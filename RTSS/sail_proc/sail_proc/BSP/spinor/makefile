.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
OSPI_PUB=$(SAIL_SRC_HOME)/BSP/spinor/public/
OSPI_CMN=$(SAIL_SRC_HOME)/BSP/spinor/public
OSPI_INC=$(SAIL_SRC_HOME)/BSP/spinor/inc/
GPT_PUB=$(SAIL_SRC_HOME)/BSP/gpt/public
OSALINC=$(SAIL_SRC_HOME)/BSP/osal/public
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/
SYSCALL_SW_INC = $(SAIL_SRC_HOME)/BSP/el_entry/public/
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public

SRC_C=$(SAIL_SRC_HOME)/BSP/spinor/src/sailhyp/*.c
SRC_EL1_C=$(SAIL_SRC_HOME)/BSP/spinor/src/sailsw1/*.c

DRIVER_C=$(SAIL_SRC_HOME)/BSP/spinor/src/driver/*.c
EL1_INC = -I $(CMNINC) -I $(IPCC_INC) -I $(CMNINC)/8650 -I $(OSPI_CMN) -I $(OSPI_PUB)/sailsw1 -I $(OSALINC) -I $(OSPI_INC)/sailsw1 -I $(SYSCALL_SW_INC)/sailsw1 -I $(SYSCALL_PUB_INC)

SPINOR_DRIVER_PUB=$(SAIL_SRC_HOME)/BSP/spinor/public/driver
SPINOR_DRIVER_INC=$(SAIL_SRC_HOME)/BSP/spinor/inc/driver
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
FDT_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
ifeq ("$(TARGET)" , "lemans")
	CLOCK_INC_TARGET=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
endif
ifeq ("$(TARGET)" , "monaco")
	CLOCK_INC_TARGET=$(SAIL_SRC_HOME)/BSP/clock/inc/8620
endif
CLOCK_INC_PUBLIC=$(SAIL_SRC_HOME)/BSP/clock/public
CRC_INC=$(SAIL_SRC_HOME)/BSP/crc/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
EL2_INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(GPT_PUB) -I $(OSPI_CMN) -I $(SPINOR_DRIVER_PUB) -I $(SPINOR_DRIVER_INC) -I $(SPINOR_DRIVER_INC)/8650 -I $(OSPI_PUB)/sailhyp -I $(OSPI_INC)/sailhyp -I $(GPIO_INC) -I $(CHIPINFO_INC) -I$(FDT_INC) -I $(BUSYWAIT_INC) -I$(CRC_INC) -I$(SYSCALL_PUB_INC) -I$(SYSCALL_SW_INC)/sailhyp -I $(CLOCK_INC) -I $(CLOCK_INC_TARGET) -I $(CLOCK_INC_PUBLIC) -I $(SLEEP_INC) -I $(SLEEP_INC)/sailhyp

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/spinor)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(EL2_INC);\
		($(CC) $(TARGET_OPTS) $(EL2_INC) $(CC_SRC_OPTS) $(SRC_C) $(DRIVER_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(EL2_INC);\
		($(CC) $(TARGET_OPTS) -DENB_TRAP_CALL $(EL2_INC) $(CC_SRC_OPTS) $(SRC_C) $(DRIVER_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(EL1_INC);\
		($(CC) $(TARGET_OPTS) -DENB_TRAP_CALL $(EL1_INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
