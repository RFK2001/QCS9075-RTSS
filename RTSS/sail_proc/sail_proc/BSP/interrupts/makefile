.PHONY: clean all print setup

ASM_OPTS=-xassembler-with-cpp
CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/interrupts/inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
EL_ENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/interrupts/src
SRC_HYP_C=$(SOURCE_DIR)/sailhyp/*.c
SRC_HYP_S=$(SOURCE_DIR)/sailhyp/*.S
SRC_EL1_C=$(SOURCE_DIR)/sailsw1/*.c
SRC_EL1_S=$(SOURCE_DIR)/sailsw1/*.S 
INC_HYP  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR)  -I $(INC_DIR)/8650 -I $(PUBLIC_INC)/sailhyp -I $(EL_ENTRY_INC) -I $(EL_ENTRY_INC)/sailhyp/ -I $(IPCC_INC)

INC_EL1  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR)  -I $(INC_DIR)/8650 -I $(PUBLIC_INC)/sailsw1
PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/interrupts)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_HYP);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_HYP_C) $(ASM_OPTS) $(SRC_HYP_S) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ]; then \
		echo $(INC_EL1);\
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
