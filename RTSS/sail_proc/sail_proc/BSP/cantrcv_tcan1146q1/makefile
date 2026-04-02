.PHONY: clean all print setup

CFLAGS += -DCAN_PLT_SAFERTOS_ENABLE

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/inc/sailel1
STUB_DIR=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/stub
SPI_INC=$(SAIL_SRC_HOME)/BSP/spi/public
CAN_STUB_DIR=$(SAIL_SRC_HOME)/BSP/can/stub
CAN_INC_DIR=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public

ifeq ("$(TARGET)" , "lemans")
	PLT_DEF=CHIPINFO_FAMILY_LEMANS
	CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
	GEN_DIR=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/lemans
	CAN_HW_INC_DIR=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1/lemans
	SOURCE_GEN_DIR = $(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/lemans
endif
ifeq ("$(TARGET)" , "monaco")
	PLT_DEF=CHIPINFO_FAMILY_MONACO
	CLOCK_INC_HW=$(SAIL_SRC_HOME)/BSP/clock/inc/8620
	GEN_DIR=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/monaco
	CAN_HW_INC_DIR=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1/monaco
	SOURCE_GEN_DIR = $(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/monaco
endif
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public

FDT_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/public/sailel1
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/src/sailel1

SRC_C=$(SOURCE_DIR)/*.c
SRC_GEN_C=$(SOURCE_GEN_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s
SRC_GEN_S = $(SOURCE_GEN_DIR)/*.s
INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(STUB_DIR) -I$(GEN_DIR) -I $(SPI_INC) -I $(CAN_STUB_DIR) -I $(CAN_INC_DIR) -I$(CAN_HW_INC_DIR) -I $(FDT_INC) -I $(GPIO_INC) -I $(SAIL_SRC_HOME)/BSP/clock/inc -I $(CLOCK_INC) -I $(CLOCK_INC)/sailsw1 -I $(CLOCK_INC_HW) -I $(BUSYWAIT_INC) -I $(CHIPINFO_INC) -I $(INTERRUPTS_INC)/sailsw1 -I $(PUBLIC_INC) -I $(IPCC_INC)

# PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1)

all: setup
	@if [ "$(TAG)" != "sailhyp" ]; then \
		echo $(INC) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) -D$(PLT_DEF) $(INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(SRC_GEN_C) $(CC_OPTS))|| exit $$?; \
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
