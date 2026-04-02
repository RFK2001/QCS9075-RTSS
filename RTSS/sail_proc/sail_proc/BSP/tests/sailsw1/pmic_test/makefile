.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
MONITORINTR_INC = $(SAIL_SRC_HOME)/BSP/monitor/public
PMIC_INC=$(SAIL_SRC_HOME)/BSP/pmic
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SYSCALL_SW1_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1
OSPINOR_CMN = $(SAIL_SRC_HOME)/BSP/spinor/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
LOGCODE_INC = $(SAIL_SRC_HOME)/BSP/LogCode/public
I2C_INC = $(SAIL_SRC_HOME)/BSP/i2c
WDT_INC = $(SAIL_SRC_HOME)/BSP/wdt
DISPATCHER_INC = $(SAIL_SRC_HOME)/BSP/dispatcher/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/pmic_test/src
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public

SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I$(IPCC_INC)  -I $(PUBLIC_INC)  -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(MONITORINTR_INC) -I $(PMIC_INC)/inc/sailhyp/8650 -I $(PMIC_INC)/inc/sailhyp -I $(PMIC_INC)/public -I $(PMIC_INC)/inc/sailsw1 -I $(SYSCALL_PUB_INC) -I $(SYSCALL_SW1_INC) -I $(OSPINOR_CMN) -I $(OSPINOR_CMN)/sailsw1 -I $(CHIPINFO_INC) -I $(LOGCODE_INC) -I $(I2C_INC)/public -I $(I2C_INC)/inc/8650 -I $(WDT_INC)/public/sailsw1 -I $(WDT_INC)/inc/8650 -I $(DISPATCHER_INC)

PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/pmic)

all: setup
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && [ "$(TAG)" != "autosarsailbaremetal" ]&& echo $(PLACEMENT_TEMP) | grep -q $(TAG); then \
		echo $(SAILSW1_INC) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(SAILSW1_INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS)) || exit $$?; \
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
