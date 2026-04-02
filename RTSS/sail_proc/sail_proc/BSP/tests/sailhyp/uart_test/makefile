.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
TEST_INC=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailhyp
UART_INC=$(SAIL_SRC_HOME)/BSP/uart/inc
UART_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/uart/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SYSCALL_HYP_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
ELENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailhyp/uart_test/src

SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


INC  =  -I $(PUBLIC_INC)/sailhyp -I $(PUBLIC_INC) -I $(TEST_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(UART_PUBLIC_INC) -I $(UART_INC) -I $(BUSYWAIT_INC)  -I $(SYSCALL_PUB_INC) -I $(SYSCALL_HYP_INC) -I $(ELENTRY_INC)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] ; then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(TARGET_OPTS) $(INC_SAIL_FREERTOS) $(INC) $(SRC_C) $(CC_OPTS)) || exit $$?; \
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
