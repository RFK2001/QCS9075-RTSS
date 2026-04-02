##############################################################
# Copyright (c) 2022-2025 Qualcomm Technologies, Inc.
# All Rights Reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
##############################################################



##############################################################
 #                   Importing modules
##############################################################
import sys
import AlpacaServer
import sys
import time
import serial
import getopt
import webbrowser
import requests
import sys

SCRIPT_VERSION = '0.3'
GITHUB_URL = 'https://github.qualcomm.com/ohkeunow/alpaca_onoff_test'
RELEASE_URL = GITHUB_URL + '/releases'

ERROR_CONTINUE = 0
ERROR_STOP = 1

##############################################################
 #                   Defining Helper functions
##############################################################

def check_version():
    r = requests.get(RELEASE_URL + '/latest')
    try:
        if r.url != '%s/tag/%s' % (RELEASE_URL, SCRIPT_VERSION):
            print('updated script found at github repository.. refusing to run..')
            webbrowser.open(RELEASE_URL)
            return False
    except Exception as e:
        return True
    return True


def open_port(port_name):
    ser = serial.Serial(port=port_name,
                        baudrate=115200,
                        parity=serial.PARITY_NONE,
                        stopbits=serial.STOPBITS_ONE,
                        bytesize=serial.EIGHTBITS)
    ser.set_buffer_size(rx_size=2*1024*1024)    #set buffer size to be 2MB, is this enough?
    return ser


def read_port(ser):
    ret_bytes = b''
    while ser.inWaiting() > 0:
        ret_bytes += ser.read(ser.inWaiting())
    return ret_bytes


def log(log_string, log_file):
    print(log_string)
    if log_file:
        log_file.write(log_string)
        log_file.write('\n')
        log_file.flush()

def get_time(expect_tuple):
    return expect_tuple[1]      # return the time delay element

def print_usage():
    print('''Usage : python3 turnonoff_v2.py 
                            --alpaca=com3                   : COM port for ALPACA control
                            --comports=com4,com5,com6,com7  : COM port list to monitor
                            --log=c:\\temp\\sometest        : prefix for logfile''')

# Search address in symbol table and return symbol name if search succeds else -1
def binary_search(symtab, addr):

    low = 0
    high = len(symtab) - 1
    mid = 0
 
    while low <= high:
 
        mid = (high + low) // 2
 
        # If addr is greater, ignore left half
        if int(symtab[mid][2],16) < addr:
            low = mid + 1
 
        # If addr is smaller, ignore right half
        elif int(symtab[mid][1],16) >= addr:
            high = mid - 1
 
        # means addr is present at mid
        else:
            return symtab[mid][0]
 
    # If we reach here, then the address is not found in symbol table
    return -1

#Reads the log file and returns the printed function addresses
def read_log_file(log_file):

    search_addrs = list()

    with open(log_file) as file:
        # Skips text before the beginning of the symbol table:

        for line in file:

            if 'Stack unwind begins' in line.strip():  # Starting of symbol table
                break
        # Reads text until the end of the symbol table:

        for line in file:  # This keeps reading the file
            line = line.strip()

            if not line:continue

            if 'Stack unwind ends' in line: #End of symbol table
                break

            for word in line.split():
                if word.startswith('='):
                    search_addrs.append(word[1:])

    
    return search_addrs

#Reads the map file and extract the symbol table out of it
def form_symtab(map_file):

    mapfile_content = list()

    with open(map_file) as file:
        # Skips text before the beginning of the symbol table:

        for line in file:
            if 'Symbol Name' in line.strip():  # Starting of symbol table
                break
        # Reads text until the end of the symbol table:

        for line in file:  # This keeps reading the file
            line = line.strip()
            if '=====' in line: #End of symbol table
                break
            if line:
                mapfile_content.append(line)

    symtab = list()

    for line in mapfile_content:
        line = line.split()
        
        if len(line) >= 5 and line[2] == 'Thumb':
            
            symtab.append([line[0],line[1],hex(int(line[1],16) + int(line[4]))])

    symtab.sort(key =lambda x:x[1])

    return symtab

##############################################################
 #                   Name : run_alpaca
 #                   Args: 1) Alpaca port 
 #                         2) UART port
 #                         3) Log file prefix
 #                   Func: Generates Log File
 #                   Return : None
##############################################################

def run_alpaca(alpaca_com='com3', console_com='com7', log_prefix='log'):

    # prepare ALPACA connection
    aserver = AlpacaServer.openAlpacaTAC()
    twindow = AlpacaServer.createTacServer(aserver)
    if not twindow.OpenByName(alpaca_com):
        print('cannot open ALPACA port %s' % alpaca_com)
        return
    twindow.Set_Visible(True)

    log_file = None
    if log_prefix:
        log_file = open('%s_output.log' % log_prefix, 'w', encoding='latin-1')

    log('turning off the target', log_file)
    twindow.PowerOffButton()
    time.sleep(3)

    # open the port and prepare log files
    
    log('opening port: ' + console_com, log_file)
    com_handle = open_port(console_com)
    read_bytes = read_port(com_handle)
    
    twindow.PowerOnButton()
    time.sleep(7)
    
    read_bytes = read_port(com_handle)
    
    file = open('%s.log' % log_prefix,'w' ,encoding='latin-1')
    file.write(read_bytes.decode('latin-1', errors='ignore'))
    file.close()

    twindow.PowerOffButton()
    time.sleep(3)

#Takes symbol table and search address as argument and return the symbol name

##############################################################
 #                   Name : stack_unwind
 #                   Args: 1) Map file 
 #                         2) Log file prefix
 #                         
 #                   Func: Prints unwinded function symbols
 #                   Return : None
##############################################################
def stack_unwind(map_file ,log_prefix='log'):

    symtab = form_symtab(map_file)
    log_file = '%s.log' % log_prefix
    search_addr = read_log_file(log_file)

    print("Stack unwind begins ..")
    for addr in search_addr:

        symname = binary_search(symtab,int(addr,16))
        if symname == -1:print("(",addr,")","Address not found in symbol table",sep='',end='\n')

        else :print("(",addr,")",symname,sep='',end='\n')

    print("Stack unwind ends ..")

##############################################################
 #                   Name : Main function

##############################################################

if __name__=="__main__":

    if not check_version():
        sys.exit(3)

    try:
        opts, args = getopt.getopt(sys.argv[1:], 'a:c:x:e:l:m:',
                                   ['alpaca=', 'comports=', 'expect=', 'error=', 'log=', 'mapfile='])
    except getopt.GetoptError as e:
        print_usage()
        sys.exit(2)

    alpaca_port = None
    com_port = None
    log_prefix = None
    map_file = None

    for opt, arg in opts:
        if opt in ('-a', '--alpaca'):
            alpaca_port = arg
        elif opt in ('-c', '--comports'):
            com_port = arg
        elif opt in ('-l', '--log'):
            log_prefix = arg
        elif opt in ('-m', '--mapfile'):
            map_file = arg
    
    if (alpaca_port is None) or (com_port is None) or (map_file is None):
        print_usage()
        sys.exit(2)
    
    run_alpaca(alpaca_com=alpaca_port,
               console_com=com_port,
               log_prefix=log_prefix)

    stack_unwind(map_file ,log_prefix)
    