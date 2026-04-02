.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INTINC=$(SAIL_SRC_HOME)/BSP/interrupts/public
OSAL_PUB=$(SAIL_SRC_HOME)/BSP/osal/public
IPCC_PUB=$(SAIL_SRC_HOME)/BSP/ipcc/public
SRC_DIR=$(SAIL_SRC_HOME)/BSP/osal/src

SRC_C=$(SRC_DIR)/sailhyp/*.c
SRC_EL1_C=$(SRC_DIR)/sailsw1/*.c

INC = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INTINC)/sailhyp -I $(OSAL_PUB)
INC_EL1 = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INTINC)/sailsw1 -I $(OSAL_PUB)
PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/osal)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_EL1) $(INC_SAIL_SAFERTOS);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(INC_SAIL_FREERTOS) -I $(IPCC_PUB) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
