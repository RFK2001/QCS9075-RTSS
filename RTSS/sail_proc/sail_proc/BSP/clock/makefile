.PHONY: clean all print setup

export CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/clock/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
PMIC_INC=$(SAIL_SRC_HOME)/BSP/pmic/public
INC_SYSCALL_SYSCALL_PUB=$(SAIL_SRC_HOME)/BSP/el_entry/public
INC_SYSCALL_PUB=$(SAIL_SRC_HOME)/BSP/el_entry/public
SAILHEAP=$(SAIL_SRC_HOME)/BSP/sailheap/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/clock/src
INC_DIR=$(SAIL_SRC_HOME)/BSP/clock/inc
ifeq ("$(TARGET)" , "lemans")
	INC_DIR_TARGET=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
	SRC_HYP_TARGET=$(SOURCE_DIR)/sailhyp/8650/*.c
endif
ifeq ("$(TARGET)" , "monaco")
	INC_DIR_TARGET=$(SAIL_SRC_HOME)/BSP/clock/inc/8620
	SRC_HYP_TARGET=$(SOURCE_DIR)/sailhyp/8620/*.c
endif
SRC_EL2_C=$(SOURCE_DIR)/sailhyp/*.c
SRC_EL1_C=$(SOURCE_DIR)/sailsw1/*.c
SRC_JTAG_C=$(SOURCE_DIR)/sailhyp/*.c
SRC_JTAG_S=$(SOURCE_DIR)/sailhyp/*.s
INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(PUBLIC_INC) -I $(INC_SYSCALL_SYSCALL_PUB) -I $(INC_SYSCALL_PUB)/sailhyp -I $(INC_DIR_TARGET) -I $(CHIPINFO_INC) -I$(BUSYWAIT_INC) -I $(SAILHEAP) -I $(PMIC_INC)
INC_JTAG  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(PUBLIC_INC) -I $(INC_SYSCALL_SYSCALL_PUB) -I $(INC_SYSCALL_PUB)/sailhyp -I $(INC_DIR_TARGET) -I $(CHIPINFO_INC) -I$(BUSYWAIT_INC) -I $(SAILHEAP)
INC_EL1  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(PUBLIC_INC) -I $(INC_SYSCALL_SYSCALL_PUB) -I $(INC_SYSCALL_PUB)/sailsw1 -I $(INC_DIR_TARGET) -I $(CHIPINFO_INC) -I$(BUSYWAIT_INC) -I $(SAILHEAP)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/clock)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC_JTAG) $(CC_SRC_OPTS) $(SRC_JTAG_C) $(SRC_HYP_TARGET) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_EL2_C) $(SRC_HYP_TARGET) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
