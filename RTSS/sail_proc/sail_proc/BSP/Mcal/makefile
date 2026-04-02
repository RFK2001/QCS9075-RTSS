.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
MCAL_CMN_INC=$(SAIL_SRC_HOME)/BSP/Mcal/Base
DIO_INC_DIR=$(SAIL_SRC_HOME)/BSP/Mcal/Dio/Inc
DIO_SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/Mcal/Dio/Src
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
SPI_INC_DIR=$(SAIL_SRC_HOME)/BSP/Mcal/Spi/Inc
SPI_SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/Mcal/Spi/Src
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public/
ERROR_FATAL_INC=$(SAIL_SRC_HOME)/BSP/common_inc/
SPI_BSP_INC=$(SAIL_SRC_HOME)/BSP/spi/public
CFG_INC=$(SAIL_SRC_HOME)/BSP/McalCfg/Inc
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
LOGCODE_INC = $(SAIL_SRC_HOME)/BSP/LogCode/public
SRC_C=$(DIO_SOURCE_DIR)/*.c
SRC_S=$(DIO_SOURCE_DIR)/*.s 


INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(DIO_INC_DIR)  -I $(GPIO_INC) -I $(SPI_INC_DIR) -I $(LOGCODE_INC) -I $(CFG_INC) -I $(INTERRUPTS_INC)

SAILSW1_INC  = -I $(ERROR_FATAL_INC) -I $(SLEEP_INC) -I $(SLEEP_INC)/sailsw1 -I $(CMNINC) -I $(CMNINC)/8650 -I $(LOGCODE_INC) -I $(MCAL_CMN_INC) -I $(DIO_INC_DIR) -I $(SPI_BSP_INC) -I $(CFG_INC) -I $(GPIO_INC) -I $(SPI_INC_DIR)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/Mcal)

all: setup
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(SAILSW1_INC) $(INC_SAIL_SAFERTOS);\
		($(CC) $(TARGET_OPTS) $(SAILSW1_INC) $(INC_SAIL_SAFERTOS) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
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
