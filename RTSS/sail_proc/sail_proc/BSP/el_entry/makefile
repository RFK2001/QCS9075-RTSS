.PHONY: clean all print setup

CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
INC_DIR=$(SAIL_SRC_HOME)/BSP/el_entry
GPIO_INC=$(SAIL_SRC_HOME)/BSP/gpio/public
CHIPINFO_INC=$(SAIL_SRC_HOME)/BSP/chipinfo/public
BUSYWAIT_INC=$(SAIL_SRC_HOME)/BSP/time/public
CLOCK_INC=$(SAIL_SRC_HOME)/BSP/clock/public
TESTS_INC=$(SAIL_SRC_HOME)/BSP/tests
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
ICB_INC=$(SAIL_SRC_HOME)/BSP/icb/public/sailsw1
GIC_INC=$(SAIL_SRC_HOME)/BSP/interrupts/public
CAN_INC=$(SAIL_SRC_HOME)/BSP/can/public
WDT_INC=$(SAIL_SRC_HOME)/BSP/wdt/public/
I2C_INC=$(SAIL_SRC_HOME)/BSP/i2c/public
SPI_INC=$(SAIL_SRC_HOME)/BSP/spi/public
DBG_INC=$(SAIL_SRC_HOME)/BSP/crashdbg/public
LOGCODE_INC = $(SAIL_SRC_HOME)/BSP/LogCode/public
ISD_INC=$(SAIL_SRC_HOME)/BSP/isd/public/
FUSA_INC=$(SAIL_SRC_HOME)/BSP/fusa/public
AC_INC=$(SAIL_SRC_HOME)/BSP/security/accesscontrol/common/public
HWKM_INC=$(SAIL_SRC_HOME)/BSP/security/hwkm/public
MPU_INC=$(SAIL_SRC_HOME)/BSP/security/mpu/public
UART_INC=$(SAIL_SRC_HOME)/BSP/uart/public
TSENS_INC=$(SAIL_SRC_HOME)/BSP/tsens/public
SECBOOT_INC=$(SAIL_SRC_HOME)/BSP/security/sail_auth/sail_sec/inc
PWR_CONTROLLER_INC = $(SAIL_SRC_HOME)/BSP/pwr_controller/public
PWR_CONTROLLER_HYP_INC = $(SAIL_SRC_HOME)/BSP/pwr_controller/public/sailhyp
PWR_CONTROLLER_SW1_INC = $(SAIL_SRC_HOME)/BSP/pwr_controller/public/sailsw1
SAIL_DIAGNOSTICS_INC = $(SAIL_SRC_HOME)/BSP/sail_diagnostics/public
SAILHEAP=$(SAIL_SRC_HOME)/BSP/sailheap/public
PMIC_INC=$(SAIL_SRC_HOME)/BSP/pmic/public
PRNG_FIPS_INC=$(SAIL_SRC_HOME)/BSP/security/prng_fips_hybrid/public
CPR_INC=$(SAIL_SRC_HOME)/BSP/cpr/public
TGB_INC=$(SAIL_SRC_HOME)/BSP/trusens/public
CRC_INC=$(SAIL_SRC_HOME)/BSP/crc/public
SPINOR_INC=$(SAIL_SRC_HOME)/BSP/spinor/public
XBL_INC=$(SAIL_SRC_HOME)/BSP/xbl/public
BIST_INC=$(SAIL_SRC_HOME)/BSP/bist/public



MCAL_CMN_INC=$(SAIL_SRC_HOME)/BSP/Mcal/Base




MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
MAILBOXLIB_INC=$(SAIL_SRC_HOME)/BSP/mailboxLib/public
SAILUPDATER_INC=$(SAIL_SRC_HOME)/BSP/sail_updater/public
VSENS_INC=$(SAIL_SRC_HOME)/BSP/vsens/public/sailhyp
FDT_PUBLIC=$(SAIL_SRC_HOME)/BSP/fdt/public
TEST_SW1_INC=$(SAIL_SRC_HOME)/BSP/tests

