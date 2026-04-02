.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
MAILBOXINT_INC=$(SAIL_SRC_HOME)/BSP/mailboxInt/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
UART_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/uart/public
FUSA_INC = $(SAIL_SRC_HOME)/BSP/fusa/public
GPIO_INC = $(SAIL_SRC_HOME)/BSP/gpio/public
EMAC_API_INC=$(SAIL_SRC_HOME)/BSP/data/ethernet/emac/driver/api/public/safeRTOS
VERSION_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
SAILFS_PUB=$(SAIL_SRC_HOME)/BSP/sail_fs/public
ACMUSER_INC = $(SAIL_SRC_HOME)/BSP/acmu/public
MONITORINTR_INC = $(SAIL_SRC_HOME)/BSP/monitor/public
ACMU_INC = $(SAIL_SRC_HOME)/BSP/acmu/inc
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public/
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
TSENS_INC = $(SAIL_SRC_HOME)/BSP/tsens
PWR_CONTROLLER_INC=$(SAIL_SRC_HOME)/BSP/pwr_controller
TEST_PUBLIC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/tests/public
LOGCODE_INC = $(SAIL_SRC_HOME)/BSP/LogCode/public
CRASHDBG_INC=$(SAIL_SRC_HOME)/BSP/crashdbg/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public

ifeq ("$(TARGET)" , "lemans")
	CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
endif
ifeq ("$(TARGET)" , "monaco")
	CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8620
endif

SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/mailbox_test/src

SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I $(PUBLIC_INC) -I$(IPCC_INC)  -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(TEST_HWIO_INC) -I $(MAILBOXEXT_INC) -I $(MAILBOXINT_INC) -I $(MAILBOXLIB_INC) -I $(IPCC_INC) -I $(UART_PUBLIC_INC) -I $(FUSA_INC) -I $(GPIO_INC) -I $(EMAC_API_INC) -I $(VERSION_INC) -I $(SAILFS_PUB) -I $(ACMUSER_INC) -I $(MONITORINTR_INC) -I $(ACMU_INC) -I $(BUSYWAIT_INC) -I $(CLOCK_INC_HW) -I $(CHIPINFO_INC) -I $(TSENS_INC)/public -I $(TSENS_INC)/public/sailsw1 -I $(PWR_CONTROLLER_INC)/inc/8650 -I $(TEST_PUBLIC) -I $(LOGCODE_INC) -I $(CRASHDBG_INC)

PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/mailboxExt)

all: setup
	  @if [ "$(TAG)" != "sailhyp" ] ; then \
               echo $(INC);\
               ($(CC) $(TARGET_OPTS) $(TARGET_OPTS) $(INC_SAIL_FREERTOS) $(SAILSW1_INC) $(SRC_C) $(CC_OPTS)) || exit $$?; \
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
