.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/sail_diagnostics/public
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/
TIME_INC=$(SAIL_SRC_HOME)/BSP/time/public
SYSCALL_INC=$(SAIL_SRC_HOME)/BSP/el_entry/inc/sailhyp/
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/sail_diagnostics/src
SRC_HYP_C=$(SOURCE_DIR)/sailhyp/*.c

INC  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC) -I $(SYSCALL_PUB_INC)/sailhyp -I $(SYSCALL_INC) -I $(TIME_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/sail_diagnostics)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC) ;\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SRC_HYP_C) $(CC_OPTS))|| exit $$?; \
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
