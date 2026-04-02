#!/usr/bin/env python
chipset = '8650'

HWIO_REGISTER_FILES = [
    {
        'exclude-reserved': True,
        'filename': f'../../../common_inc/{chipset}/sail_security_csr_hwio_{chipset}.h',
        'header': '#include "msmhwiobase.h"',
        'modules': ['SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_CORE'],
        "module-filter-exclude": {
            "SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_CORE": [
                "SAILSS_SECURITY_CONTROL_QFPROM_RAW.*"
            ]
        },
        "output-offsets": True,
        "integer-qualifiers": True
    },
    {
        'exclude-reserved': True,
        'filename': 'security_control_hwioreg.h',
        'header': '#include "msmhwiobase.h"',
        'modules': ['SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_CORE'],
        "output-offsets": True,
        "integer-qualifiers": True
    },
]


if __name__ == "__main__":
    import sys
    from hwio.scripts.hwio_gen import hwio_gen
    sys.argv.append('--chip=lemansau_1.0')
    sys.argv.append('--memory-map=SAIL_SECURITY_CONTROL')
    hwio_gen()

