.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/sail_updater/inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/sail_updater/public
PUBLIC_HYP_INC=$(SAIL_SRC_HOME)/BSP/sail_updater/public/sailhyp
PUBLIC_SW1_INC=$(SAIL_SRC_HOME)/BSP/sail_updater/public/sailsw1
DMACRC_PRVINC=$(SAIL_SRC_HOME)/BSP/dma_crc/inc
CRC_INC=$(SAIL_SRC_HOME)/BSP/crc/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
OSPINOR_EL1_INC = $(SAIL_SRC_HOME)/BSP/spinor/public/sailsw1
OSPINOR_EL2_INC = $(SAIL_SRC_HOME)/BSP/spinor/public/sailhyp
OSPINOR_CMN = $(SAIL_SRC_HOME)/BSP/spinor/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
BOOT_HYP_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SYSCALL_SW1_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1
XBL_EL2_INC=$(SAIL_SRC_HOME)/BSP/xbl/public/sailhyp
XBL_EL1_INC=$(SAIL_SRC_HOME)/BSP/xbl/public/sailsw1
XBL_CMN=$(SAIL_SRC_HOME)/BSP/xbl/public/
GPT_INC=$(SAIL_SRC_HOME)/BSP/gpt/public
FDT_PUBLIC=$(SAIL_SRC_HOME)/BSP/fdt/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep
TESTS_INC=$(SAIL_SRC_HOME)/BSP/tests
SOURCE_HYP_DIR=$(SAIL_SRC_HOME)/BSP/sail_updater/src/sailhyp
SOURCE_SW1_DIR=$(SAIL_SRC_HOME)/BSP/sail_updater/src/sailsw1
SRC_HYP_C=$(SOURCE_HYP_DIR)/*.c
SRC_HYP_S=$(SOURCE_HYP_DIR)/*.s
SRC_SW1_C=$(SOURCE_SW1_DIR)/*.c
SRC_SW1_S=$(SOURCE_SW1_DIR)/*.s
INC_HYP  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(PUBLIC_INC) -I $(PUBLIC_HYP_INC) -I $(GPT_INC) -I $(XBL_CMN) -I $(XBL_EL2_INC) -I$(CRC_INC) -I $(MAILBOXEXT_INC) -I $(MAILBOXLIB_INC) -I $(OSPINOR_EL2_INC) -I $(OSPINOR_CMN) -I $(BOOT_HYP_INC) -I $(FDT_PUBLIC)
INC_SW1  = -I $(IPCC_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(PUBLIC_INC) -I $(PUBLIC_SW1_INC) -I $(GPT_INC) -I $(XBL_CMN) -I $(XBL_EL1_INC) -I$(CRC_INC) -I$(DMACRC_PRVINC) -I $(MAILBOXEXT_INC) -I $(MAILBOXLIB_INC) -I $(OSPINOR_EL1_INC) -I $(OSPINOR_CMN) -I $(SYSCALL_PUB_INC) -I $(SYSCALL_SW1_INC) -I $(FDT_PUBLIC) -I $(SLEEP_INC)/inc/8650 -I $(SLEEP_INC)/public -I $(SLEEP_INC)/public/sailsw1

ifeq ($(SAILUPDATER_INJTEST_ENABLED_VAL),1)
INC_HYP += -I $(TESTS_INC)/public/sailhyp
endif


ifneq (,$(wildcard $(SRC_SW1_C)))
BUILD_REQUIRED=true
else
BUILD_REQUIRED=false
endif

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/sail_updater)

#TODO: Taking or using address of packed member may result in an unaligned ptr value. Currently suppressing the error as the msg img struct type has required alignment. Once resolved remove the Compiler flag.
CC_ERROR_OPTS = -Wno-address-of-packed-member

all: setup
#enable the below lines to compile only EL2 driver for HYP
ifneq ($(NORPVL_ENB_VAL),1)
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_HYP);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_HYP_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
endif

	#enable the below lines to compile EL1 driver for SW1
	@if [ "$(TAG)" != "sailhyp" ]; then \
		if [ $(BUILD_REQUIRED) = true ]; then \
			echo $(INC_SW1) $(INC_SAIL_FREERTOS);\
			($(CC) $(TARGET_OPTS) $(INC_SW1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_SW1_C) $(CC_OPTS) $(CC_ERROR_OPTS))|| exit $$?; \
			mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
			cp *.o aarch32/$(BUILD_TARGET)/$(TAG); \
			find aarch32/$(BUILD_TARGET)/$(TAG)/*.o | xargs $(COMPILER_PATH)/fromelf --elf --in_place --strip=all; \
			mkdir -p aarch32_store/$(BUILD_TARGET)/ ; \
			tar cf ./aarch32_store/$(BUILD_TARGET)/obj_store_$(TAG).tar aarch32/$(BUILD_TARGET)/$(TAG)/; \
			mv -f *.o ./aarch32/$(BUILD_TARGET)/$(TAG); \
		else \
			tar xvf ./aarch32_store/$(BUILD_TARGET)/obj_store_$(TAG).tar; \
		fi; \
	fi
clean:
	rm -fr ./aarch32/$(TAG)/*.o  
print-%: setup
	@echo $* = $($*)

setup: 
 ifneq ($(ARM_TOOL_VARIANT),ult)
  $(Error! Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
 endif
