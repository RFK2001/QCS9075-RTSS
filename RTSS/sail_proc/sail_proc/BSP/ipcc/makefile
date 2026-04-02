.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/ipcc/inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
EL_ENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
BUSYWAIT_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/time/public
SAILHEAP=$(SAIL_SRC_HOME)/BSP/sailheap/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/ipcc/src

SRC_C=$(SOURCE_DIR)/*.c  $(SOURCE_DIR)/sail/*.c $(SOURCE_DIR)/sail/8650/*.c  $(SOURCE_DIR)/sail/sailhyp/*.c 

SRC_EL1_C=$(SOURCE_DIR)/*.c  $(SOURCE_DIR)/sail/*.c $(SOURCE_DIR)/sail/8650/*.c  $(SOURCE_DIR)/sail/sailsw1/*.c 

SRC_S=$(SOURCE_DIR)/*.S

INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(PUBLIC_INC) -I $(EL_ENTRY_INC) -I $(EL_ENTRY_INC)/sailhyp -I $(INTERRUPTS_INC)/sailhyp -I $(SAILHEAP) -I $(BUSYWAIT_PUBLIC_INC)

INC_EL1  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(PUBLIC_INC) -I $(EL_ENTRY_INC) -I $(EL_ENTRY_INC)/sailsw1 -I $(INTERRUPTS_INC)/sailsw1 -I $(SAILHEAP) -I $(BUSYWAIT_PUBLIC_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/ipcc)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		$(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS); \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		$(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS); \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC) $(INC_SAIL_FREERTOS);\
		$(CC) $(TARGET_OPTS) $(INC_EL1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS); \
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
