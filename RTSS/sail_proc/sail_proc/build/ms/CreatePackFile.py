#!/usr/bin/python
import sys, argparse, os

INC_MATCH_STR = "#include "

def filelist(dir):
    filelist=[]
    for file in os.listdir(dir):
        if os.path.isfile(os.path.join(dir, file)):
            filelist.append(file)
    return filelist

def read_inc_pack(incfile,path,destfd):
    for root, dirs, files in os.walk(path):
        for dir in [os.path.join(root,d) for d in dirs]:
            for file in filelist(dir=dir):
                 if(file == incfile):
                     filename = os.path.join(dir,file)
                     with open(filename) as infile:
                         for line in infile:
                             destfd.write(line)

#filename of example text will be read SAIL.SI.1.2_rtos.txt
def readfile(srcfile,destfile,sail_proc):
    # destfile = os.path.join('..','..','..',srcfile)
    with open(destfile, 'w') as destfd:
        with open(srcfile) as infile:
            for line in infile:
                if "#define" in line:
                    continue
                elif "#undef" in line:
                    continue
                elif INC_MATCH_STR in line:
                    pack_inc_file = line.replace(INC_MATCH_STR,'')
                    pack_inc_file = pack_inc_file.replace('\n','')
                    read_inc_pack(incfile=pack_inc_file,path=sail_proc,destfd=destfd)
                    continue
                destfd.write(line)

def parse_args():
    parser = argparse.ArgumentParser(
        description='Expand pack files by removing #includes',
        usage=f'{__file__} [options]'
    )
    parser.add_argument("-f","--filename", required = True, help="Name of the pack file input")
    args, unknownargs = parser.parse_known_args()
    return args,unknownargs

def main():
    args , extraargs = parse_args()
    if os.path.isfile(args.filename):
        # file exists
        #[SAIL_ROOT\sail_proc', 'build', 'ms']
        dirs = os.path.dirname(__file__).rsplit(os.path.sep,2)
        sail_proc = dirs[-3]
        readfile(args.filename,destfile=os.path.join(os.path.dirname(sail_proc),args.filename),sail_proc=sail_proc)
    else:
        print("Pack file doesn't exists in current directory\n")

if __name__ == '__main__':
    if sys.version_info.major < 3:
        print(f"ERROR:{__file__} requires Python 3.x")
        sys.exit(1)
    
    try:
        sys.exit(main())
    except KeyboardInterrupt:
        sys.exit(1)