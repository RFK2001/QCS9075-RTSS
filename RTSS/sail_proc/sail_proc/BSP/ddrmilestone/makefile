.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/ddrmilestone/inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/ddrmilestone/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/ddrmilestone/src
ISD_SW1_INC=$(SAIL_SRC_HOME)/BSP/isd/public
ELENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
OSAL_INC=$(SAIL_SRC_HOME)/BSP/osal/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s

INC  = -I $(IPCC_INC) -I $(CMNINC) -I $(OSAL_INC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(ISD_SW1_INC) -I $(ISD_SW1_INC)/sailsw1 -I $(FREERTOS_INC) -I $(INC_SAIL_FREERTOS) -I $(ELENTRY_INC) -I $(MAILBOXEXT_INC) -I $(MAILBOXLIB_INC) -I $(ELENTRY_INC)/sailsw1
	   
# PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/ddrmilestone)
	   
all: setup
	@if [ "$(TAG)" != "sailhyp" ]; then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
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
