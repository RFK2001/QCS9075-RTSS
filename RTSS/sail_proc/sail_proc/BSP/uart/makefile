.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/uart/inc
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
ifeq ("$(TARGET)" , "lemans")
	CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
endif
ifeq ("$(TARGET)" , "monaco")
	CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8620
endif
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
LOGCODE_INC = $(SAIL_SRC_HOME)/BSP/LogCode/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
TESTS_UT_INC=$(SAIL_SRC_HOME)/BSP/tests
FDT_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/uart/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/uart/src
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s
INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(FDT_INC) -I $(INC_DIR)/8650 -I$(IPCC_INC) -I $(GPIO_INC) -I $(SAIL_SRC_HOME)/BSP/clock/inc -I $(CLOCK_INC) -I $(CLOCK_INC_HW) -I $(BUSYWAIT_INC) -I $(INC_DIR)/inc -I $(CHIPINFO_INC) -I $(INTERRUPTS_INC)/sailhyp -I $(PUBLIC_INC) -I $(LOGCODE_INC) -I $(TESTS_UT_INC) -I $(MAILBOXLIB_INC) -I $(MAILBOXEXT_INC) -I $(SLEEP_INC) -I $(SLEEP_INC)/sailsw1
INC_EL1  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(FDT_INC) -I $(INC_DIR)/8650 -I$(IPCC_INC) -I $(GPIO_INC) -I $(SAIL_SRC_HOME)/BSP/clock/inc -I $(CLOCK_INC) -I $(CLOCK_INC_HW) -I $(BUSYWAIT_INC) -I $(INC_DIR)/inc -I $(CHIPINFO_INC) -I $(INTERRUPTS_INC)/sailsw1 -I $(PUBLIC_INC) -I $(LOGCODE_INC) -I $(TESTS_UT_INC) -I $(MAILBOXLIB_INC) -I $(MAILBOXEXT_INC) -I $(SLEEP_INC) -I $(SLEEP_INC)/sailsw1
PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/uart)

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
	elif [ "$(TAG)" != "sailhyp" ] &&echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_EL1) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
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
