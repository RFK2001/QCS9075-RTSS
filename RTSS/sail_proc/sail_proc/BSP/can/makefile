.PHONY: clean all print setup

CFLAGS += -DCAN_PLT_SAFERTOS_ENABLE

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1
FREERTOS_KERNEL_INC=$(SAIL_SRC_HOME)/FreeRTOS/kernel
STUB_DIR=$(SAIL_SRC_HOME)/BSP/can/stub
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public/sailsw1
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
TCAN1044_PUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/public/sailel1
TCAN1044_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/inc/sailel1
TCAN1044_STUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/stub
TCAN1146_PUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/public/sailel1
TCAN1146_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/inc/sailel1
TCAN1146_STUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/stub
SPI_INC=$(SAIL_SRC_HOME)/BSP/spi/public

ifeq ("$(TARGET)" , "lemans")
	PLT_DEF=CHIPINFO_FAMILY_LEMANS
	CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
	GEN_DIR=$(SAIL_SRC_HOME)/BSP/can/Gen/lemans
	TCAN1044_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/Gen/lemans
	TCAN1146_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/lemans
	CAN_INC_HW=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1/lemans
endif
ifeq ("$(TARGET)" , "monaco")
	PLT_DEF=CHIPINFO_FAMILY_MONACO
	CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8620
	GEN_DIR=$(SAIL_SRC_HOME)/BSP/can/Gen/monaco
	TCAN1044_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/Gen/monaco
	TCAN1146_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/monaco
	CAN_INC_HW=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1/monaco
endif

BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public

FDT_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/can/public/sailel1
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/can/src/sailel1
GEN_SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/can/Gen/

SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s

ifeq ("$(TARGET)" , "lemans")
GEN_SRC_C=$(GEN_SOURCE_DIR)/lemans/*.c
GEN_SRC_S=$(GEN_SOURCE_DIR)/lemans/*.s
GEN_TST_SRC_C=$(GEN_SOURCE_DIR)/Test/lemans/*.c
GEN_TST_SRC_S=$(GEN_SOURCE_DIR)/Test/lemans/*.s
endif
ifeq ("$(TARGET)" , "monaco")
GEN_SRC_C=$(GEN_SOURCE_DIR)/monaco/*.c
GEN_SRC_S=$(GEN_SOURCE_DIR)/monaco/*.s
GEN_TST_SRC_C=$(GEN_SOURCE_DIR)/Test/monaco/*.c
GEN_TST_SRC_S=$(GEN_SOURCE_DIR)/Test/monaco/*.s
endif

INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(STUB_DIR) -I $(SLEEP_INC)  -I $(SLEEP_INC)/sailsw1  -I $(CAN_INC_HW) -I $(GEN_DIR) -I $(TCAN1044_INC) -I $(TCAN1044_PUB) -I $(FDT_INC) -I $(GPIO_INC) -I $(SAIL_SRC_HOME)/BSP/clock/inc -I $(CLOCK_INC) -I $(CLOCK_INC)/sailsw1 -I $(CLOCK_INC_HW) -I $(BUSYWAIT_INC) -I $(CHIPINFO_INC) -I $(INTERRUPTS_INC) -I $(PUBLIC_INC) -I $(IPCC_INC) -I $(TCAN1146_STUB) -I $(TCAN1146_INC) -I $(TCAN1146_PUB) -I $(TCAN1044_STUB) -I $(TCAN1044_GEN) -I $(TCAN1146_GEN) -I $(SPI_INC) -I $(EVENTS_INC) -I $(FREERTOS_KERNEL_INC)/include/ 

# PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/can)

all: setup
	@if [ "$(TAG)" != "sailhyp" ]; then \
		echo $(INC) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) -D$(PLT_DEF) $(INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(GEN_TEST_SRC_C) $(GEN_SRC_C) $(GEN_TST_SRC_C) $(CC_OPTS))|| exit $$?; \
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
