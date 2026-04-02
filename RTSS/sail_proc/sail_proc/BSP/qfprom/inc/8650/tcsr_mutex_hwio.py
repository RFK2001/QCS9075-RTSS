#!/usr/bin/env python

HWIO_REGISTER_FILES = [
    {
        'exclude-reserved': True,
        'filename': 'tcsr_mutex_hwio.h',
        'header': '#include "msmhwiobase.h"',
        'modules': ['SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX'],
        "module-filter-include": {
            "SAIL_TO_MD_TCSR_TCSR_TCSR_MUTEX": [
                "SAIL_TO_MD_TCSR_MUTEX_REG_n"
            ]
        },
        "integer-qualifiers": True
    },
]


if __name__ == "__main__":
    import sys
    from hwio.scripts.hwio_gen import hwio_gen
    sys.argv.append('--chip=lemansau_1.0')
    sys.argv.append('--memory-map=SAILSS_ADDRESS_FILE_SW')
    hwio_gen()