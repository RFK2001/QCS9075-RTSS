

# additional variables that affects the build

# mandatory
# SECTOOLS : define the path to sectools

# optional
# TARGET_SOC : lemans, monaco
# DTBO : path to common EL2 and El1 DTB overlay binary file

declare -A serverlist

serverlist["bangalore"]=7117@license-vm-1-hyd:7117@license-hyd1:7117@license-hyd2:7117@license-wan-hyd
serverlist["beijing"]=8224@license-chn1:8224@license-chn2
serverlist["boulder"]=8224@REDCLOUD
serverlist["encnaa"]=8224@license-wan-rtp1
serverlist["farnborough"]=8224@license-wan-frn3
serverlist["haifa"]=8224@license-wan-frn1
serverlist["hyderabad"]=7117@license-vm-1-hyd:7117@license-hyd1:7117@license-hyd2:7117@license-wan-hyd
serverlist["korea"]=8224@license-kor1
serverlist["markham"]=8224@license-wan-yyz1
serverlist["sandiego"]=7117@license-wan-arm:7117@license-wan-arm1:7117@license-wan-20-sd-prd.qualcomm.com
serverlist["santaclara"]=8224@license-wan-scl1

#default license server lists if host site is not present
serverlist["default"]=${serverlist["sandiego"]}:${serverlist["hyderabad"]}

export SAIL_ROOT=$(pwd)
export MANIFEST_XML_FILE_PATH=$SAIL_ROOT/sail_proc/build
if [ -e $MANIFEST_XML_FILE_PATH/manifest.xml ]
then
    SAIL_CRM_FROM_XML=($(grep -oP '(?<=build_id>)[^<]+' "$MANIFEST_XML_FILE_PATH/manifest.xml"))
else
    echo "Environment Setup Incomplete -> Cannot find manifest file at $MANIFEST_XML_FILE_PATH"
	return
fi
echo -e "#"define SAIL_IMAGE_VERSION "\"${SAIL_CRM_FROM_XML}"\" '\n'\
"#"define SAIL_WSPACE_INFO "\""$(basename "$(dirname "$PWD")")""/""${PWD##*/}""\" > $SAIL_ROOT/sail_proc/BSP/el_entry/public/sailhyp/version.h
echo "#"define HOSTNAME "\"${HOSTNAME}"\" >> $SAIL_ROOT/sail_proc/BSP/el_entry/public/sailhyp/version.h
echo "#"define DATE "\"$(date)"\" >> $SAIL_ROOT/sail_proc/BSP/el_entry/public/sailhyp/version.h


USAGE="valid command option < arm_gnu | arm_fusa >"
export TOOLCHAIN=${1:-arm_gnu}

for arg; do
  case "$arg" in
    --help|-h)                echo $USAGE; return;;
      arm_gnu)                export TOOLCHAIN=arm_gnu;;
      arm_fusa)               export TOOLCHAIN=arm_fusa;;
    *)                        echo -e "unknown option $arg\n$USAGE" >&2; return;;
  esac
done

# Setup Toolchain ( ARM FuSa / ARM GNU [GCC] )

if [ "$1" == "arm_gnu" ]; then

  if [ -z "${COMPILER_PATH}" ]; then
    export COMPILER_PATH=$SAIL_ROOT/sail_proc/toolchain/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi/bin
  fi

  if [ ! -x "${COMPILER_PATH}/arm-none-eabi-gcc" ]; then
    echo "Missing ARM GNU (GCC) Compiler in PATH: ${COMPILER_PATH}"

    export COMPILER_PATH=$SAIL_ROOT/sail_proc/toolchain/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi/bin

    echo "Switching to fallback Compiler PATH: ${COMPILER_PATH}"
  fi

  echo "Toolchain Selected ARM GNU"

