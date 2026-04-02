#!/usr/bin/env python

CLOCKDRIVERGEN_CONFIG = {
  'target': 'lemans',
  'filter_warning': 'sw',
  'memmap_name': 'SAILSS_ADDRESS_FILE_SW',

  'generators': [{
    'type': 'dalclock',
    'output_dir': '../src/sailhyp',

    'options': {
      'env': ['SMSS'],
	  'explicit_ownership': True,
	  'include_all_freqs': ['sailss_cc_.*'],
	  'include_only_fmax': {'.*': ['nominal']},
    },
  }],
}

if __name__ == "__main__":
  import sys, os
  from subprocess import call

  if os.name == 'nt':
    clockdrivergen_path = r'\\ben\corebsp_labdata_0001\sysdrv\clockdrivergen\bin\clockdrivergen.py'
  else:
    clockdrivergen_path = r'/prj/qct/corebsp_labdata_0001/sysdrv/clockdrivergen/bin/clockdrivergen.py'

  call(['python3', clockdrivergen_path, '--cfg', __file__] + sys.argv[1:])

