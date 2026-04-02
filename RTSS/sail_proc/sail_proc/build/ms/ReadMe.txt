Use the following commands to compile all images in one go.
	1.Full build command for lemans : make    or   make TARGET=lemans
	2.Full clean command for lemans : make clean   or   make clean TARGET=lemans
	3.Full build command for monaco : make TARGET=monaco
	4.Full clean command for monaco : make clean TARGET=monaco

This will generate the images under bin/Flavor/DEBUG/TARGET/signed/… folder. 
Note: There is a plan to add Build Flavors. At that the location of the binaries should be bin/Flavour/DEBUG/TARGET/signed/…
here TARGET can be lemans/monaco as per the settings, and Flavor is SAIL_RTOS by default.

Individual images compilation : the images segregated into groups based on top of the main execution environment compiled into the image, the following is the segregation available as of now
	1.Sail EL2       -- Uses the inhouse bare metal execution environment to be executed in EL2 mode.
	2.FreeRTOS       -- Uses the FreeRTOS to define the execution environment. All the Images that use FreeRTOS will be put under this classification.

To build individual images there are two ways to go about it.
	1.Issue a make command using the above segregation: All the images will still be generated under bin/SAIL_RTOS/DEBUG/TARGET/signed/… folder.
		a.Compile SailHyp image for lemans           : make sailel2         or   make sailel2 TARGET=lemans
		b.Compile EL1 FreeRTOS image for lemans      : make sailfreertos    or   make sailfreertos TARGET=lemans
        d.Compile SailHyp image for monaco           : make sailel2 TARGET=monaco
		b.Compile EL1 FreeRTOS image for monaco      : make sailfreertos TARGET=monaco
	2.Issue a make command by going into respective MakeSupport folder and invoke the make command. All the images will still be generated under bin/SAIL_RTOS/DEBUG/TARGET/signed/… folder.
		a.Compile SailHyp image: Make sure you are in build/ms folder then issue the following commands.
			i.Move to SailEL2 makesupport folder     : cd MakeSupport/sailel2
			ii.Compilation command for lemans        : make   or   make sailhyp   or   make TARGET=lemans   or   make sailhyp TARGET=lemans
			iii.Clean command for lemans             : make clean   or   make clean TARGET=lemans
			iv.Compilation command for monaco        : make TARGET=monaco   or   make sailhyp TARGET=monaco
			v.Clean command for monaco               : make clean TARGET=monaco
		c.Compile EL1 FreeRTOS image: Make sure you are in build/ms folder then issue the following commands.
			i.Move to FreeRTOS makesupport folder    : cd MakeSupport/freertos
			ii.Compilation command for lemans        : make   or   make sailsw1   or   make TARGET=lemans   or   make sailsw1 TARGET=lemans
			iii.Clean command for lemans             : make clean   or   make clean TARGET=lemans
			iv.Compilation command for monaco        : make TARGET=monaco   or   make sailsw1 TARGET=monaco
			v.Clean command for monaco               : make clean TARGET=monaco