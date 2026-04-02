.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc

TIME_INC=$(SAIL_SRC_HOME)/BSP/time/public

PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/fdt/src
INC_DIR=$(SAIL_SRC_HOME)/BSP/fdt/inc
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s
INC  = -I $(PUBLIC_INC) -I $(INC_DIR) -I $(CMNINC) -I $(CMNINC)/8650 -I $(TIME_INC) 

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/fdt)

all: setup
	if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC); \
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS) -DSAILEL2) || exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
	   	mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC); \
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS) -DSAILEL2) || exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
	   	mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	elif [ "$(IMAGE_RTOS)" != "sailhyp" ] &&echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC); \
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS) -DSAILSW1) || exit $$?; \
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
