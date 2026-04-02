.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/bist/inc
BIST_COMMON_INC=$(SAIL_SRC_HOME)/BSP/bist/inc/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/bist/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
CLOCK_INTERNAL_INC=$(SAIL_SRC_HOME)/BSP/clock/inc
EL_ENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
EL_ENTRY_HYP_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
ifeq ("$(TARGET)" , "lemans")
	CLOCK_INTERNAL_INC_TARGET=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
	BIST_INTERNAL_INC_TARGET=$(SAIL_SRC_HOME)/BSP/bist/inc/8650
	CMNINC_TARGET=$(SAIL_SRC_HOME)/BSP/common_inc/8650
	CLK_INC=$(SAIL_SRC_HOME)/BSP/clock/inc/8650
else ifeq ("$(TARGET)" , "monaco")
	CLOCK_INTERNAL_INC_TARGET=$(SAIL_SRC_HOME)/BSP/clock/inc/8620
	BIST_INTERNAL_INC_TARGET=$(SAIL_SRC_HOME)/BSP/bist/inc/8620
	CMNINC_TARGET=$(SAIL_SRC_HOME)/BSP/common_inc/monaco
	CLK_INC=$(SAIL_SRC_HOME)/BSP/clock/inc/8620
endif
TIME_INC=$(SAIL_SRC_HOME)/BSP/time/public
# WDT_INC=$(SAIL_SRC_HOME)/BSP/wdt/public/sailhyp
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
FDT_PUBLIC=$(SAIL_SRC_HOME)/BSP/fdt/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/bist/src
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/inc/8650


SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s
INC  = -I $(FDT_PUBLIC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(CLK_INC) -I $(ISD_INC) -I $(INC_DIR) -I $(INC_DIR)/8650 -I $(PUBLIC_INC) -I $(CLOCK_INC) -I $(CLOCK_INC)/sailhyp -I $(TIME_INC) -I $(CHIPINFO_INC) -I $(CLOCK_INTERNAL_INC) -I $(CLOCK_INTERNAL_INC_TARGET) -I $(BIST_COMMON_INC) -I $(BIST_INTERNAL_INC_TARGET) -I $(CMNINC_TARGET) -I$(EL_ENTRY_INC) -I$(EL_ENTRY_HYP_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/bist)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
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