elif [ "$1" == "arm_fusa" ]; then

  if [ -z "${ARMLMD_LICENSE_FILE}" ]; then
    hostsite=$(mdb $HOSTNAME return site)

    hostsite=${hostsite/*: /}               # Remove everything up to and including : sign
    hostsite=${hostsite/\-*/}               # Remove - and everything after it
    hostsite=${hostsite//[[:blank:]]/}      # Remove whitespaces
    hostsite=${hostsite//[$'\t\r\n ']}      # Remove \t\r\n

    license_server_set=false

    for key in ${!serverlist[@]}; do
      if [[ "$hostsite" == "${key}" ]];then
          export ARMLMD_LICENSE_FILE=${serverlist[${key}]}
          license_server_set=true
      fi
    done
    
    if [ "$license_server_set" = false ]; then
      export ARMLMD_LICENSE_FILE=${serverlist["default"]}
    fi
  fi

  if [ -z "${ARM_TOOL_VARIANT}" ]; then
    export ARM_TOOL_VARIANT=ult
  fi

  if [ -z "${COMPILER_PATH}" ]; then
    export COMPILER_PATH=$SAIL_ROOT/sail_proc/toolchain/6.16.2_fusa/bin
  fi

  if [ -z "${ARM_PRODUCT_DEF}" ]; then
    export ARM_PRODUCT_DEF=${COMPILER_PATH}/../platinum.elmap
  fi

  if [ ! -x "${COMPILER_PATH}/armclang" ]; then
    echo "Missing ARM FuSa Compiler in PATH: ${COMPILER_PATH}"

    export COMPILER_PATH=$SAIL_ROOT/sail_proc/toolchain/6.16.2_fusa/bin
    export ARM_PRODUCT_DEF=${COMPILER_PATH}/../platinum.elmap

    echo "Switching to fallback Compiler PATH: ${COMPILER_PATH}"
  fi

  echo "Toolchain Selected ARM FuSa 6.16.2"

else
  if [ -z "${COMPILER_PATH}" ]; then
    export COMPILER_PATH=$SAIL_ROOT/sail_proc/toolchain/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi/bin
  fi

  if [ ! -x "${COMPILER_PATH}/arm-none-eabi-gcc" ]; then
    echo "Missing ARM GNU (GCC) Compiler in PATH: ${COMPILER_PATH}"

    export COMPILER_PATH=$SAIL_ROOT/sail_proc/toolchain/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi/bin

    echo "Switching to fallback Compiler PATH: ${COMPILER_PATH}"
  fi

  echo "Toolchain Selected ARM GNU"
fi

export PATH=/pkg/qct/software/boottools:$PATH

export SAIL_SRC_HOME=$SAIL_ROOT/sail_proc
export BUILD_MS_ROOT=$SAIL_ROOT/sail_proc/build/ms
mkdir -p -m 777 $BUILD_MS_ROOT/bin
cd $SAIL_ROOT/sail_proc/build/ms
chmod -R +x $COMPILER_PATH

cp $SAIL_ROOT/sail_proc/build/copy_scripts/makefile $SAIL_ROOT/sail_proc/BSP/.
chmod u+w $SAIL_ROOT/sail_proc/BSP/makefile

cp $SAIL_ROOT/sail_proc/build/copy_scripts/makefile_FreeRTOS $SAIL_ROOT/sail_proc/FreeRTOS/makefile

chmod u+w $SAIL_ROOT/sail_proc/FreeRTOS/makefile

# Generate Toplevel packfile from component pack files
if [ -f "${BUILD_MS_ROOT}/SAIL.SI.1.2_rtos.txt" ]; then
filepp -I${SAIL_SRC_HOME}/FreeRTOS/ -I${SAIL_SRC_HOME}/build/ -I${SAIL_SRC_HOME}/BSP/  ${BUILD_MS_ROOT}/SAIL.SI.1.2_rtos.txt > ../../../SAIL.SI.1.2_rtos.txt
echo "Generated Pack file for Freertos"
fi

echo "Environment Setup Completed -> Run Make"
