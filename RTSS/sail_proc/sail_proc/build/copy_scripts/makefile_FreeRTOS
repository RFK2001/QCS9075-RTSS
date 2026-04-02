.PHONY: clean all print setup

FREERTOS_OSAL_INC=$(SAIL_SRC_HOME)/FreeRTOS/osal
FREERTOS_CONFIG_INC=$(SAIL_SRC_HOME)/FreeRTOS/config
FREERTOS_KERNEL_INC=$(SAIL_SRC_HOME)/FreeRTOS/kernel
FREERTOS_PORTABLE_INC=$(SAIL_SRC_HOME)/FreeRTOS/portable

SOURCE_FREERTOS_OSAL_DIR=$(SAIL_SRC_HOME)/FreeRTOS/osal
SOURCE_FREERTOS_KERNEL_DIR=$(SAIL_SRC_HOME)/FreeRTOS/kernel
SOURCE_FREERTOS_PORTABLE_DIR=$(SAIL_SRC_HOME)/FreeRTOS/portable

SRC_FREERTOS_OSAL_C=$(SOURCE_FREERTOS_OSAL_DIR)/*.c
SRC_FREERTOS_KERNEL_C=$(SOURCE_FREERTOS_KERNEL_DIR)/*.c
SRC_FREERTOS_PORTABLE_C=$(SOURCE_FREERTOS_PORTABLE_DIR)/*.c
SRC_FREERTOS_PORTABLE_S=$(SOURCE_FREERTOS_PORTABLE_DIR)/*.s

SRC_FREERTOS = $(SRC_FREERTOS_KERNEL_C) $(SRC_FREERTOS_PORTABLE_C) $(SRC_FREERTOS_OSAL_C)

IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
COMMON_INC=$(SAIL_SRC_HOME)/BSP/common_inc
COMMON_INC_8650=$(SAIL_SRC_HOME)/BSP/common_inc/8650
STARTUP_INC=$(SAIL_SRC_HOME)/BSP/startup/inc/sailsw1
SAIL_BOOTCFG=$(SAIL_SRC_HOME)/BSP/sail_bootcfg/public

INC = -I $(FREERTOS_OSAL_INC)/public/                     \
      -I $(FREERTOS_CONFIG_INC)                           \
      -I $(FREERTOS_KERNEL_INC)/include/                  \
      -I $(FREERTOS_PORTABLE_INC)                         \
      -I $(IPCC_INC)/                                     \
      -I $(COMMON_INC)/                                   \
      -I $(COMMON_INC_8650)/                              \
      -I $(STARTUP_INC)/                                  \
      -I $(SAIL_BOOTCFG)/								  \

all: setup
	@if [ "$(TAG)" != "sailhyp"  ]; then\
		echo $(INC) ;\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_FREERTOS) $(CC_ASM_OPTS) $(SRC_FREERTOS_PORTABLE_S) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(TAG) ;\
		mv *.o ./aarch32/$(TAG)/ ;\
	fi
clean:
	rm -fr ./aarch32/$(TAG)/*.o
print-%: setup
	@echo $* = $($*)

setup: 
 ifneq ($(ARM_TOOL_VARIANT),ult)
	$(Error! Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
 endif