.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
GPT_DRV_INC=$(SAIL_SRC_HOME)/BSP/gpt_timer/inc
#GPT_CFG_DRV_INC=$(SAIL_SRC_HOME)/BSP/gpt_timer/cfg/inc
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
SAIL_RTOS_INC=$(SAIL_SRC_HOME)/BSP/sailfreertos/public/
MCAL_BASE=$(SAIL_SRC_HOME)/BSP/Mcal/Base/
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/gpt_test/src

SAFERTOS_KERNEL_INC=$(SAIL_SRC_HOME)/FreeRTOS/kernel
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
#GPT_TEST_CFG_INC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/gpt_test/public/
GPT_INC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/gpt_test/public
SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1  -I $(IPCC_INC) -I $(GPT_DRV_INC) -I $(GPT_INC)  -I $(PUBLIC_INC) -I $(MCAL_BASE)  -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(GPT_CFG_INC) -I $(SAIL_RTOS_INC)


PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/Mcal)

all: setup
	@if [ "$(TAG)" != "sailhyp" ]; then  \
		echo $(SAILSW1_INC) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(SAILSW1_INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS)) || exit $$?; \
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
