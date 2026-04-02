#!/usr/bin/python3

import sys
import xml.etree.ElementTree as ET


def get_ox(cfg_file, module_path):
    tree = ET.parse(cfg_file)
    root = tree.getroot()

    ret = ''
    for dir in root:
        path = dir.attrib['path']
        if module_path.endswith(path):
            for sw_name in ('sailjtagprogrammer','sailhyp', 'sailsw1', 'sailsw2', 'sailsw3', 'sailsw4'):
                found = False
                for component in dir:
                    if component.attrib['sw'] == sw_name:
                        found = True

                if found:
                    ret += sw_name + ','

    return ret


if __name__ == '__main__':

    if len(sys.argv) != 3:
        sys.exit(-1)
    cfg_file = sys.argv[1]
    module_path = sys.argv[2]

    ox = get_ox(cfg_file, module_path)

    print(ox)
