.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/chipinfo/inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/chipinfo/src
SRC_EL2_C=$(SOURCE_DIR)/sailhyp/*.c
SRC_EL1_C=$(SOURCE_DIR)/sailsw1/*.c
INC_SYSCALL_SYSCALL_PUB=$(SAIL_SRC_HOME)/BSP/el_entry/public
INC_SYSCALL_PUB=$(SAIL_SRC_HOME)/BSP/el_entry/public
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/inc
INC  = -I $(CMNINC) -I $(GPIO_INC)/8650 -I $(CMNINC)/8650 -I $(INC_DIR) -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(INC_SYSCALL_SYSCALL_PUB) -I $(INC_SYSCALL_PUB)/sailhyp
INC_SW  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(INC_SYSCALL_SYSCALL_PUB) -I $(INC_SYSCALL_PUB)/sailsw1

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/chipinfo)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_EL2_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_EL2_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_SW);\
		($(CC) $(TARGET_OPTS) $(INC_SW) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
