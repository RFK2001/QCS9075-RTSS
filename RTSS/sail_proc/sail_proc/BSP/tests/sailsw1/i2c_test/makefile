.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
GPT_CFG_INC=$(SAIL_SRC_HOME)/BSP/McalCfg/Inc
I2C_INC = $(SAIL_SRC_HOME)/BSP/i2c
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
CRC_INC =  $(SAIL_SRC_HOME)/BSP/crc/public
PSAIL_INC=$(SAIL_SRC_HOME)/BSP/psail
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
PMIC_INC=$(SAIL_SRC_HOME)/BSP/pmic
WDT_INC = $(SAIL_SRC_HOME)/BSP/wdt
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep
MONITOR_INC=$(SAIL_SRC_HOME)/BSP/monitor/public
ACMU_INC=$(SAIL_SRC_HOME)/BSP/acmu/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public


SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/i2c_test/src

SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I $(PUBLIC_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) \
                -I $(I2C_INC)/public -I $(I2C_INC)/inc/8650 -I $(GPIO_INC) -I $(CRC_INC) -I $(PSAIL_INC)/inc \
                -I $(CHIPINFO_INC) -I $(PMIC_INC)/public -I $(WDT_INC)/public/sailsw1 -I $(WDT_INC)/inc/8650 \
                -I $(PMIC_INC)/inc/sailhyp -I $(SLEEP_INC)/public -I $(SLEEP_INC)/public/sailsw1 \
                -I $(SLEEP_INC)/inc -I $(MONITOR_INC) -I$(IPCC_INC)  -I $(ACMU_INC)


PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/i2c)

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
