.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/isd_test/src
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/inc
ISD_INC_PUBLIC=$(SAIL_SRC_HOME)/BSP/isd/public/sailsw1
ELENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
LOGCODE_INC=$(SAIL_SRC_HOME)/BSP/LogCode/public
ISD_INC_HYP=$(SAIL_SRC_HOME)/BSP/isd/inc/sailhyp
ISD_INC_SW1=$(SAIL_SRC_HOME)/BSP/isd/inc/sailsw1
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/inc
IPCC_PUBLIC=$(SAIL_SRC_HOME)/BSP/ipcc/public
TESTAPP_INC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/isd_test/inc
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public


SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =   -I $(PUBLIC_INC)/sailsw1 -I$(IPCC_INC)  -I $(PUBLIC_INC) -I $(TESTAPP_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(ISD_INC) -I $(ISD_INC_PUBLIC) -I $(ELENTRY_INC)/sailsw1 -I $(ELENTRY_INC)  -I $(LOGCODE_INC) -I $(ISD_INC_HYP) -I $(ISD_INC_SW1) -I $(IPCC_INC) -I $(IPCC_PUBLIC)

PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/isd)

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
