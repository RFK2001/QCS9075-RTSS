#!/usr/bin/python
import os , shutil
from socket import gethostname
from time import localtime, strftime
from re import search, IGNORECASE
from subprocess import check_output, CalledProcessError , call
from xml.etree import ElementTree as et
import sys

#ARM License servers
HOSTS = [

"license-vm-1-hyd",     #Hyderabad

"license-wan-20-sd-prd.qualcomm.com",

"license-wan-arm",

#Add all the known servers in this list

]
LICENSE_SERVER_PORT = 7117
DEFAULT_ARM_LICENSE_SERVER = "license-wan-arm"

TIMEOUT = "1000"
NUM_PINGS = "3"

BATCH_FILE = f"settmp.bat"
ARM_TOOL_VARIANT    = f"ult"
BUILD_PRODUCTS_FILENAME = "BuildProducts.txt"

def update_version_file():
    hostname = gethostname()
    basename = os.path.basename(SAIL_ROOT)
    MANIFEST_XML_FILE=os.path.join(SAIL_ROOT,'sail_proc','build','manifest.xml')
    
    # get the current date and time
    now = strftime("%a %d %b %Y %H:%M:%S +0530", localtime())
    VERSION_FILE = os.path.join(SAIL_ROOT,'sail_proc','BSP','el_entry','public','sailhyp','version.h')
    
    f = open(VERSION_FILE, "w")
    
    if not os.path.exists(MANIFEST_XML_FILE):
        f.close()
        return 1
    else:
        # Get XML data
        XmlCfg = et.ElementTree(file=MANIFEST_XML_FILE).getroot()
        XmlImageTree = XmlCfg.find('image_tree')
        
        if XmlImageTree is not None:
            XmlImageTreeBuildId = XmlImageTree.find('build_id')
           
        if XmlImageTreeBuildId is not None: 
            build_id = XmlImageTreeBuildId.text.strip()
           
        f.write(
            f"""#define SAIL_IMAGE_VERSION "{build_id}"\
            """
        )
        
        f.write(
            f"""\n#define SAIL_WSPACE_INFO "{basename}"\n#define HOSTNAME "{hostname}"\n#define DATE "{now}"\
            """
        )
        
    f.close()
    return 0

def get_win_path(cyg_path):
    return check_output(["cygpath", "-wm", cyg_path]).strip(b"\n").decode()


def get_faster_host():
    selected_host = None
    min_ping_time = None
    for host in HOSTS:
        try:
            # This ping command only works on Windows because the ping command requires different arguments on Linux and macOS
            output = check_output(["ping", "-n", NUM_PINGS, "-w", TIMEOUT, host])
            match = search("Average[ ]*=[ ]*([0-9][0-9]*)", output.decode(), IGNORECASE)
            if match:
                ping_time = int(match.group(1))
                if min_ping_time is None or ping_time < min_ping_time:
                    min_ping_time = ping_time
                    selected_host = host
        except CalledProcessError:
            pass
    return selected_host

def find_license_server(default=DEFAULT_ARM_LICENSE_SERVER):
    location = "{}@{}".format(LICENSE_SERVER_PORT,default)
    server = get_faster_host()
    if server is not None:
        location = "{}@{}".format(LICENSE_SERVER_PORT,server)
    return location

if __name__ == '__main__':
    #[SAIL_ROOT, 'sail_proc', 'build', 'ms']
    dirs = os.path.dirname(__file__).rsplit(os.path.sep,3)
    
    #SAIL_ROOT
    SAIL_ROOT = dirs[-4]
    update_version_status = update_version_file()
    if update_version_status == 1:
        sys.exit(1)
    
    ARMLMD_LICENSE_FILE = find_license_server()

    env_dict = {
        'ARMLMD_LICENSE_FILE':f"{ARMLMD_LICENSE_FILE}",
        'ARM_TOOL_VARIANT':f"{ARM_TOOL_VARIANT}",
    }

    try:
        COMPILER_PATH
    except NameError:
        if os.name == 'nt':
            COMPILER_PATH = os.path.join(SAIL_ROOT,'sail_proc','toolchain','6.16.2_win','bin')
        else:
            COMPILER_PATH = os.path.join(SAIL_ROOT,'sail_proc','toolchain','6.16.2_fusa','bin')

    try:
        ARM_PRODUCT_DEF
    except NameError:
        elmap = os.path.join(COMPILER_PATH,'..','platinum.elmap')
    
    SAIL_SRC_HOME = os.path.join(SAIL_ROOT,'sail_proc')
    BUILD_MS_ROOT = os.path.join(SAIL_ROOT,'sail_proc','build','ms')
    # mode
    mode = 0o777
    
    if not os.path.exists(os.path.join(BUILD_MS_ROOT,'bin')):
        os.mkdir(os.path.join(BUILD_MS_ROOT,'bin'), mode)
    
    for root, dir, file in os.walk(COMPILER_PATH):
        os.chmod(root, mode)
    #chmod -R +x $COMPILER_PATH
    shutil.copyfile(os.path.join(SAIL_ROOT,'sail_proc','build','copy_scripts','makefile'),os.path.join(SAIL_ROOT,'sail_proc','BSP','makefile'))
    os.chmod(os.path.join(SAIL_ROOT,'sail_proc','BSP','makefile'), mode)
    shutil.copyfile(os.path.join(SAIL_ROOT,'sail_proc','build','copy_scripts','makefile_FreeRTOS'),os.path.join(SAIL_ROOT,'sail_proc','FreeRTOS','makefile'))
    os.chmod(os.path.join(SAIL_ROOT,'sail_proc','FreeRTOS','makefile'), mode)
    
    SECTOOLS = check_output(["python", os.path.join(BUILD_MS_ROOT, 'scripts', 'sectoolsv2_finder.py')]).strip(b"\n").decode()

    if os.name == 'nt':
        COMPILER_PATH = get_win_path(COMPILER_PATH)
        SAIL_SRC_HOME = get_win_path(SAIL_SRC_HOME)
        BUILD_MS_ROOT = get_win_path(BUILD_MS_ROOT)
        ARM_PRODUCT_DEF = get_win_path(elmap)
        SECTOOLS = get_win_path(SECTOOLS)

        env_dict['COMPILER_PATH'] = f'{COMPILER_PATH}'
        env_dict['SAIL_SRC_HOME'] = f'{SAIL_SRC_HOME}'
        env_dict['BUILD_MS_ROOT'] = f'{BUILD_MS_ROOT}'
        env_dict['ARM_PRODUCT_DEF'] = f'{ARM_PRODUCT_DEF}'
        env_dict['SECTOOLS'] = f'{SECTOOLS}'
        
        fp = open(BATCH_FILE, "w")
        for key in env_dict:
            fp.write(f"set {key}={env_dict[key]}\n")
        fp.close()
                
        sys.exit(0)