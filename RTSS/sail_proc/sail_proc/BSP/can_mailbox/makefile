.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/mailboxExt/inc
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public/sailsw1
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/public
EL_ENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
CAN_PUB_INC=$(SAIL_SRC_HOME)/BSP/can/public/sailel1
CAN_STUB_INC=$(SAIL_SRC_HOME)/BSP/can/stub
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/can_mailbox/public/sailel1
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/can_mailbox/src/sailel1
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
ifeq ("$(TARGET)" , "lemans")
	PLT_DEF=CHIPINFO_FAMILY_LEMANS
endif
ifeq ("$(TARGET)" , "monaco")
	PLT_DEF=CHIPINFO_FAMILY_MONACO
endif
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s
INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(PUBLIC_INC) -I $(INTERRUPTS_INC) -I $(IPCC_INC) -I $(BUSYWAIT_INC) -I $(ISD_INC) -I $(ISD_INC)/sailsw1 -I $(MAILBOXLIB_INC) -I $(MAILBOXEXT_INC) -I $(CAN_PUB_INC) -I $(CAN_STUB_INC) -I $(EL_ENTRY_INC) -I$(EL_ENTRY_INC)/sailsw1 -I $(CHIPINFO_INC)

# PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/mailboxExt)

all: setup
	@if [ "$(TAG)" != "sailhyp" ]; then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) -D$(PLT_DEF) $(INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
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