.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
INC=$(SAIL_SRC_HOME)/BSP/sleep/inc
MAILBOX_LIB=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
MAILBOX_INT=$(SAIL_SRC_HOME)/BSP/mailboxInt/public
PWR_CNTRL=$(SAIL_SRC_HOME)/BSP/pwr_controller/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
PMIC_INC=$(SAIL_SRC_HOME)/BSP/pmic/public
#WDOG_INC=$(SAIL_SRC_HOME)/BSP/wdt/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
FUSA_INC=$(SAIL_SRC_HOME)/BSP/fusa/public
UART_INC=$(SAIL_SRC_HOME)/BSP/uart/public
PSAIL_INC=$(SAIL_SRC_HOME)/BSP/psail/public
PSAIL_HWIO_INC=$(SAIL_SRC_HOME)/BSP/psail/inc/8650
CHIPINFO=$(SAIL_SRC_HOME)/BSP/chipinfo/public
CVSOC_SMERR_INC=$(SAIL_SRC_HOME)/BSP/cvsoc_smerr/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
EL_ENTRY_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd
SYSCALL_PUB_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public
SYSCALL_HYP_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailhyp
SYSCALL_SW1_INC=$(SAIL_SRC_HOME)/BSP/el_entry/public/sailsw1
OSAL_INC=$(SAIL_SRC_HOME)/BSP/osal/public
I2C_INC=$(SAIL_SRC_HOME)/BSP/i2c/public
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
ifeq ("$(TARGET)" , "lemans")
	INC_TARGET=$(SAIL_SRC_HOME)/BSP/sleep/inc/8650
else ifeq ("$(TARGET)" , "monaco")
	INC_TARGET=$(SAIL_SRC_HOME)/BSP/sleep/inc/monaco		
endif


SRC_C=$(SAIL_SRC_HOME)/BSP/sleep/src/sailhyp/*.c
SRC_S=$(SAIL_SRC_HOME)/BSP/sleep/src/sailhyp/*.s

SRC_EL1_C=$(SAIL_SRC_HOME)/BSP/sleep/src/sailsw1/*.c
SRC_EL1_S=$(SAIL_SRC_HOME)/BSP/sleep/src/sailsw1/*.s

INC_HYP =  -I $(CMNINC) \
		   -I $(CMNINC)/8650 \
		   -I $(PUBLIC_INC)/sailhyp \
		   -I $(PUBLIC_INC) \
		   -I $(INC) \
		   -I $(INC_TARGET) \
		   -I $(BUSYWAIT_INC)\
		   -I $(PWR_CNTRL) \
		   -I $(PWR_CNTRL)/sailhyp \
		   -I $(WDOG_INC)/sailhyp \
		   -I $(CLOCK_INC)\
		   -I $(SYSCALL_PUB_INC)\
		   -I $(SYSCALL_HYP_INC)\

INC_SW1  = -I $(CMNINC) \
		   -I $(CMNINC)/8650 \
		   -I $(PUBLIC_INC)/sailsw1 \
		   -I $(PUBLIC_INC) -I$(IPCC_INC)\
		   -I $(SAFERTOS_INC) \
		   -I $(INC_SAIL_FREERTOS) \
		   -I $(MAILBOX_LIB) \
		   -I $(WDOG_INC)/sailsw1 \
		   -I $(INC) \
		   -I $(INC_TARGET)\
		   -I $(PWR_CNTRL) \
		   -I $(PMIC_INC)\
		   -I $(PMIC_INC)/sailsw1 \
		   -I $(BUSYWAIT_INC)\
		   -I $(PWR_CNTRL)/sailsw1 \
		   -I $(CLOCK_INC)\
		   -I $(FUSA_INC)\
		   -I $(UART_INC)\
		   -I $(PSAIL_INC)/sailhyp \
		   -I $(PSAIL_INC)/sailsw1 \
		   -I $(PSAIL_HWIO_INC)\
		   -I $(CVSOC_SMERR_INC)\
		   -I $(CHIPINFO)\
		   -I $(IPCC_INC)\
		   -I $(MAILBOX_INT)\
		   -I $(GPIO_INC)\
		   -I $(MAILBOXEXT_INC)\
		   -I $(EL_ENTRY_INC)/sailhyp \
		   -I $(EL_ENTRY_INC)/sailsw1 \
		   -I $(SYSCALL_PUB_INC)\
		   -I $(SYSCALL_SW1_INC)\
		   -I $(ISD_INC)/public/sailsw1\
		   -I $(ISD_INC)/inc\
		   -I $(ISD_INC)/inc/sailsw1\
		   -I $(OSAL_INC)\
		   -I $(I2C_INC)\

PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/sleep)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_HYP);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_HYP);\
		($(CC) $(TARGET_OPTS) $(INC_HYP) $(CC_SRC_OPTS) $(SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" != "sailhyp" ]; then \
		echo $(INC_SW1);\
		($(CC) $(TARGET_OPTS) $(INC_SW1) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
