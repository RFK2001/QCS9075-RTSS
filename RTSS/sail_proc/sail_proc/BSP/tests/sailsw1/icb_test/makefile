.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
WDT_INC = $(SAIL_SRC_HOME)/BSP/wdt
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
MAILBOXINT_INC=$(SAIL_SRC_HOME)/BSP/mailboxInt/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
WDT_INC = $(SAIL_SRC_HOME)/BSP/wdt
ICB_INC=$(SAIL_SRC_HOME)/BSP/icb
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
WDT_TEST=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/wdt_test/public
ICB_TEST=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/icb_test/public
FUSA_INC = $(SAIL_SRC_HOME)/BSP/fusa/public
MONITORINTR_INC = $(SAIL_SRC_HOME)/BSP/monitor/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
 

SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/icb_test/src

SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I$(IPCC_INC) -I $(PUBLIC_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(WDT_INC)/public/sailsw1 -I $(WDT_INC)/inc/8650 -I $(CLOCK_INC) -I $(MAILBOXEXT_INC) -I $(MAILBOXINT_INC) -I $(MAILBOXLIB_INC) -I $(BUSYWAIT_INC) -I $(ICB_INC)/public -I $(ICB_INC)/inc -I $(ICB_INC)/inc/8650 -I $(CHIPINFO_INC) -I $(WDT_TEST) -I $(ICB_TEST) -I $(FUSA_INC) -I $(MONITORINTR_INC)

all: setup
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && [ "$(TAG)" != "autosarsailbaremetal" ]; then \
		echo $(SAILSW1_INC) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(SAILSW1_INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS)) || exit $$?; \
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
