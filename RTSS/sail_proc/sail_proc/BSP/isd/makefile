.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INTINC=$(SAIL_SRC_HOME)/BSP/interrupts/public
TESTINC=$(SAIL_SRC_HOME)/BSP/tests/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
LOGCODE_INC=$(SAIL_SRC_HOME)/BSP/LogCode/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
AC_INC=$(SAIL_SRC_HOME)/BSP/security/accesscontrol/common/public
PMIC_INC=$(SAIL_SRC_HOME)/BSP/pmic/public
CPR_INC_EL2=$(SAIL_SRC_HOME)/BSP/cpr/public
ELENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
DBG_INC=$(SAIL_SRC_HOME)/BSP/crashdbg/public
EB_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
SPINOR_INC=$(SAIL_SRC_HOME)/BSP/spinor/public
BUSYWAIT_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/time/public
XBL_INC=$(SAIL_SRC_HOME)/BSP/xbl/public
PRVINC_DIR=$(SAIL_SRC_HOME)/BSP/isd/inc
PUBINC_DIR=$(SAIL_SRC_HOME)/BSP/isd/public/
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/isd/src
DDRMLST_INC=$(SAIL_SRC_HOME)/BSP/ddrmilestone/public
VSENS_INC=$(SAIL_SRC_HOME)/BSP/vsens/public

SRC_C=$(SOURCE_DIR)/*.c $(SOURCE_DIR)/sailhyp/*.c
SRC_EL1_C=$(SOURCE_DIR)/*.c $(SOURCE_DIR)/sailsw1/*.c
SRC_S=$(SOURCE_DIR)/*.s

INC  = -I $(EB_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBINC_DIR) -I $(PUBINC_DIR)/sailhyp -I $(PRVINC_DIR) -I $(LOGCODE_INC) -I $(SPINOR_INC) -I $(SPINOR_INC)/sailhyp  -I $(PRVINC_DIR)/sailhyp -I $(PRVINC_DIR)/8650 -I $(FREERTOS_INC) -I $(INC_SAIL_FREERTOS) -I $(INTINC)/sailhyp -I $(IPCC_INC) -I $(CHIPINFO_INC) -I $(PMIC_INC) -I $(CPR_INC_EL2) -I $(TESTINC)/sailhyp -I $(ELENTRY_INC) -I $(ELENTRY_INC)/sailhyp -I $(DBG_INC) -I $(DBG_INC)/sailhyp -I $(XBL_INC) -I $(AC_INC) -I $(BUSYWAIT_PUBLIC_INC)

INC_EL1  = -I $(VSENS_INC)/sailsw1 -I $(DDRMLST_INC) -I $(EB_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBINC_DIR)/sailsw1 -I $(PRVINC_DIR) -I $(PRVINC_DIR)/sailsw1 -I $(PRVINC_DIR)/8650 -I $(FREERTOS_INC) -I $(INC_SAIL_FREERTOS) -I $(LOGCODE_INC) -I $(INTINC)/sailsw1 -I $(IPCC_INC) -I $(CHIPINFO_INC) -I $(PMIC_INC) -I $(CPR_INC_EL2) -I $(TESTINC)/sailsw1 -I $(ELENTRY_INC) -I $(ELENTRY_INC)/sailsw1 -I $(DBG_INC) -I $(DBG_INC)/sailsw1 -I $(SLEEP_INC) -I $(SLEEP_INC)/sailsw1 -I $(BUSYWAIT_PUBLIC_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/isd)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_EL1) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
