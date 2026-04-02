.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/spi/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
CLOCK_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/clock/public
GPIO_PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
INTERRUPT_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public/sailsw1
LOGCODE=$(SAIL_SRC_HOME)/BSP/LogCode/public
TESTS_UT_INC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
QUP_INC=$(SAIL_SRC_HOME)/BSP/qup/public
MCAL_CMN_INC=$(SAIL_SRC_HOME)/BSP/Mcal/Base
FDT_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/spi/src/*.c
INC_DIR=$(SAIL_SRC_HOME)/BSP/spi/public
PUBLIC_INC_DIR=$(SAIL_SRC_HOME)/BSP/spi/public
SW1_INC  = -I $(IPCC_INC) -I $(QUP_INC) -I $(CMNINC) -I $(SLEEP_INC) -I $(SLEEP_INC)/sailsw1 -I $(LOGCODE) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(FDT_INC) -I $(PUBLIC_INC_DIR) -I $(MCAL_CMN_INC) -I $(INC_DIR)/8650 -I $(TESTS_UT_INC) -I $(PUBLIC_INC_DIR) -I $(CHIPINFO_INC) -I $(BUSYWAIT_INC) -I $(CLOCK_PUBLIC_INC) -I $(CLOCK_PUBLIC_INC)/sailsw1 -I $(CLOCK_PUBLIC_INC)/sailhyp -I $(GPIO_PUBLIC_INC) -I $(INTERRUPT_INC)

#PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/spi)
ifeq ("$(TARGET)" , "lemans")
    PLT_DEF=CHIPINFO_FAMILY_LEMANSAU
endif
ifeq ("$(TARGET)" , "monaco")
    PLT_DEF=CHIPINFO_FAMILY_MONACOAU    
endif

all: setup
	@if [ "$(TAG)" != "sailhyp" ]; then \
		echo $(INC) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(SW1_INC) -D$(PLT_DEF) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SOURCE_DIR) $(CC_OPTS))|| exit $$?; \
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
