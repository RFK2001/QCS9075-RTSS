.PHONY: clean all print setup


SAILVSENS_TESTEN_OPTION=-DVSENS_APT_DEBUG
CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
UART_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/uart/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
SYSCALL_SW1_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1
FREERTOS_PRV=$(SAIL_SRC_HOME)/FreeRTOS/kernel/include
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/public
PORTABLE_INC=$(SAIL_SRC_HOME)/FreeRTOS/portable/include
SPI_INC=$(SAIL_SRC_HOME)/BSP/spi/public
SPI_TEST_INC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/spi_test/public/
ELENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
VERSION_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
TEST_PUBLIC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/tests/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/tests/src
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I $(PUBLIC_INC) -I $(CMNINC) -I $(PORTABLE_INC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(UART_PUBLIC_INC) -I $(IPCC_INC)  -I $(GPIO_INC) -I $(CHIPINFO_INC) -I $(BUSYWAIT_INC) -I $(CLOCK_INC) -I $(SYSCALL_SW1_INC) -I $(SM_PUBLIC_INC)  -I $(FREERTOS_PRV) -I $(ISD_INC)/sailsw1  -I $(SPI_INC)  -I $(SPI_TEST_INC) -I $(UART_INC) -I $(ELENTRY_INC) -I $(ELENTRY_INC)/sailsw1 -I $(VERSION_INC) -I $(TEST_PUBLIC) -I $(ISD_INC)

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
