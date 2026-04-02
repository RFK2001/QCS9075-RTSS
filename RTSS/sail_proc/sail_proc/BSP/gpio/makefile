.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/gpio/inc
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/gpio/src
INTERRUPT_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep
SRC_C=$(SOURCE_DIR)/*.c $(SOURCE_DIR)/sailhyp/*.c
SRC_EL1_C=$(SOURCE_DIR)/*.c $(SOURCE_DIR)/sailsw1/*.c
SRC_S=$(SOURCE_DIR)/*.s

INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR)/sailhyp -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(INTERRUPT_INC)/sailhyp -I $(CHIPINFO_INC)

INC_EL1  = -I $(CMNINC) -I$(IPCC_INC) -I $(CMNINC)/8650 -I $(INC_DIR)/sailsw1 -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(INTERRUPT_INC)/sailsw1 -I $(CHIPINFO_INC) -I $(SLEEP_INC)/public -I $(SLEEP_INC)/public/sailsw1 
PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/gpio)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC) $(INC_SAIL_SAFERTOS);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
