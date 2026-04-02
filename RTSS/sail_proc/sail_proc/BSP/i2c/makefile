.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/i2c/inc
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
SYSCALL_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
FDT_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/i2c/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
Crashdbg_INC=$(SAIL_SRC_HOME)/BSP/crashdbg/public
I2C_TEST_WRAPPER_INC=$(SAIL_SRC_HOME)/BSP/tests
SRC_C=$(SAIL_SRC_HOME)/BSP/i2c/src/sailhyp/*.c
SRC_S=$(SAIL_SRC_HOME)/BSP/i2c/src/sailhyp/*.s

SRC_EL1_C=$(SAIL_SRC_HOME)/BSP/i2c/src/sailsw1/*.c
SRC_EL1_S=$(SAIL_SRC_HOME)/BSP/i2c/src/sailsw1/*.s


INC_HYP  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(FDT_INC) -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(GPIO_INC) -I $(CLOCK_INC) -I$(BUSYWAIT_INC) -I $(INTERRUPTS_INC)/sailhyp -I $(SYSCALL_INC) -I $(SYSCALL_INC)/sailhyp -I $(BUSYWAIT_INC) -I $(SLEEP_INC) -I $(SLEEP_INC)/sailhyp -I $(Crashdbg_INC)

INC_SW1  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(SYSCALL_INC) -I $(FDT_INC) -I $(SYSCALL_INC)/sailsw1 -I $(PUBLIC_INC) -I $(INC_DIR) -I $(INC_DIR)/8650 -I $(GPIO_INC) -I $(CLOCK_INC) -I$(BUSYWAIT_INC) -I $(INTERRUPTS_INC)/sailsw1 -I $(SLEEP_INC) -I $(SLEEP_INC)/sailhyp -I $(SLEEP_INC)/sailsw1 -I $(I2C_TEST_WRAPPER_INC)/sailsw1 -I $(I2C_TEST_WRAPPER_INC)/public/sailsw1

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/i2c)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_SW1) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(INC_SW1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
