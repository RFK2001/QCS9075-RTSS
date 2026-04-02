.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/gpio_test/src
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
GPIO_INC_HWIO=$(SAIL_SRC_HOME)/BSP/gpio/inc/8650
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public


SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I $(PUBLIC_INC) -I$(IPCC_INC)  -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(GPIO_INC) -I $(GPIO_INC_HWIO)

PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/gpio)

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
