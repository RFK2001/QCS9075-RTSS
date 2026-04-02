.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/mailboxExt/inc
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
LOGCODEINC=$(SAIL_SRC_HOME)/BSP/LogCode/public
TESTS_UT_INC=$(SAIL_SRC_HOME)/BSP/tests
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/mailboxExt/src
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s
INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(LOGCODEINC) -I $(PUBLIC_INC) -I $(INTERRUPTS_INC)/sailhyp -I $(IPCC_INC) -I $(BUSYWAIT_INC) -I $(MAILBOXLIB_INC) -I $(TESTS_UT_INC)
INC_EL1  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(LOGCODEINC) -I $(PUBLIC_INC) -I $(INTERRUPTS_INC)/sailsw1 -I $(IPCC_INC) -I $(BUSYWAIT_INC) -I $(MAILBOXLIB_INC) -I $(TESTS_UT_INC)
PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/mailboxExt)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_EL1);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS) )|| exit $$?; \
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
