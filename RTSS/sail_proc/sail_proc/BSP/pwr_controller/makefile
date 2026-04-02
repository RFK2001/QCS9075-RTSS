.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
INC_DIR=$(SAIL_SRC_HOME)/BSP/pwr_controller/inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/pwr_controller/public
PUBLIC_HYP_INC=$(SAIL_SRC_HOME)/BSP/pwr_controller/public/sailhyp
PUBLIC_SW1_INC=$(SAIL_SRC_HOME)/BSP/pwr_controller/public/sailsw1
FDT_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SYSCALL_HYP_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
SYSCALL_SW1_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1
SOURCE_HYP_DIR=$(SAIL_SRC_HOME)/BSP/pwr_controller/src/sailhyp
SOURCE_SW1_DIR=$(SAIL_SRC_HOME)/BSP/pwr_controller/src/sailsw1
SRC_HYP_C=$(SOURCE_HYP_DIR)/*.c
SRC_HYP_S=$(SOURCE_HYP_DIR)/*.s
SRC_SW1_C=$(SOURCE_SW1_DIR)/*.c
SRC_SW1_S=$(SOURCE_SW1_DIR)/*.s
INC_HYP  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(PUBLIC_HYP_INC) -I $(INTERRUPTS_INC)/sailhyp -I $(BUSYWAIT_INC) -I$(SYSCALL_PUB_INC) -I$(SYSCALL_HYP_INC)  -I $(FDT_INC)
INC_SW1  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC) -I $(PUBLIC_SW1_INC) -I$(SYSCALL_PUB_INC) -I$(SYSCALL_SW1_INC) 

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/pwr_controller)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_HYP);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_HYP_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_HYP);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_HYP_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	elif [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && [ "$(IMAGE_RTOS)" = "FREERTOS" ] &&echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_SW1);\
		($(CC) $(TARGET_OPTS) $(INC_SW1) $(CC_SRC_OPTS) $(SRC_SW1_C) $(CC_OPTS))|| exit $$?; \
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
