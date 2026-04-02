.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
CRC_INC=$(SAIL_SRC_HOME)/BSP/crc/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
MAILBOXINT_INC=$(SAIL_SRC_HOME)/BSP/mailboxInt/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SYSCALL_HYP_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
SYSCALL_SW1_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1
SAILUPDATER_INC = $(SAIL_SRC_HOME)/BSP/sail_updater
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
 

SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/sailupdater_test/src
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I$(IPCC_INC) -I $(PUBLIC_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(SAILUPDATER_INC)/public -I $(SAILUPDATER_INC)/inc -I $(MAILBOXEXT_INC) -I $(MAILBOXINT_INC) -I $(MAILBOXLIB_INC) -I $(SYSCALL_PUB_INC) -I $(SYSCALL_HYP_INC) -I $(SYSCALL_SW1_INC) -I $(CRC_INC) -I $(CHIPINFO_INC)

PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/sail_updater)

all: setup
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && [ "$(TAG)" != "autosarsailbaremetal" ]&& echo $(PLACEMENT_TEMP) | grep -q $(TAG); then \
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
