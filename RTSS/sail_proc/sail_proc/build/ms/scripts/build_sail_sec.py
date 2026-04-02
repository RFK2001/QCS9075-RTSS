import os

import sys

 
try:
    sectoolsv2_finder = "scripts/sectoolsv2_finder.py" # TODO: Configure path to sectoolsv2_finder.py

    sys.path.append(os.path.abspath(sectoolsv2_finder))

    sectools = os.environ.get("SECTOOLS")

    if sectools:

        if not os.path.isfile(sectools):

            raise RuntimeError("Can't find Sectools at SECTOOLS:'{}'".format(sectools))

    elif os.path.isfile(sectoolsv2_finder):

        import sectoolsv2_finder

        sectools = sectoolsv2_finder.find()  # Specific Sectools version can be specified via "version" parameter

        if sectools is None or not os.path.isfile(sectools):

            raise RuntimeError("Can't find Sectools internally at: '{}'".format(sectools))

    else:

        raise RuntimeError("SECTOOLS environment variable is not set")

    sectools = os.path.abspath(sectools)
    os.environ["SECTOOLS_DIR"] = str(sectools)

except RuntimeError:
    print " "

else:
    print  os.environ.get('SECTOOLS_DIR')

