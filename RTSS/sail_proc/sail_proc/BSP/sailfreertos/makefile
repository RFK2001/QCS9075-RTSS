.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/sailfreertos/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/sailfreertos/src
SAILSW1_TESTS_INC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1
OSAL_INC=$(SAIL_SRC_HOME)/BSP/osal/public
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/public/
TEST_INC=$(SAIL_SRC_HOME)/BSP/tests/public/
ELENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
GPIO_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
SPI_INC=$(SAIL_SRC_HOME)/BSP/spi/public
SAIL_UPDATER_INC=$(SAIL_SRC_HOME)/BSP/sail_updater/public/sailsw1
SPINOR_PUB_INC=$(SAIL_SRC_HOME)/BSP/spinor/public
SPINOR_INC=$(SAIL_SRC_HOME)/BSP/spinor/public/sailsw1
PSAIL_INC=$(SAIL_SRC_HOME)/BSP/psail/public
PMIC_INC=$(SAIL_SRC_HOME)/BSP/pmic/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
INTERRUPT_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public/sailsw1
TIME_INC=$(SAIL_SRC_HOME)/BSP/time/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/public
DDR_MS_INC=$(SAIL_SRC_HOME)/BSP/ddrmilestone/public
PMU_INC=$(SAIL_SRC_HOME)/BSP/pmu/public
CAN_PUB_INC = $(SAIL_SRC_HOME)/BSP/can/public
ICB_INC=$(SAIL_SRC_HOME)/BSP/icb/public/sailsw1
CAN_MAILBOX_PUB_INC = $(SAIL_SRC_HOME)/BSP/can_mailbox/public/sailel1
CRASHDBG_INC=$(SAIL_SRC_HOME)/BSP/crashdbg/public
TEST_INC = $(SAIL_SRC_HOME)/BSP/tests/public/sailsw1

SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s

INC = -I $(TIME_INC) -I $(PSAIL_INC) -I$(INTERRUPT_INC) -I $(DDR_MS_INC) -I$(CRASHDBG_INC) -I $(PMU_INC) -I $(CLOCK_INC) -I $(ICB_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC) -I $(FREERTOS_CONFIG_INC) -I $(ELENTRY_INC) -I $(ELENTRY_INC)/sailsw1/ -I $(IPCC_INC) -I $(ISD_INC) -I $(ISD_INC)/sailsw1 -I $(SPI_INC) -I $(CAN_PUB_INC)/sailel1 -I $(TEST_INC) -I $(CAN_MAILBOX_PUB_INC) -I $(CMNINC)/8650 -I $(OSAL_INC) -I $(GPIO_PUBLIC_INC) -I $(TEST_INC)/sailsw1 -I $(ISD_INC)/sailsw1  -I $(SAILSW1_TESTS_INC)/osal_test/public  -I $(ELENTRY_INC) -I $(SAIL_UPDATER_INC) -I $(SPINOR_PUB_INC) -I $(SPINOR_INC) -I $(PMIC_INC)/sailsw1 -I $(SLEEP_INC) -I $(SLEEP_INC)/sailsw1


PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/sailsafertos)

all: setup
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC) $(INC_SAIL_FREERTOS);\
		$(CC) $(TARGET_OPTS) $(INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS); \
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
