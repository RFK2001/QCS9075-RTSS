.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/pmic/inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/pmic/public
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/pmic/src
I2C_INC=$(SAIL_SRC_HOME)/BSP/i2c/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
CRC_INC=$(SAIL_SRC_HOME)/BSP/crc/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
CPR_INC=$(SAIL_SRC_HOME)/BSP/cpr/public
CRASHDBG_INC=$(SAIL_SRC_HOME)/BSP/crashdbg/public
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SYSCALL_HYP_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
SYSCALL_SW1_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1
MAILBOX_EXT=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
MAILBOX_LIB=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
# FUSA_INC=$(SAIL_SRC_HOME)/BSP/fusa/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
SPINOR_PUBLIC=$(SAIL_SRC_HOME)/BSP/spinor/public
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep
BIST_INC=$(SAIL_SRC_HOME)/BSP/bist/public
INC_BSP_SAFERTOS=$(SAIL_SRC_HOME)/BSP/sailfreertos/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
SRC_HYP_C=$(SOURCE_DIR)/sailhyp/*.c
SRC_HYP_S=$(SOURCE_DIR)/sailhyp/*.s
SRC_SW1_C=$(SOURCE_DIR)/sailsw1/*.c
SRC_SW1_S=$(SOURCE_DIR)/sailsw1/*.s

INC_HYP = -I $(CMNINC) \
       -I $(CMNINC)/8650 \
       -I $(INC_DIR)/sailhyp \
       -I $(INC_DIR)/sailhyp/8650 \
       -I $(I2C_INC) \
       -I $(BUSYWAIT_INC) \
       -I $(GPIO_INC) \
       -I $(CRC_INC) \
       -I $(CHIPINFO_INC) \
       -I $(CRASHDBG_INC) \
       -I $(CRASHDBG_INC)/sailhyp \
       -I $(PUBLIC_INC) \
       -I $(PUBLIC_INC)/sailhyp \
       -I $(SYSCALL_PUB_INC) \
       -I $(SYSCALL_HYP_INC) \
       -I $(BIST_INC)	   

INC_SW1 = -I $(CMNINC) \
       -I $(CMNINC)/8650 \
       -I $(CPR_INC) \
       -I $(INC_DIR)/sailsw1 \
       -I $(PUBLIC_INC) \
       -I $(INC_DIR)/sailhyp \
       -I $(INC_DIR)/sailhyp/8650 \
       -I $(I2C_INC) -I $(INC_BSP_SAFERTOS) -I $(IPCC_INC)\
       -I $(SYSCALL_PUB_INC) \
       -I $(SYSCALL_SW1_INC) \
       -I $(GPIO_INC) \
       -I $(MAILBOX_EXT)\
       -I $(MAILBOX_LIB)\
       -I $(CLOCK_INC)\
       -I $(CHIPINFO_INC)\
       -I $(PUBLIC_INC)/sailsw1 \
       -I $(SPINOR_PUBLIC)/sailsw1 \
       -I $(SPINOR_PUBLIC)\
       -I $(SLEEP_INC)/public\
       -I $(SLEEP_INC)/public/sailsw1 \


PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/pmic)

all: setup
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_HYP);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_HYP_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ]; then \
		echo $(INC_SW1);\
		($(CC) $(TARGET_OPTS) $(INC_SW1) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_SW1_C) $(CC_OPTS))|| exit $$?; \
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
