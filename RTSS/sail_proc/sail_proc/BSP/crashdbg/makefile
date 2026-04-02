.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/crashdbg/inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/crashdbg/public
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
PMIC_EL2_INC=$(SAIL_SRC_HOME)/BSP/pmic/public
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/public/
SPINOR_HYP=$(SAIL_SRC_HOME)/BSP/spinor/public/sailhyp
SPINOR_PUBLIC=$(SAIL_SRC_HOME)/BSP/spinor/public
CPR_INC=$(SAIL_SRC_HOME)/BSP/cpr/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
INC_SYSCALL_SYSCALL_PUB=$(SAIL_SRC_HOME)/BSP/el_entry/public
INC_SYSCALL_PUB=$(SAIL_SRC_HOME)/BSP/el_entry/public
SECDP_INC=$(SAIL_SRC_HOME)/BSP/security/sail_auth/secdbg/inc
SAILSEC_INC=$(SAIL_SRC_HOME)/BSP/security/sail_auth/sail_sec/inc/lemans
SECBOOT_INC=$(SAIL_SRC_HOME)/BSP/security/sail_auth/secboot/inc/common
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/crashdbg/src
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
BIST_INC=$(SAIL_SRC_HOME)/BSP/bist/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/public/sailsw1
ISD_HYP_INC=$(SAIL_SRC_HOME)/BSP/isd/public/sailhyp
SRC_C=$(SOURCE_DIR)/sailhyp/*.c
SRC_S=$(SOURCE_DIR)/sailhyp/*.s
SRC_EL1_C=$(SOURCE_DIR)/sailsw1/*.c
SRC_EL1_S=$(SOURCE_DIR)/sailsw1/*.s

INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I$(ISD_HYP_INC) -I $(INC_DIR) -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(FREERTOS_INC) -I $(INC_SAIL_FREERTOS) -I$(GPIO_INC) -I$(BUSYWAIT_INC) -I$(PMIC_EL2_INC) -I$(ISD_INC)/sailhyp -I$(SPINOR_PUBLIC) -I$(SPINOR_HYP) -I $(CPR_INC) -I $(CHIPINFO_INC) -I $(INC_SYSCALL_SYSCALL_PUB) -I $(INC_SYSCALL_PUB)/sailhyp -I $(SECDP_INC) -I $(SAILSEC_INC) -I $(SECBOOT_INC) -I $(CLOCK_INC) -I $(BIST_INC)

INC_EL1  = -I $(CMNINC) -I $(ISD_INC) -I $(IPCC_INC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(FREERTOS_INC) -I $(INC_SAIL_FREERTOS) -I$(GPIO_INC) -I$(BUSYWAIT_INC) -I$(PMIC_EL2_INC) -I$(ISD_INC)/sailsw1 -I$(SPINOR_PUBLIC) -I$(SPINOR_HYP) -I $(CPR_INC) -I $(CHIPINFO_INC) -I $(INC_SYSCALL_SYSCALL_PUB) -I $(INC_SYSCALL_PUB)/sailsw1 -I $(SPINOR_PUBLIC)/sailsw1 -I $(SLEEP_INC) -I $(SLEEP_INC)/sailsw1

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/crashdbg)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		$(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_ASM_OPTS) $(SRC_S) $(CC_OPTS)|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_EL1);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
