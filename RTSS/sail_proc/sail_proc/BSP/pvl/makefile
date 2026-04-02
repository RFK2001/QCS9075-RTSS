.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
BUSYWAIT_INC_DIR=$(SAIL_SRC_HOME)/BSP/time/public
SPINOR_HYP=$(SAIL_SRC_HOME)/BSP/spinor/public/sailhyp
SPINOR_DRIVER=$(SAIL_SRC_HOME)/BSP/spinor/public/driver
SPINOR_PUBLIC=$(SAIL_SRC_HOME)/BSP/spinor/public
UARTINC=$(SAIL_SRC_HOME)/BSP/uart/public
ELENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
TIME_INC=$(SAIL_SRC_HOME)/BSP/time/public
INC_DIR=$(SAIL_SRC_HOME)/BSP/pvl/inc/
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/pvl/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/pvl/src
SRC_C=$(SOURCE_DIR)/*.c
XBL_PUBLIC=$(SAIL_SRC_HOME)/BSP/xbl/public
BOOT_PUBLIC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
GPT_INC=$(SAIL_SRC_HOME)/BSP/gpt/public

INC  = -I $(PUBLIC_INC) -I $(ELENTRY_INC) -I $(TIME_INC) -I $(INC_DIR) -I $(CMNINC) -I $(CMNINC)/8650 -I $(UARTINC) -I $(BUSYWAIT_INC_DIR) -I $(SPINOR_HYP) -I $(SPINOR_DRIVER) -I $(SPINOR_PUBLIC) -I $(XBL_PUBLIC) -I $(BOOT_PUBLIC) -I $(GPT_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/pvl)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS)) || exit $$?; \
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
