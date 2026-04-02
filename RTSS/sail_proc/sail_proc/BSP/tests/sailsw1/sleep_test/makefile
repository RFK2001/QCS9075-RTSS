.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
SLEEP1_INC=$(SAIL_SRC_HOME)/BSP/sleep
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SYSCALL_HYP_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
SYSCALL_SW1_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
PWR_CONTROLLER_INC=$(SAIL_SRC_HOME)/BSP/pwr_controller
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/sleep_test/src
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I $(IPCC_INC) -I $(SLEEP_INC) -I $(SLEEP1_INC)/inc -I $(SLEEP_INC)/sailsw1 -I $(PUBLIC_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1)  -I $(SYSCALL_PUB_INC) -I $(SYSCALL_SW1_INC) -I $(SLEEP_INC)/inc -I $(SLEEP_INC)/public -I $(SLEEP_INC)/public/sailsw1 -I $(PWR_CONTROLLER_INC)/inc/8650 -I $(PWR_CONTROLLER_INC)/public -I $(PWR_CONTROLLER_INC)/public/sailsw1


all: setup
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && [ "$(TAG)" != "autosarsailbaremetal" ]; then \
               echo $(SAILSW1_INC) $(INC_SAIL_FREERTOS);\
               ($(CC) $(TARGET_OPTS) $(SAILSW1_INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(SAILVSENS_TESTEN_OPTION) $(CC_OPTS)) || exit $$?; \
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
