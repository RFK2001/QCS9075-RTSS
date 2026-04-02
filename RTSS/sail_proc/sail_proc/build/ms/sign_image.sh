#! /bin/bash

#Get the path for Centralized sectools
#SECTOOLS=$(python -B ${BUILD_MS_ROOT}/scripts/build_sail_sec.py)
#Sign the Image 
if [[ -f ${SECTOOLS} ]]; then
  	echo "SECTOOLS found ${SECTOOLS}"
    ${SECTOOLS}  secure-image ${BUILD_MS_ROOT}/bin/${BUILD_FLAVOUR}/DEBUG/$3/$1.elf --outfile ${BUILD_MS_ROOT}/bin/${BUILD_FLAVOUR}/DEBUG/$3/signed/$1.elf --image-id $2 --security-profile ${BUILD_MS_ROOT}/../../BSP/security/security_profile/$3/sail_security_profile.xml --sign --signing-mode TEST
else
  	echo "Warning: SECTOOLS environment variable not set"
  	echo "Warning: sail.elf image is not signed."
	exit 1
fi
