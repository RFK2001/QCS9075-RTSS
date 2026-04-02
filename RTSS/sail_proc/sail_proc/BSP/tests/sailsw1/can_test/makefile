.PHONY: clean all print setup

DFLAGS= -DCAN_FUSA_NTFY_FEATURE_ENABLE

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
TESTS_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/tests/public
CAN_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/can/public/
CAN_INC=$(SAIL_SRC_HOME)/BSP/can/inc/
CAN_MAILBOX_PUB_INC=$(SAIL_SRC_HOME)/BSP/can_mailbox/public/sailsw1
CAN_HWIO_INC=$(SAIL_SRC_HOME)/BSP/can/inc/8650
CAN_TRCV=$(SAIL_SRC_HOME)/BSP/can_trcv/public/
CAN_MCAL_PUB_INC=$(SAIL_SRC_HOME)/BSP/can/public/sailmcal
CAN_MCAL_PRIV_INC=$(SAIL_SRC_HOME)/BSP/can/inc/sailmcal
MCAL_CMN_INC=$(SAIL_SRC_HOME)/BSP/Mcal/Base
FUSA_INC = $(SAIL_SRC_HOME)/BSP/fusa/public
MONITORINTR_INC = $(SAIL_SRC_HOME)/BSP/monitor/public
GPIO_INC = $(SAIL_SRC_HOME)/BSP/gpio/public
GIC_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
MEMHEAP_INC = $(SAIL_SRC_HOME)/BSP/memheap/public
MEMHEAP_SRC = $(SAIL_SRC_HOME)/BSP/memheap/inc
CAN_TEST_PUB=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/can_test/public
SPI_MCAL_INC=$(SAIL_SRC_HOME)/BSP/spi/public
SPI_MCAL_CFG_INC=$(SAIL_SRC_HOME)/BSP/McalCfg/Inc


CAN1_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/public/sailel1
CAN2_INC=$(SAIL_SRC_HOME)/BSP/can/stub
CAN3_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/lemans
CAN4_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/stub/
CAN5_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/public/sailel1

TCAN1044_PUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/public/sailel1
TCAN1146_PUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/public/sailel1
CAN_INC_DIR=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1
CAN_GEN_DIR=$(SAIL_SRC_HOME)/BSP/can/Gen
CAN_PUB_DIR=$(SAIL_SRC_HOME)/BSP/can/public/sailel1
CAN_STUB_DIR=$(SAIL_SRC_HOME)/BSP/can/stub
TCAN1146_STUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/stub
TCAN1044_STUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/stub/

ifeq ("$(TARGET)" , "lemans")
CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
TCAN1044_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/Gen/lemans
TCAN1146_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/lemans
CAN_INC_HW=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1/lemans
CAN_GEN_INC=$(CAN_GEN_DIR)/lemans
endif

ifeq ("$(TARGET)" , "monaco")
CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
TCAN1044_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/Gen/monaco
TCAN1146_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/monaco
CAN_INC_HW=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1/monaco
CAN_GEN_INC=$(CAN_GEN_DIR)/monaco
endif

SAILHEAP=$(SAIL_SRC_HOME)/BSP/sailheap/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
MAILBOXINT_INC=$(SAIL_SRC_HOME)/BSP/mailboxInt/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
SM_CLIENT_PUBLIC = $(SAIL_SRC_HOME)/SSM/safetymonitor/sm_client/public
SM_SHARED = $(SAIL_SRC_HOME)/SSM/safetymonitor/safety_shared
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/can_test/src
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I $(PUBLIC_INC) -I $(CMNINC) -I $(TESTS_PUBLIC_INC) -I $(CAN1_INC) -I $(CAN2_INC) -I $(CAN3_INC) -I $(CAN4_INC) -I $(CAN5_INC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(CAN_MCAL_PUB_INC) -I $(CAN_MCAL_PRIV_INC) -I $(CAN_INC)/sailsw1 -I $(CAN_PUBLIC_INC)/sailsw1 -I $(CAN_HWIO_INC) -I $(CAN_TRCV)/sailsw1 -I $(MCAL_CMN_INC) -I $(FUSA_INC) -I $(MONITORINTR_INC) -I $(GPIO_INC) -I $(GIC_INC) -I $(BUSYWAIT_INC) -I $(MEMHEAP_INC) -I $(MEMHEAP_SRC) -I $(CAN_TEST_PUB) -I $(SPI_MCAL_INC) -I $(SPI_MCAL_CFG_INC) -I $(SAILHEAP) -I $(MAILBOXEXT_INC) -I $(MAILBOXINT_INC) -I $(MAILBOXLIB_INC) -I $(CAN_MAILBOX_PUB_INC) -I $(SM_CLIENT_PUBLIC) -I $(SM_SHARED)  -I $(TCAN1044_PUB) -I $(IPCC_INC) -I $(TCAN1044_GEN) -I $(TCAN1044_STUB) -I $(TCAN1146_PUB) -I $(TCAN1146_GEN) -I $(TCAN1146_STUB)

INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(PUBLIC_INC) -I $(SPI_INC) -I $(CHIPINFO_INC) -I $(CAN_INC_HW) -I $(CAN_PUB_DIR) -I $(CAN_INC_DIR) -I $(CAN_STUB_DIR) -I $(CAN_GEN_INC) -I $(TCAN1044_PUB) -I $(IPCC_INC) -I $(TCAN1044_GEN) -I $(TCAN1044_STUB) -I $(TCAN1146_PUB) -I $(TCAN1146_GEN) -I $(TCAN1146_STUB)

PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/can)

all: setup
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && [ "$(TAG)" != "autosarsailbaremetal" ]; then \
                 echo $(SAILSW1_INC) $(INC_SAIL_FREERTOS);\
                ($(CC) $(TARGET_OPTS) $(SAILSW1_INC) $(INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(SAILVSENS_TESTEN_OPTION) $(CC_OPTS)) || exit $$?; \
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
