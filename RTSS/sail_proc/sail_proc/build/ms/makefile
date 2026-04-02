.PHONY: clean all sailfreertos sailel2 setup print

MKFILE_SUBDIR = $(BUILD_MS_ROOT)/MakeSupport

default:all

all:
	@echo "=======XXXXXXX Build Products start XXXXXXX=======!"
	@cd $(MKFILE_SUBDIR) ; \
	if [ -f makefile ]; then \
		make ; \
		if [ $$? -eq 2 ]; then \
			echo " \n \n \t Make Detected An Error !	\n \n " ;\
			exit 1;\
		fi ;\
	fi
	cd ..
	@echo "=======XXXXXXX Build Products complete XXXXXXX=======!"


sailfreertos:
	$(MAKE) -C MakeSupport/freertos  BUILD_FLAVOUR=SAIL_RTOS

sailel2:
	$(MAKE) -C MakeSupport/sailel2


rebuild: clean all

    
clean:
	@echo "=======XXXXXXX Build Products Clean start XXXXXXX=======!"
	@cd $(MKFILE_SUBDIR) ; \
	if [ -f makefile ]; then \
		make clean; \
		if [ $$? -eq 2 ]; then \
			echo " \n \n \t Make Detected An Error !	\n \n " ;\
			exit 1;\
		fi ;\
	fi
	cd ..
	@echo "=======XXXXXXX All Build Products Cleared XXXXXXX=======!"

clean_freertos:
	$(MAKE) clean -C MakeSupport/freertos 

clean_sailel2:
	$(MAKE) clean -C MakeSupport/sailel2
setup:
ifeq ($(TOOLCHAIN),arm_fusa)
ifneq ($(ARM_TOOL_VARIANT),ult)
	$(error  Error! Setup Enviroment first using "source ./sail_proc/build/ms/setupenv.sh")
endif
endif

print-%: setup
	@echo $* = $($*)
