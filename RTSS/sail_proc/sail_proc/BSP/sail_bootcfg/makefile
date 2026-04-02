.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/sail_bootcfg/public
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/
SYSCALL_INC=$(SAIL_SRC_HOME)/BSP/el_entry/inc/sailhyp/
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/sail_bootcfg/src
SRC_HYP_C=$(SOURCE_DIR)/sailhyp/*.c
SRC_SW1_C=$(SOURCE_DIR)/sailsw1/*.c

INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC) -I $(SYSCALL_PUB_INC)/sailhyp -I $(SYSCALL_INC) -I $(SYSCALL_PUB_INC)

SAILSW1_INC = -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC) -I $(SYSCALL_PUB_INC)/sailsw1 -I $(SYSCALL_INC) -I $(SYSCALL_PUB_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/sail_bootcfg)

all: setup
	@if [ "$(TAG)" = "sailhyp" ]; then \
		echo $(INC) ;\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_HYP_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ]; then \
		echo $(SAILSW1_INC) ;\
		($(CC) $(TARGET_OPTS) $(SAILSW1_INC) $(CC_SRC_OPTS) $(SRC_SW1_C) $(CC_OPTS))|| exit $$?; \
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
