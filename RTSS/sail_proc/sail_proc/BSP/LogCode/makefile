.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/LogCode/public
FDT_PUBLIC=$(SAIL_SRC_HOME)/BSP/fdt/public
UART_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/uart/public
CRC_INC=$(SAIL_SRC_HOME)/BSP/crc/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/LogCode/src
TEST_INC=$(SAIL_SRC_HOME)/BSP/tests/public
ADSPCHIME_INC=$(SAIL_SRC_HOME)/BSP/adspchime/public
BIDINFO_INC=$(SAIL_SRC_HOME)/BSP/bidinfo/public
MAILBOX_EXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
SRC_C=$(SOURCE_DIR)/*.c 
SRC_S=$(SOURCE_DIR)/*.s
INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC) -I $(FDT_PUBLIC) -I $(UART_PUBLIC_INC) -I $(CRC_INC) -I $(TEST_INC) -I $(BIDINFO_INC) -I $(ADSPCHIME_INC) -I $(MAILBOX_EXT_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/LogCode)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ;\
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	elif [ "$(IMAGE_RTOS)" = "FREERTOS" ] &&echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC_SAIL_FREERTOS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ;\
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi

clean:
	rm -fr ./aarch32/$(BUILD_TARGET)/$(TAG)/*.o  
	rm -fr ./aarch32/$(BUILD_TARGET)/$(TAG)/*.o  

print-%: setup
	@echo $* = $($*)

setup: 
 ifneq ($(ARM_TOOL_VARIANT),ult)
  $(Error! Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
 endif
