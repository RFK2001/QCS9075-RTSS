.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/gpt/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/gpt/src
SRC_C=$(SOURCE_DIR)/*.c
SRC_EL1_C=$(SOURCE_DIR)/gpt_p1.c
INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/gpt)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS)) || exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS)) || exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS)) || exit $$?; \
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
