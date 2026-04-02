#!/usr/bin/env python
import sys, os

if __name__ == '__main__':
    cmd = ' '.join(sys.argv[1:])
    try:
        sys.exit(os.system(cmd))
    except KeyboardInterrupt:
        sys.exit(1)
