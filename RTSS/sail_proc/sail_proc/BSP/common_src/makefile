.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
LOGCODE=$(SAIL_SRC_HOME)/BSP/LogCode/public
UART_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/uart/public
BUSYWAIT_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/time/public
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public/
FREERTOS_INC=$(SAIL_SRC_HOME)/FreeRTOS/kernel/include
FREERTOS_CONFIG_INC=$(SAIL_SRC_HOME)/FreeRTOS/config
FREERTOS_PORT_INC=$(SAIL_SRC_HOME)/FreeRTOS/kernel/portable/
SAILFREERTOS_INC=$(SAIL_SRC_HOME)/BSP/sailfreertos/public/
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
CRC_INC=$(SAIL_SRC_HOME)/BSP/crc/public
FDT_PUBLIC=$(SAIL_SRC_HOME)/BSP/fdt/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/public/
SAIL_BOOTCFG=$(SAIL_SRC_HOME)/BSP/sail_bootcfg/public
TEST_INC=$(SAIL_SRC_HOME)/BSP/tests/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/common_src

SRC_C=$(SOURCE_DIR)/*.c $(SOURCE_DIR)/sailhyp/*.c
SRC_EL1_C=$(SOURCE_DIR)/*.c $(SOURCE_DIR)/sailsw1/*.c
SRC_S=$(SOURCE_DIR)/*.s

EL_ENTRY_INC  = -I $(SAIL_SRC_HOME)/BSP/el_entry/public

INC  = -I $(CMNINC) -I $(LOGCODE) -I $(CMNINC)/8650 -I $(CRC_INC) -I $(FDT_PUBLIC) -I $(UART_PUBLIC_INC) -I $(BUSYWAIT_PUBLIC_INC) -I $(GPIO_INC) -I $(ISD_INC) -I $(ISD_INC)/sailhyp -I $(WDT_INC)/sailhyp -I $(CLOCK_INC)

INC_EL1  = -I $(CMNINC) -I $(LOGCODE) -I $(CRC_INC) -I $(CMNINC)/8650 -I $(UART_PUBLIC_INC) \
						-I $(BUSYWAIT_PUBLIC_INC) -I $(GPIO_INC) -I $(IPCC_INC) -I $(ISD_INC)/sailsw1 \
						-I $(FREERTOS_PORT_INC) \
						-I $(MAILBOXEXT_INC) -I $(MAILBOXLIB_INC) -I $(SAIL_BOOTCFG) -I $(TEST_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/common_src)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(EL_ENTRY_INC) $(EL_ENTRY_INC)/sailhyp $(CC_SRC_OPTS) $(SRC_C) $(CC_ASM_OPTS) $(SRC_S) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(EL_ENTRY_INC) $(EL_ENTRY_INC)/sailhyp $(CC_SRC_OPTS) $(SRC_C) $(CC_ASM_OPTS) $(SRC_S) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	elif [ "$(TAG)" != "sailhyp" ] ; then \
		echo $(INC_EL1) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(EL_ENTRY_INC) $(EL_ENTRY_INC)/sailsw1 $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_ASM_OPTS) $(SRC_S) $(CC_OPTS) )|| exit $$?; \
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
