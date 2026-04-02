.PHONY: clean all setup print

export TARGET_SOC ?= lemansau
export TAG = $(IMAGE)
export PROJ_NAME=$(IMAGE)
export BUILD_FLAVOUR ?= SAIL_RTOS
export BSP_SUBDRS=$(SAIL_SRC_HOME)/BSP
export DIR_OBJ_REL=$(SAIL_SRC_HOME)/build/ms/bin/$(BUILD_FLAVOUR)/OBJ_RELEASE/$(TARGET)
export FREERTOS_SUBDRS=$(SAIL_SRC_HOME)/FreeRTOS
export CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
export ELF_PATH=$(BUILD_MS_ROOT)/bin/$(BUILD_FLAVOUR)/DEBUG/$(TARGET)
export MAP_FILE_PATH=$(ELF_PATH)/$(PROJ_NAME).map
export DIR_S_BSP = $(sort $(dir $(wildcard $(BSP_SUBDRS)/*/*)))
export DIR_S_FREERTOS = $(sort $(dir $(wildcard $(FREERTOS_SUBDRS)/*)))
export PLACEMENT_CFG ?= $(SAIL_SRC_HOME)/BSP/scripts/placement_default.xml
export PLACEMENT_RUN = python3 $(SAIL_SRC_HOME)/BSP/scripts/get_module_flag.py $(PLACEMENT_CFG)
export IMAGE_RTOS = FREERTOS
export EL2_OBJ_INSTALLER=$(BSP_SUBDRS)/sailhyp_obj_install_$(BUILD_FLAVOUR).sh
#export SAILUPDATER_INJTEST_ENABLED_VAL=1

TOOLCHAIL_FLAG ?= __ARM_GNU__ 

export DTC ?= dtc
export DTS_CONFIG ?= CONFIG0

ifneq ($(OS),Windows_NT)
export SECTOOLS ?= $(shell python3 $(SAIL_SRC_HOME)/build/ms/scripts/sectoolsv2_finder.py)
endif

EL2_DTB_ADDR = 	0x08019000
#EL2_DTBO_ADDR = 0x0
SW1_DTB_ADDR = 	0x082DC400
#SW1_DTBO_ADDR = 0x0
#SW2_DTB_ADDR = 	0x082D8400
#SW2_DTBO_ADDR = 0x0
#SW3_DTB_ADDR = 	0x082D6400
#SW3_DTBO_ADDR = 0x0

default: debug

export BUILD_TARGET = DEBUG

debug: export BUILD_TARGET = DEBUG
debug: build_all

release: export BUILD_TARGET = RELEASE
release: build_all

SIGN_DIR = ./bin/$(BUILD_FLAVOUR)/$(BUILD_TARGET)/$(TARGET)/signed

ifeq ($(SAILUPDATER_INJTEST_ENABLED_VAL),1)
export CC_OPTS_BASE += -DSAILUPDATER_INJTEST_SRC_ENABLED
endif


ifneq (,$(wildcard $(SAIL_SRC_HOME)/BSP/sailjtagprogrammer))
build_all: sailhypnosym sailhyp
else
build_all: sailhyp
endif

sailhyp: check_valid_target setup_compiler_flags
sailhypnosym: check_valid_target setup_compiler_flags
sailnorpvl: check_valid_target setup_compiler_flags

sailhyp: export CC_OPTS = $(CC_OPTS_BASE) -DSAILEL2 -D$(TARGET) -D$(BUILD_FLAVOUR) -D$(DTS_CONFIG) -D$(TOOLCHAIL_FLAG)
# ifeq ($(TAG),sailhyp)
# export LD_OPTS=--lto --map --list=$(MAP_FILE_PATH) --cpu=cortex-r52 --show_cmdline --no_startup --symbols --inline_type=none --entry=$(VECTOR_TABLE) --scatter=$(SCATTER_FILE_PATH) -o $(ELF_PATH)/$(PROJ_NAME)_nonedtb.elf
# endif

sailhyp:
	@echo "sailhy_obj_pinstall.sh"
	mkdir -p -m 777 --verbose $(BUILD_MS_ROOT)/bin/$(BUILD_FLAVOUR)/$(BUILD_TARGET)/$(TARGET)
	make install_clean
	make build IMAGE=sailhyp IMAGE_ID=SAIL-HYP VECTOR_TABLE=EL2_Vectors
	make install
	@echo "=======XXXXXXX SAIL-HYP Image Build Completed XXXXXXX=======!"

sailhypnosym: export CC_OPTS = $(CC_OPTS_BASE) -DSAILEL2 -D$(TARGET) -D$(BUILD_FLAVOUR) -D$(DTS_CONFIG) -D$(TOOLCHAIL_FLAG)
sailhypnosym:
	@echo "=======XXXXXXX START Building SAIL-HYP-NOSYM Image only =======XXXXXXX"
	@echo $(EL2_OBJ_INSTALLER)
	mkdir -p -m 777 --verbose $(BUILD_MS_ROOT)/bin/$(BUILD_FLAVOUR)/$(BUILD_TARGET)/$(TARGET)
	make install_clean
	make buildnosym IMAGE=sailhyp IMAGE_ID=SAIL-HYP VECTOR_TABLE=EL2_Vectors
	@echo "=======XXXXXXX SAIL-HYP-NOSYM Image only Build Completed =======XXXXXXX!"

sailhypdts:
	@echo "=======XXXXXXX START Building SAIL-HYP with DTS Image  =======XXXXXXX"
	make link_dts IMAGE=sailhyp IMAGE_ID=SAIL-HYP
	@echo "=======XXXXXXX SAIL-HYP Image with DTS Build Completed =======XXXXXXX!"

sailjtagprogrammer: export CC_OPTS = $(CC_OPTS_BASE) -DSAILEL2 -DSAILJTAGPROGRAMMER -D$(TOOLCHAIL_FLAG)
# ifeq ($(TAG),sailjtagprogrammer)
# export LD_OPTS=--lto --map --list=$(MAP_FILE_PATH) --cpu=cortex-r52 --show_cmdline --no_startup --symbols --inline_type=none --entry=$(VECTOR_TABLE) --scatter=$(SCATTER_FILE_PATH) -o $(ELF_PATH)/$(PROJ_NAME).elf
# endif

sailjtagprogrammer:
	@echo "=======XXXXXXX START Building SAIL-JTAGPROGRAMMER Image  =======XXXXXXX"
	mkdir -p -m 777 --verbose $(BUILD_MS_ROOT)/bin/$(BUILD_FLAVOUR)/$(BUILD_TARGET)
	make build IMAGE=sailjtagprogrammer IMAGE_ID=SAIL-HYP VECTOR_TABLE=EL2_Vectors 
	@echo "=======XXXXXXX JTAGPROGRAMMER Image Build Completed =======XXXXXXX!"

sailnorpvl: export CC_OPTS = $(CC_OPTS_BASE) -DSAILEL2 -DNORPVL_ENB -D$(TARGET) -D$(TOOLCHAIL_FLAG)
sailnorpvl: export NORPVL_ENB_VAL =1
sailnorpvl:
	@echo "=======XXXXXXX START Building SAIL-HYP Image  XXXXXXX======="
	mkdir -p -m 777 --verbose $(BUILD_MS_ROOT)/bin/$(BUILD_FLAVOUR)/$(BUILD_TARGET)/$(TARGET)
	make build IMAGE=sailhyp IMAGE_ID=SAIL-HYP VECTOR_TABLE=EL2_Vectors
	@echo "=======XXXXXXX SAIL-HYP Image Build Completed XXXXXXX=======!"

setup_compiler_flags:
ifeq ($(TOOLCHAIN),arm_fusa)
#ARM FuSa Toolchain, Compiler/Linker Flags 
############################################
TOOLCHAIL_FLAG := __ARM_FUSA__
export CC := $(COMPILER_PATH)/armclang --target=arm-arm-none-eabi
export LD := $(COMPILER_PATH)/armlink

export TARGET_OPTS := \
			-mcpu=cortex-r52 \
			-fno-builtin \
			-nostdlib \
			-std=c99 \
			-fno-omit-frame-pointer 

export CC_SRC_OPTS :=
export CC_ASM_OPTS := -xassembler-with-cpp

export CC_OPTS_BASE := \
			-g \
			-O1 \
			-xc \
			-c \
			-mthumb \
			-Werror \
			-Wno-unused-command-line-argument

export ARM_SCATTER_FILE_PATH=$(SAIL_SRC_HOME)/BSP/scripts/$(PROJ_NAME).scat

export LIBS := --stdlib=libc++

export LD_OPTS := \
			--lto \
			--map \
			--list=$(MAP_FILE_PATH) \
			--cpu=cortex-r52 \
			--show_cmdline \
			--no_startup \
			--symbols \
			--inline_type=none \
			--entry=$(VECTOR_TABLE) \
			--scatter=$(ARM_SCATTER_FILE_PATH) \
			-o $(ELF_PATH)/$(PROJ_NAME)_nonedtb.elf

else ifeq ($(TOOLCHAIN),arm_gnu)
#ARM GNU Toolchain based on GCC, Compiler/Linker Flags
############################################
#TODO: tune compiler flags to find balance between optimization and code size.
TOOLCHAIL_FLAG := __ARM_GNU__
export CC := $(COMPILER_PATH)/arm-none-eabi-gcc
export LD := $(COMPILER_PATH)/arm-none-eabi-ld

export TARGET_OPTS := \
			-mcpu=cortex-r52 \
			-mfloat-abi=softfp \
			-fno-builtin \
			-ffreestanding \
			-nostdlib \
			-std=c99 \
			-fno-omit-frame-pointer \
			-ffunction-sections \
			-fdata-sections \
			-fno-common \
			-fno-optimize-sibling-calls \
			-mabi=aapcs \
			-mno-sched-prolog \
			-mapcs-frame

export CC_SRC_OPTS := -xc
export CC_ASM_OPTS := -xassembler-with-cpp

export CC_OPTS_BASE := \
			-gdwarf-4 \
			-O1 \
			-c \
			-marm \
			-Werror \
			-Wno-unused-command-line-argument \
			--no-sysroot-suffix \
			--sysroot=$(COMPILER_PATH)/../

export GNU_LD_FILE_PATH := $(SAIL_SRC_HOME)/BSP/scripts/$(PROJ_NAME).ld

export LIBS := \
			-Bstatic \
			-Wl,-L$(COMPILER_PATH)/../ \
			-Wl,-L$(COMPILER_PATH)/../arm-none-eabi/lib \
			-Wl,--gc-sections \
			-Wl,--start-group -lc -lgcc -lm -lrdimon -Wl,--end-group

export LD_OPTS := \
			$(TARGET_OPTS) \
			-nostartfiles \
			-Wl,-Map=$(MAP_FILE_PATH) \
			-Wl,--entry=$(VECTOR_TABLE) \
			-Wl,--script=$(GNU_LD_FILE_PATH) \
			-o $(ELF_PATH)/$(PROJ_NAME)_nonedtb.elf
else
	$(error  Error! TOOLCHAIN not selected. Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
endif

#DTC Command Usage
############################################
export DTS_CPP_CMD=$(CC) -P -E -x c -D$(DTS_CONFIG) -I $(SAIL_SRC_HOME)/BSP/scripts $(SAIL_SRC_HOME)/BSP/scripts/$(TARGET_SOC)-$(TAG).dts -o $(ELF_PATH)/$(TAG)_postcpp.dts
export DTS_CMD=$(DTC) -q -p 1000 --in-format dts -i $(SAIL_SRC_HOME)/BSP/scripts --out-format dtb --out $(ELF_PATH)/$(TAG).dtb $(ELF_PATH)/$(TAG)_postcpp.dts

#Secure Tools Utility
############################################
export SWIV_FLAG ?= TRUE
export SWIV_TOOL ?= python3 $(SAIL_SRC_HOME)/build/ms/scripts/swiv_build_utility.py

build: setup compile link

buildnosym: setup compile link_nosym

define COLLECT_OBJS
	OBJ_S += $(foreach dir,$(DIR_S_BSP),$(wildcard $(dir)aarch32/$(BUILD_TARGET)/$(TAG)/*))
	OBJ_S += $(foreach dir,$(DIR_OBJ_REL),$(wildcard $(dir)/$(TAG)/*))
endef

compile: setup

	@cd $(FREERTOS_SUBDRS) ;\
	if [ -f makefile ]; then \
		make ; \
		if [ $$? -eq 2 ]; then \
			echo " \n \n \t Make Detected An Error !	\n \n " ;\
			exit 1;\
		fi ;\
	fi
	cd ..
	
	@cd $(BSP_SUBDRS) ;\
	if [ -f makefile ]; then \
		make ; \
	 	if [ $$? -eq 2 ]; then \
			echo " \n \n \t Make Detected An Error !  \n \n " ;\
			exit 1;\
		fi ;\
	fi 
	@cd ..

dts_compile:
	mkdir -p -m 777 --verbose $(ELF_PATH)
	python3 ../syscmd.py $(DTS_CPP_CMD)
	python3 ../syscmd.py $(DTS_CMD)
	

link: setup dts_compile
	$(eval $(call COLLECT_OBJS))
	@echo $(OBJ_S) > obj.txt
	@if [ "$(TOOLCHAIN)" = "arm_fusa" ]; then \
		$(LD) $(LIBS) --via=obj.txt $(LD_OPTS); \
	elif [ "$(TOOLCHAIN)" = "arm_gnu" ]; then \
		$(CC) $(LD_OPTS) @obj.txt $(LIBS); \
	fi
	rm -f obj.txt
	make prng_fips
	echo merge DTB and DTBO to the elf file...
	@if [ "$(TAG)" = "sailhyp" ] || [ "$(TAG)" = "sailjtagprogrammer" ]; then	\
		$(SECTOOLS) elf-tool insert $(ELF_PATH)/$(TAG)_nonedtb.elf \
			--data $(ELF_PATH)/$(TAG).dtb --outfile $(ELF_PATH)/$(TAG)_dtb.elf --type LOAD	\
			--paddr $(EL2_DTB_ADDR) --vaddr $(EL2_DTB_ADDR) --align 0x4 -v; 	\
		rm -f $(ELF_PATH)/$(TAG)_nonedtb.elf;	\
		mv -f $(ELF_PATH)/$(TAG)_dtb.elf $(ELF_PATH)/$(TAG).elf;	\
	fi

	@if [ "$(SWIV_FLAG)" = "TRUE" ] && [ "$(TAG)" != "sailhyp" ] && [ "$(TAG)" != "sailjtagprogrammer" ]; then	\
		$(SWIV_TOOL) -i $(ELF_PATH)/$(TAG).elf -o $(ELF_PATH)/$(TAG)_swiv.elf -b ;\
		$(SECTOOLS) elf-tool insert $(ELF_PATH)/$(TAG).elf --data $(ELF_PATH)/$(TAG)_swiv.elf.bin \
			--outfile $(ELF_PATH)/$(TAG)_temp.elf --type NULL --align 0x4 -v ;\
		rm -f $(ELF_PATH)/$(TAG)_swiv.elf ;\
		rm -f $(ELF_PATH)/$(TAG)_swiv.elf.bin ;\
		rm -f $(ELF_PATH)/$(TAG).elf ;\
		mv -f $(ELF_PATH)/$(TAG)_temp.elf $(ELF_PATH)/$(TAG).elf ;\
	fi

	@echo "Build signing start!"
	bash $(BUILD_MS_ROOT)/sign_image.sh $(PROJ_NAME) $(IMAGE_ID) $(TARGET)
	@echo "Build Completed Successfully !"
	@echo "ELF Section Details:"
	@readelf -ls $(BUILD_MS_ROOT)/bin/$(BUILD_FLAVOUR)/$(BUILD_TARGET)/$(TARGET)/signed/$(PROJ_NAME).elf

link_nosym: setup
	$(eval $(call COLLECT_OBJS))
	@echo $(OBJ_S) > obj.txt
	@if [ "$(TOOLCHAIN)" = "arm_fusa" ]; then \
		$(LD) $(LIBS) --via=obj.txt $(LD_OPTS); \
	elif [ "$(TOOLCHAIN)" = "arm_gnu" ]; then \
		$(CC) $(LD_OPTS) @obj.txt $(LIBS); \
	fi
	rm -f obj.txt
	make prng_fips
	mkdir -p -m 777 --verbose $(ELF_PATH)/elfsymbols
	cp -f $(ELF_PATH)/$(TAG)_nonedtb.elf $(ELF_PATH)/elfsymbols/$(TAG).elf
	@if [ "$(TAG)" = "sailhyp" ]; then	\
		$(SECTOOLS) elf-tool remove-sections $(ELF_PATH)/$(TAG)_nonedtb.elf \
			--outfile $(ELF_PATH)/$(TAG)_nosym.elf; 	\
		rm -f $(ELF_PATH)/$(TAG)_nonedtb.elf; \
#		mv -f $(ELF_PATH)/$(TAG)_nosym.elf $(ELF_PATH)/$(TAG).elf; \
	fi

link_dts: setup renamedtself dts_compile 
	echo merge DTB and DTBO to the elf file...
	@if [ "$(TAG)" = "sailhyp" ]; then	\
		$(SECTOOLS) elf-tool insert $(ELF_PATH)/$(TAG)_nonedtb.elf \
			--data $(ELF_PATH)/$(TAG).dtb --outfile $(ELF_PATH)/$(TAG)_dtb.elf --type LOAD	\
			--paddr $(EL2_DTB_ADDR) --vaddr $(EL2_DTB_ADDR) --align 0x4 -v; 	\
		if [ ! -z "$(DTBO_EL2)" ] && [ -f "$(DTBO_EL2)" ]; then \
			$(SECTOOLS) elf-tool insert $(ELF_PATH)/$(TAG)_dtb.elf \
				--data $(DTBO_EL2) --outfile $(ELF_PATH)/$(TAG)_dtbo.elf --type LOAD \
				--paddr $(EL2_DTBO_ADDR) --vaddr $(EL2_DTBO_ADDR) --align 0x4 -v;	\
			mv -f $(ELF_PATH)/$(TAG)_dtbo.elf $(ELF_PATH)/$(TAG)_dtb.elf; \
		fi;	\
	fi

	rm -f $(ELF_PATH)/$(TAG)_nonedtb.elf
	mv -f $(ELF_PATH)/$(TAG)_dtb.elf $(ELF_PATH)/$(TAG).elf

	@if [ "$(SWIV_FLAG)" = "TRUE" ] && [ "$(TAG)" != "sailhyp" ]; then	\
		$(SWIV_TOOL) -i $(ELF_PATH)/$(TAG).elf -o $(ELF_PATH)/$(TAG)_swiv.elf -b ;\
		$(SECTOOLS) elf-tool insert $(ELF_PATH)/$(TAG).elf --data $(ELF_PATH)/$(TAG)_swiv.elf.bin \
			--outfile $(ELF_PATH)/$(TAG)_temp.elf --type NULL --align 0x4 -v ;\
		rm -f $(ELF_PATH)/$(TAG)_swiv.elf ;\
		rm -f $(ELF_PATH)/$(TAG)_swiv.elf.bin ;\
		rm -f $(ELF_PATH)/$(TAG).elf ;\
		mv -f $(ELF_PATH)/$(TAG)_temp.elf $(ELF_PATH)/$(TAG).elf ;\
	fi

	@echo "Build signing start!"
	bash $(BUILD_MS_ROOT)/sign_image.sh $(PROJ_NAME) $(IMAGE_ID) $(TARGET)
	@echo "Build Completed Successfully !"
	@echo "ELF Section Details:"
	@readelf -ls $(BUILD_MS_ROOT)/bin/$(BUILD_FLAVOUR)/$(BUILD_TARGET)/$(TARGET)/signed/$(PROJ_NAME).elf

renamedtself:
	echo rename unsigned elf with nosym to nonedtb elf file...
	cp -f $(ELF_PATH)/$(TAG)_nosym.elf $(ELF_PATH)/$(TAG)_nonedtb.elf

#TODO: enable prng_fips for hash generation, once the support is available with gcc.
prng_fips:
	@if [ "$(TOOLCHAIN)" = "arm_fusa" ]; then \
		echo prng_fips... ;\
		cd $(BUILD_MS_ROOT)/scripts && python3 prng_fips_integrity_builder.py $(ELF_PATH)/sailhyp_nonedtb.elf $(ELF_PATH)/sailhyp_nonedtb.elf ;\
	fi

rebuild: clean setup compile link

install:
ifneq (,$(wildcard $(SAIL_SRC_HOME)/BSP/security/hwkm/src))
	make install_clean
	mkdir -p -m 777 --verbose $(DIR_OBJ_REL)/sailhyp
	$(EL2_OBJ_INSTALLER) $(BSP_SUBDRS) $(DIR_OBJ_REL)
else
endif

install_clean:
ifneq (,$(wildcard $(SAIL_SRC_HOME)/BSP/security/hwkm/src))
	@echo "Install script path " $(EL2_OBJ_INSTALLER)
	chmod 755 "$(EL2_OBJ_INSTALLER)"
	rm -rf --verbose $(DIR_OBJ_REL)/sailhyp
else
endif

clean: check_valid_target clean_sailjtagprogrammer clean_sailhyp install_clean

check_valid_target:
ifeq ($(TARGET),lemans)
else ifeq ($(TARGET),monaco)
else
export TARGET=lemans
endif

clean_sailjtagprogrammer:
	@echo "=======XXXXXXX START Cleaning of SAIL-JTAGPROGRAMMER Image  XXXXXXX======="
	make clean_image IMAGE=sailjtagprogrammer
	@echo "=======XXXXXXX SAIL-JTAGPROGRAMMER Image Cleaning Completed XXXXXXX=======!"
    
clean_sailhyp:
	@echo "=======XXXXXXX START Cleaning of SAIL-HYP Image  XXXXXXX======="
	make clean_image IMAGE=sailhyp
	@echo "=======XXXXXXX SAIL-HYP Image Cleaning Completed XXXXXXX=======!"

clean_image:
	@for dir in $(BSP_SUBDRS) ; do \
		cd $$dir && make clean -i;\
		cd .. ; \
	done

	find $(BSP_SUBDRS) -name *.o -exec rm -f {} \;

	rm -f $(ELF_PATH)/$(TAG)*.dtb
	rm -f $(ELF_PATH)/$(TAG)*.dts
	rm -f $(ELF_PATH)/$(TAG)*.elf
	rm -f $(ELF_PATH)/$(TAG)*.map
	rm -f $(ELF_PATH)/signed/$(TAG)*.elf
	rm -f $(ELF_PATH)/elfsymbols/$(TAG)*.elf

	@if [ -d "$(ELF_PATH)/signed" ] && [ -z "$$(ls $(ELF_PATH)/signed)" ]; then \
		rm -rf $(ELF_PATH)/signed	;\
	fi 

	@if [ -d "$(ELF_PATH)/elfsymbols" ] && [ -z "$$(ls $(ELF_PATH)/elfsymbols)" ]; then \
		rm -rf $(ELF_PATH)/elfsymbols	;\
	fi
	
	@echo "All Build Products Cleared"

setup: 
ifeq ($(TOOLCHAIN),arm_fusa) 
ifneq ($(ARM_TOOL_VARIANT),ult)
	$(error  Error! Incorrect ARM Tool Variant. Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
endif
endif

print-%: setup
	@echo $* = $($*)
