.PHONY: clean all print setup

TIMEINC=$(SAIL_SRC_HOME)/BSP/time/public
CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
SPINOR_DIR=$(SAIL_SRC_HOME)/BSP/spinor/public
AUTH_DIR=$(SAIL_SRC_HOME)/BSP/security/sail_auth
SECIMG_UTILS=$(SAIL_SRC_HOME)/BSP/security/sail_auth/secutils/inc
UCLIB_PATH=$(SAIL_SRC_HOME)/BSP/security/uclib/api/uclib
XBL_INC=$(SAIL_SRC_HOME)/BSP/xbl/inc
GPT_INC=$(SAIL_SRC_HOME)/BSP/gpt/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
XBL_PUB=$(SAIL_SRC_HOME)/BSP/xbl/public/
ELF_LOADER_PUB=$(SAIL_SRC_HOME)/BSP/xbl/public/elfloader
ELF_LOADER_INC=$(SAIL_SRC_HOME)/BSP/xbl/inc/elfloader
XBL_CMN=$(SAIL_SRC_HOME)/BSP/xbl/public
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/
SYSCALL_SW_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/
SAILHEAP=$(SAIL_SRC_HOME)/BSP/sailheap/public
SWIV_INC=$(SAIL_SRC_HOME)/BSP/xbl/inc/swiv
CMSSM_INC=$(SAIL_SRC_HOME)/SSM/safetymonitor/safety_libs/inc
BOOT_UTILS_CONFIG=$(SAIL_SRC_HOME)/BSP/el_entry/inc/sailhyp
SAIL_UPDATER_INC=$(SAIL_SRC_HOME)/BSP/sail_updater/
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/xbl/src
ELF_LOADER_SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/xbl/src/elfloader
CM_SRC_C=$(SOURCE_DIR)/*.c

SRC_C=$(SOURCE_DIR)/sailhyp/*.c
SRC_EL1_C=$(SOURCE_DIR)/sailsw1/*.c

ELF_LOADER_C=$(SOURCE_DIR)/elfloader/*.c

ifeq ($(SWIV_FLAG),TRUE)
SWIV_SRC_C=$(SOURCE_DIR)/swiv/*.c
else
SWIV_SRC_C=$(SOURCE_DIR)/swiv_stub/*.c
endif


EL2_INC = -I $(CMNINC) -I $(CMNINC)/8650 -I $(GPT_INC) -I $(SAILHEAP) -I $(TIMEINC) -I $(SPINOR_DIR) -I $(SPINOR_DIR)/sailhyp -I $(XBL_CMN) -I $(XBL_PUB)/sailhyp -I $(XBL_INC) -I $(XBL_INC)/sailhyp -I $(SYSCALL_SW_INC)/sailhyp -I $(SYSCALL_PUB_INC) -I $(ELF_LOADER_PUB) -I $(ELF_LOADER_INC) -I $(AUTH_DIR)/sail_sec/inc/lemans -I $(AUTH_DIR)/mibib -I $(AUTH_DIR)/secboot/chipset -I $(AUTH_DIR)/secboot/env -I $(AUTH_DIR)/secboot/inc -I $(AUTH_DIR)/secboot/inc/common -I $(AUTH_DIR)/secimgauth/inc -I $(AUTH_DIR)/secimgauth/misc -I $(AUTH_DIR)/sail_sec/inc -I $(SECIMG_UTILS) -I $(BOOT_UTILS_CONFIG) -I $(CMSSM_INC) -I $(SWIV_INC) -I $(CHIPINFO_INC) -I $(UCLIB_PATH) -I $(SAIL_UPDATER_INC)/public -I $(SAIL_UPDATER_INC)/public/sailhyp


EL1_INC = -I $(CMNINC) -I $(CMNINC)/8650 -I $(XBL_CMN) -I $(XBL_PUB)/sailsw1 -I $(XBL_INC) -I $(XBL_INC)/sailsw1 -I $(SYSCALL_SW_INC)/sailsw1 -I $(SYSCALL_PUB_INC)

ifneq (,$(wildcard $(SRC_EL1_C)))
BUILD_REQUIRED=true
else
BUILD_REQUIRED=false
endif

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/xbl)

#this is temporary block for secruty header error with C99. we need -std=c99 later. TOOD: check if C99 can be used. remove the below comment of TARGET_OPTS
# export TARGET_OPTS := --target=arm-arm-none-eabi -mcpu=cortex-r52 -fno-builtin -nostdlib -Wno-unused-command-line-argument

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(EL2_INC);\
		($(CC) $(TARGET_OPTS) -DENB_TRAP_CALL $(EL2_INC) $(CC_SRC_OPTS) $(CM_SRC_C) $(SRC_C) $(ELF_LOADER_C) $(SWIV_SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		if [ $(BUILD_REQUIRED) = true ]; then \
			echo $(INC);\
			($(CC) $(TARGET_OPTS) -DENB_TRAP_CALL $(EL1_INC) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
	rm -fr ./aarch32/DEBUG/$(TAG)/*.o
	rm -fr ./aarch32/RELEASE/$(TAG)/*.o

print-%: setup
	@echo $* = $($*)

setup: 
 ifneq ($(ARM_TOOL_VARIANT),ult)
  $(Error! Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
 endif
