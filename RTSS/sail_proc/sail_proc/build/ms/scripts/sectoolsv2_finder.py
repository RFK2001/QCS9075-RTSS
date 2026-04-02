from re import search, IGNORECASE

from subprocess import check_output, CalledProcessError

import sys

 

HOSTS = [

"sundae",     # San Diego

"selma",      # Santa Clara

"titanic",    # Boulder

"blrsweng1",  # Bangalore

"swayam",     # Hyderabad

"bulk"        # Haifa

]

 

TIMEOUT = "1000"

NUM_PINGS = "3"

 

 

def get_sectools_windows_host():

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

 

 

def find(version="latest"):

    location = None

    if sys.platform.startswith("win32"):

        server = get_sectools_windows_host()

        if server is not None:

            location = "\\\\{}\\sectools\\v2\\{}\\Windows\\sectools.exe".format(server, version)

    elif sys.platform.startswith("linux"):

        location = "/pkg/sectools/v2/{}/Linux/sectools".format(version)

    else:

        raise RuntimeError("sectoolsv2_finder.py does not support {} OS.".format(sys.platform))

    return location

if __name__ == '__main__':
    print(find())
