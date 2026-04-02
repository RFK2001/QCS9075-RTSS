.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
GPT_PUBLIC = $(SAIL_SRC_HOME)/BSP/gpt/public
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SYSCALL_HYP_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
SYSCALL_SW1_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1
SPINOR_TEST_PUBLIC=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/spinor/public
OSPINOR_CMN = $(SAIL_SRC_HOME)/BSP/spinor/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/spinor_test/src
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public

SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I $(PUBLIC_INC) -I$(IPCC_INC)  -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1) -I $(GPT_PUBLIC) -I $(SYSCALL_PUB_INC) -I $(SYSCALL_SW1_INC) -I $(SPINOR_TEST_PUBLIC) -I $(OSPINOR_CMN) -I $(OSPINOR_CMN)/driver -I $(OSPINOR_CMN)/sailsw1 

PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/spinor)

all: setup
	@if [ "$(TAG)" != "sailhyp" ] ; then \
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
