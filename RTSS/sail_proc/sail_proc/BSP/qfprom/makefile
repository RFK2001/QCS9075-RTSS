.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/qfprom/public
SYSCALL_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
INC_DIR=$(SAIL_SRC_HOME)/BSP/qfprom/inc
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
SAILHYP_SRC=$(SAIL_SRC_HOME)/BSP/qfprom/src/sailhyp

ifeq ($(TARGET),monaco)
	TARGET_SRC=$(SAILHYP_SRC)/monaco/*.c
	TARGET_INC=$(INC_DIR)/monaco
else
	TARGET_SRC=$(SAILHYP_SRC)/8650/*.c
	TARGET_INC=$(INC_DIR)/8650
endif

QFPROM_COMPILE_OPTS=$(TARGET_OPTS) -Wall -Werror

SRC_C = $(SAILHYP_SRC)/*.c  $(TARGET_SRC)

INC_HYP  = -I $(CMNINC) -I $(CMNINC)/8650 -I $(INC_DIR) -I $(SYSCALL_INC) -I $(SYSCALL_INC)/sailhyp -I $(TARGET_INC) -I $(PUBLIC_INC)  -I $(CLOCK_INC)

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/qfprom)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(QFPROM_COMPILE_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
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
