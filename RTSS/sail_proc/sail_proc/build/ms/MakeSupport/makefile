.PHONY: clean all print setup

SAILEL2_DIR= "sailel2/"
FREERTOS_DIR=freertos/

SUBDIRS = $(wildcard */)

all:
	@for dir in $(SUBDIRS) ; do \
		cd $$dir ; \
		echo "=======XXXXXXX ------ START Building Images ---- XXXXXXX=======";\
		if [ -f makefile ]; then \
			make; \
			if [ $$? -eq 2 ]; then \
				echo "Make Detected An Error !";\
				exit 1;\
			fi;\
		fi;\
		echo "=======XXXXXXX ------ Finished Building Images ---- XXXXXXX=======";\
		cd .. ; \
	done

clean:
	@for dir in $(SUBDIRS) ; do \
		cd $$dir ; \
		echo "=======XXXXXXX ------ START Cleaning of Images ---- XXXXXXX=======";\
		if [ -f makefile ]; then \
			make clean; \
			if [ $$? -eq 2 ]; then \
				echo "Make Detected An Error !";\
				exit 1;\
			fi;\
		fi;\
		echo "=======XXXXXXX ------ Finished Cleaning of Images ---- XXXXXXX=======";\
		cd .. ; \
	done

print-%: setup
	@echo $* = $($*)

setup:
ifeq ($(TOOLCHAIN),arm_fusa) 
ifneq ($(ARM_TOOL_VARIANT),ult)
	$(error  Error! Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
endif
endif