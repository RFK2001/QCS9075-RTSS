.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
INC_DIR=$(SAIL_SRC_HOME)/BSP/psail/inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/psail/public
EFS_STORAGE_INC=$(SAIL_SRC_HOME)/BSP/efs2/api/storage
EFS_SERVICES_INC=$(SAIL_SRC_HOME)/BSP/efs2/api/services
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
I2C_INC=$(SAIL_SRC_HOME)/BSP/i2c/public
LOGGER_INC=$(SAIL_SRC_HOME)/BSP/LogCode/public
CRASHDBG_INC=$(SAIL_SRC_HOME)/BSP/crashdbg/public
MONITOR_INC=$(SAIL_SRC_HOME)/BSP/monitor/public
EFS_PORT_INC=$(SAIL_SRC_HOME)/BSP/efs2/efs_port
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio
EL_ENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1/
EL_ENTRY_PUBLIC=$(SAIL_SRC_HOME)/BSP/el_entry/public
FUSA_INC=$(SAIL_SRC_HOME)/BSP/fusa/public
PMIC_INC=$(SAIL_SRC_HOME)/BSP/pmic/public
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd
SPINOR_PUBLIC=$(SAIL_SRC_HOME)/BSP/spinor/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/psail/src
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s

INC  = -I $(CMNINC) \
           -I $(PUBLIC_INC) -I $(IPCC_INC) \
           -I $(CMNINC)/8650 \
           -I $(SAFERTOS_INC) \
           -I $(INC_SAIL_SAFERTOS) \
           -I $(I2C_INC)\
           -I $(MONITOR_INC) \
           -I $(GPIO_INC)/public \
           -I $(GPIO_INC)/inc/8650 \
           -I $(INC_DIR)\
           -I $(INC_DIR)/8650 \
           -I $(EFS_STORAGE_INC)\
           -I $(EFS_SERVICES_INC)\
           -I $(EFS_PORT_INC) \
           -I $(FUSA_INC)\
           -I $(ISD_INC)/inc/8650\
           -I $(ISD_INC)/public\
           -I $(BUSYWAIT_INC)\
           -I $(CHIPINFO_INC)\
           -I $(ISD_INC)/public/sailsw1 \
		   -I $(EL_ENTRY_INC) \
		   -I $(EL_ENTRY_PUBLIC) \
           -I $(SPINOR_PUBLIC)/sailsw1 \
           -I $(SPINOR_PUBLIC)\
           -I $(SLEEP_INC)/inc/8650 \
           -I $(SLEEP_INC)/public\
           -I $(SLEEP_INC)/public/sailsw1 \
           -I $(PMIC_INC) \
           -I $(CRASHDBG_INC) \
           -I $(LOGGER_INC) \

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/psail)

all: setup
	@if [ "$(TAG)" != "sailhyp" ] ;then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC_SAIL_FREERTOS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi

clean:
	rm -fr ./aarch32/DEBUG/$(TAG)/*.o
	rm -fr ./aarch32/RELEASE/$(TAG)/*.o

print-%: setup
	@echo $* = $($*)

setup: 
 ifneq ($(ARM_TOOL_VARIANT),ult)
  $(Error! Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
 endif
