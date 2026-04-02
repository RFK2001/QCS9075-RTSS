.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
OSPINOR_CMN = $(SAIL_SRC_HOME)/BSP/spinor/public
I2C_INC = $(SAIL_SRC_HOME)/BSP/i2c
PSAIL_INC=$(SAIL_SRC_HOME)/BSP/psail
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public

SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/psail_test/src
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I $(PUBLIC_INC) -I$(IPCC_INC)  -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(OSPINOR_CMN) -I $(OSPINOR_CMN)/sailsw1 -I $(I2C_INC)/public -I $(I2C_INC)/inc/8650 -I $(PSAIL_INC)/inc -I $(CHIPINFO_INC)

PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/psail)

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