TCAN1146_PUB_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/public/sailel1
TCAN1146_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/inc/sailel1
TCAN1146_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/Gen/lemans
TCAN1146_STUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1146q1/stub
CAN_INC=$(SAIL_SRC_HOME)/BSP/can/inc/sailel1
CAN_STUB_INC=$(SAIL_SRC_HOME)/BSP/can/stub
CAN_GEN_INC=$(SAIL_SRC_HOME)/BSP/can/Gen/lemans
TCAN1044_PUB_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/public/sailel1
TCAN1044_INC=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/inc/sailel1
TCAN1044_GEN=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/Gen/lemans
TCAN1044_STUB=$(SAIL_SRC_HOME)/BSP/cantrcv_tcan1044q1/stub
SLEEP_INC=$(SAIL_SRC_HOME)/BSP/sleep/public
PMU_INC=$(SAIL_SRC_HOME)/BSP/pmu/public
PVL_INC=$(SAIL_SRC_HOME)/BSP/pvl/public
SAIL_FS_PUB=$(SAIL_SRC_HOME)/BSP/sail_fs/public
DISPATCHER_INC=$(SAIL_SRC_HOME)/BSP/dispatcher/public
MAILBOXEXT_INC=$(SAIL_SRC_HOME)/BSP/mailboxExt/public
CRYPTO_INC=$(SAIL_SRC_HOME)/BSP/security/uclib/api/uclib
SECURE_STORAGE_COMMNON_INC=$(SAIL_SRC_HOME)/BSP/security/secure_storage/public
SECURE_STORAGE_EL2_INC=$(SAIL_SRC_HOME)/BSP/security/secure_storage/public/el2
SECURE_STORAGE_CFG_INC=$(SAIL_SRC_HOME)/BSP/security/secure_storage/cfg
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/el_entry/src
CDT_INC=$(SAIL_SRC_HOME)/BSP/cdt/public
SRC_C=$(SOURCE_DIR)/sailhyp/*.c
SRC_EL1_C=$(SOURCE_DIR)/sailsw1/*.c
SAILHYP_SRC_C=$(SOURCE_DIR)/sailhyp/8650/boot_config.c  $(SRC_C)

INC  = -I $(VSENS_INC) -I $(CRC_INC) -I $(CDT_INC) -I $(SAILHEAP) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PVL_INC) -I $(LOGCODE_INC) -I $(INC_DIR)/inc/sailhyp -I $(SAIL_DIAGNOSTICS_INC) -I $(INC_DIR)/public -I $(INC_DIR)/public/sailhyp -I $(GPIO_INC) -I $(CHIPINFO_INC) -I $(BUSYWAIT_INC) -I $(PWR_CONTROLLER_INC) -I $(PWR_CONTROLLER_HYP_INC) -I $(CLOCK_INC) -I $(TESTS_INC)/public/sailhyp -I $(IPCC_INC) -I $(GIC_INC)/sailhyp -I $(CAN_INC) -I $(I2C_INC) -I $(SPI_INC)/sailhyp -I $(DBG_INC) -I $(ISD_INC)/sailhyp -I $(FUSA_INC) -I $(AC_INC) -I$(MPU_INC) -I $(HWKM_INC) -I $(WDT_INC)/sailhyp -I $(UART_INC) -I $(TSENS_INC)/sailhyp -I $(TSENS_INC) -I $(SPINOR_INC) -I $(SPINOR_INC)/sailhyp -I $(PMIC_INC) -I $(SECBOOT_INC) -I $(PRNG_FIPS_INC) -I $(CPR_INC) -I $(TGB_INC) -I $(TGB_INC)/sailhyp -I $(XBL_INC) -I $(XBL_INC)/sailhyp -I $(BIST_INC) -I $(MAILBOXLIB_INC) -I $(MAILBOXINT_INC) -I $(MAILBOXEXT_INC) -I $(FDT_PUBLIC) -I $(SLEEP_INC) -I $(SLEEP_INC)/sailhyp -I $(SAILUPDATER_INC) -I $(SAILUPDATER_INC)/sailhyp -I $(ICB_INC) -I $(MAILBOXEXT_INC) -I $(CRYPTO_INC) -I $(SECURE_STORAGE_COMMNON_INC) -I $(SECURE_STORAGE_EL2_INC) -I $(SECURE_STORAGE_CFG_INC)
INC_EL1  = -I $(SAILHEAP) -I $(CMNINC) -I $(CMNINC)/8650 -I $(LOGCODE_INC) -I $(INC_DIR)/inc/sailsw1 -I $(SAIL_DIAGNOSTICS_INC) -I $(INC_DIR)/public -I $(INC_DIR)/public/sailsw1 -I $(GPIO_INC) -I $(CHIPINFO_INC) -I $(BUSYWAIT_INC) -I $(PWR_CONTROLLER_INC) -I $(PWR_CONTROLLER_HYP_INC) -I $(CLOCK_INC) -I $(IPCC_INC) -I $(GIC_INC)/sailsw1 -I $(CAN_INC) -I $(I2C_INC) -I $(SPI_INC)/sailsw1 -I $(DBG_INC) -I $(ISD_INC)/sailsw1 -I $(FUSA_INC) -I $(AC_INC) -I$(MPU_INC) -I $(HWKM_INC) -I $(WDT_INC)/sailsw1 -I $(UART_INC) -I $(TSENS_INC)/sailsw1 -I $(SPINOR_INC) -I $(SPINOR_INC)/sailsw1 -I $(PMIC_INC) -I $(SECBOOT_INC) -I $(PRNG_FIPS_INC) -I $(CPR_INC) -I $(XBL_INC) -I $(XBL_INC)/sailsw1 -I $(BIST_INC) -I $(MAILBOXLIB_INC) -I $(MAILBOXEXT_INC) -I $(FDT_PUBLIC) -I $(SLEEP_INC) -I $(ICB_INC) -I $(SLEEP_INC)/sailsw1 -I $(SAIL_FS_PUB) -I $(DISPATCHER_INC)

SAILSW1_INC = -I $(PMU_INC) -I$(TCAN1146_PUB_INC) -I$(TCAN1146_INC) -I$(TCAN1146_GEN) -I$(TCAN1146_STUB) -I$(TCAN1044_STUB) -I $(CAN_STUB_INC) -I$(CAN_GEN_INC) -I$(TCAN1044_PUB_INC) -I$(TCAN1044_INC) -I$(TCAN1044_GEN) -I $(SPI_INC)  -I $(MCAL_CMN_INC) -I $(PWR_CONTROLLER_SW1_INC) -I $(TEST_SW1_INC)/sailsw1 -I $(TEST_SW1_INC)/public/sailsw1 -I $(ACMU_PUBLIC_INC) -I $(TESTS_INC)/public/sailsw1


PLACEMENT = $(shell $(PLACEMENT_RUN) $(SAIL_SRC_HOME)/BSP/el_entry)

all: setup
	@if [ "$(TAG)" = "sailjtagprogrammer" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC) ;\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SAILHYP_SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
	fi
	@if [ "$(TAG)" = "sailhyp" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC) ;\
		($(CC) $(TARGET_OPTS) $(INC) $(CC_SRC_OPTS) $(SAILHYP_SRC_C) $(CC_OPTS))|| exit $$?; \
		mkdir -p aarch32/$(BUILD_TARGET)/$(TAG) ; \
		mv *.o ./aarch32/$(BUILD_TARGET)/$(TAG)/; \
    elif [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && [ "$(IMAGE_RTOS)" = "FREERTOS" ] && echo $(PLACEMENT) | grep -q $(TAG); then \
		echo $(INC_EL1) $(SAILSW1_INC) $(INC_SAIL_FREERTOS);\
		($(CC) $(TARGET_OPTS) $(INC_EL1) $(SAILSW1_INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_EL1_C) $(CC_OPTS))|| exit $$?; \
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
