.PHONY: clean all print setup

EL_ENTRY_DIR=$(SAIL_SRC_HOME)/BSP/el_entry/public
CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/icb/inc
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
FREERTOS_INC=$(SAIL_SRC_HOME)/BSP/sailfreertos/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
INTR_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public/sailsw1
ifeq ("$(TARGET)" , "lemans")
	CLOCK_TARGET=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
endif
ifeq ("$(TARGET)" , "monaco")
	CLOCK_TARGET=$(SAIL_SRC_HOME)/BSP/clock/inc/8620
endif
GIC_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/icb/public/sailsw1
SPINOR_PUBLIC=$(SAIL_SRC_HOME)/BSP/spinor/public
SRC_C=$(SAIL_SRC_HOME)/BSP/icb/src/sailhyp/*.c $(SAIL_SRC_HOME)/BSP/icb/src/sailhyp/8650/*.c
SRC_EL1_C=$(SAIL_SRC_HOME)/BSP/icb/src/sailsw1/*.c
INC_HYP  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR)/sailhyp -I $(INC_DIR)/sailhyp/8650 \
           -I $(PUBLIC_INC) -I $(CHIPINFO_INC) -I $(CLOCK_INC) \
           -I $(GIC_INC) -I $(FUSA_INC_HYP) \
           -I $(SPINOR_PUBLIC)/sailhyp -I $(SPINOR_PUBLIC) \
           -I $(BUSYWAIT_INC) -I $(CLOCK_TARGET) -I $(EL_ENTRY_DIR) -I $(EL_ENTRY_DIR)/sailhyp
INC_EL1  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(INC_DIR)/8650 \
           -I $(PUBLIC_INC) -I $(CHIPINFO_INC) -I $(CLOCK_INC) -I $(GIC_INC) \
           -I $(SPINOR_PUBLIC)/sailsw1  -I $(INTR_INC) -I$(IPCC_INC)\
           -I $(SPINOR_PUBLIC) -I $(CLOCK_TARGET) -I $(EL_ENTRY_DIR) -I $(EL_ENTRY_DIR)/sailsw1

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/icb)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_HYP);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] ; then \
		echo $(INC_EL1) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
