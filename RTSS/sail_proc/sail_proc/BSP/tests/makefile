.PHONY: clean all print setup

export SUBDIRS = $(sort $(dir $(wildcard */)))
export CMNINC=$(SAIL_SRC_HOME)/BSP/common_inc
export IPCC_INC=$(SAIL_SRC_HOME)/BSP/ipcc/public
export SAIL_FREERTOS_INC=$(SAIL_SRC_HOME)/BSP/sailfreertos/public
export FREERTOS_CONFIG_INC=$(SAIL_SRC_HOME)/FreeRTOS/config
export FREERTOS_OSAL_INC=$(SAIL_SRC_HOME)/FreeRTOS/osal
export FREERTOS_KERNEL_INC=$(SAIL_SRC_HOME)/FreeRTOS/kernel
export FREERTOS_PORTABLE_INC=$(SAIL_SRC_HOME)/FreeRTOS/portable
export INC_SAIL_FREERTOS=-I $(SAIL_FREERTOS_INC) \
                         -I $(FREERTOS_CONFIG_INC) \
                         -I $(IPCC_INC) \
                         -I $(FREERTOS_OSAL_INC)/public \
                         -I $(FREERTOS_KERNEL_INC)/include \
                         -I $(FREERTOS_PORTABLE_INC)

all:
	@for dir in $(SUBDIRS) ; do \
                cd $$dir ; \
		echo "=================== dir =============="; \
		echo $$dir; \
                if [ -f makefile ] && [ "$(TAG)" != "sailsw4" ]; then \
                        make; \
                        if [ $$? -eq 2 ]; then \
                                echo "Make Detected An Error !";\
                                exit 1;\
                        fi;\
                fi;\
                cd .. ; \
        done

clean:
	@for dir in $(SUBDIRS) ; do \
                cd $$dir && make clean -i ; \
                cd .. ; \
        done

print-%: setup
	@echo $* = $($*)

setup: 
        ifneq ($(ARM_TOOL_VARIANT),ult)
	$(Error! Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
endif

