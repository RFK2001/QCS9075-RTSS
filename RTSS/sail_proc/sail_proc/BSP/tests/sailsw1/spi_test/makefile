.PHONY: clean all print setup


CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
PUBLIC_INC=$(SAIL_SRC_HOME)/BSP/tests/public
TEST_HWIO_INC=$(SAIL_SRC_HOME)/BSP/tests/8650
PUBLIC_INC_sw1=$(SAIL_SRC_HOME)/BSP/tests/public/sailsw1
SPI_MCAL_INC=$(SAIL_SRC_HOME)/BSP/spi/public
SPI_MCAL_CFG_INC=$(SAIL_SRC_HOME)/BSP/McalCfg/Inc
FDT_INC=$(SAIL_SRC_HOME)/BSP/fdt/public
MCAL_CMN_INC=$(SAIL_SRC_HOME)/BSP/Mcal/Base
IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
BUSY_INC=$(SAIL_SRC_HOME)/BSP/time/public/
SOURCE_DIR=$(SAIL_SRC_HOME)/BSP/tests/sailsw1/spi_test/src
SPI_INC = $(SAIL_SRC_HOME)/BSP/spi

SRC_C=$(SOURCE_DIR)/*.c
SRC_S=$(SOURCE_DIR)/*.s


SAILSW1_INC  =  -I $(PUBLIC_INC)/sailsw1 -I $(PUBLIC_INC) -I $(CMNINC) -I $(CMNINC)/8650 -I $(PUBLIC_INC_sw1)  -I $(SPI_MCAL_CFG_INC) -I $(FDT_INC) -I $(MCAL_CMN_INC) -I $(SPI_MCAL_INC) -I $(SPI_MCAL_CFG_INC) -I $(SPI_INC)/public -I $(SPI_INC)/inc -I $(SPI_INC)/inc/8650  -I $(IPCC_INC) -I $(BUSY_INC)


PLACEMENT_TEMP = $(shell $(PLACEMENT_RUN) BSP/spi)

all: setup
	@if [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ] && [ "$(TAG)" != "autosarsailbaremetal" ]; then \
		 echo $(SAILSW1_INC) $(INC_SAIL_FREERTOS);\
                ($(CC) $(TARGET_OPTS) $(SAILSW1_INC) $(INC_SAIL_FREERTOS) $(CC_SRC_OPTS) $(SRC_C) $(SAILVSENS_TESTEN_OPTION) $(CC_OPTS)) || exit $$?; \
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
