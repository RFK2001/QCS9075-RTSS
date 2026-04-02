.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
INTERRUPTS_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
ERR_INC=$(SAIL_SRC_HOME)/BSP/interrupts/inc
FDT_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
BSP_MCAL_TMP_INC=$(SAIL_SRC_HOME)/BSP/Mcal/Base

INC_EL2_DIR=$(SAIL_SRC_HOME)/BSP/gpt_timer/inc/sailhyp/
INC_EL1_DIR=$(SAIL_SRC_HOME)/BSP/gpt_timer/inc/sailsw1/

CFG_ELX_INC=$(SAIL_SRC_HOME)/BSP/gpt_timer/cfg/inc/

INC_ELX_DIR=$(SAIL_SRC_HOME)/BSP/gpt_timer/inc/

CFG_ELX_SRC=$(SAIL_SRC_HOME)/BSP/gpt_timer/cfg/src/*.c

SRC_EL2_C=$(SAIL_SRC_HOME)/BSP/gpt_timer/src/sailhyp/*.c
SRC_EL2_S=$(SAIL_SRC_HOME)/BSP/gpt_timer/src/sailhyp/*.s

SRC_ELX_C=$(SAIL_SRC_HOME)/BSP/gpt_timer/src/*.c
SRC_ELX_S=$(SAIL_SRC_HOME)/BSP/gpt_timer/src/*.s

SRC_EL1_C=$(SAIL_SRC_HOME)/BSP/gpt_timer/src/sailsw1/*.c
SRC_EL1_S=$(SAIL_SRC_HOME)/BSP/gpt_timer/src/sailsw1/*.s

#GPT_CC_OPT= -Wall -Wextra -Wpedantic -Werror -Wstrict-prototypes -Wconversion -Wsign-conversion -Wnull-dereference -Wshadow -Wformat=2 
#GPT_CC_OPT=-Wall -Wstrict-prototypes -Wconversion -Wsign-conversion -Wnull-dereference -Wformat=2

INC_HYP  = -I $(ERR_INC) -I $(BSP_MCAL_TMP_INC) -I $(CFG_ELX_INC) -I $(INC_EL2_DIR) -I $(INC_ELX_DIR) -I $(CMNINC) -I $(CMNINC)/8650 -I $(CLOCK_INC) -I $(FDT_INC) -I $(INTERRUPTS_INC)/sailhyp -I $(BUSYWAIT_INC) -I $(SLEEP_INC) -I $(SLEEP_INC)/sailhyp

INC_SW1  = -I $(ERR_INC) -I$(IPCC_INC) -I $(BSP_MCAL_TMP_INC) -I $(CFG_ELX_INC) -I $(INC_EL1_DIR) -I $(INC_ELX_DIR) -I $(CMNINC) -I $(CMNINC)/8650 -I $(FDT_INC) -I $(CLOCK_INC) -I $(BUSYWAIT_INC) -I $(INTERRUPTS_INC)/sailsw1 -I $(SLEEP_INC) -I $(SLEEP_INC)/sailsw1 

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/gpt_timer)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_EL2_C) $(SRC_ELX_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_SW1) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(INC_SW1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(CFG_ELX_SRC) $(SRC_EL1_C) $(SRC_ELX_C) $(CC_OPTS) $(GPT_CC_OPT))|| exit $$?; \
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
