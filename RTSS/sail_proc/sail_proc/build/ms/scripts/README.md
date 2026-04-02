
## usage

Usage : python stack_unwind.py 

--alpaca=com3                   : COM port for ALPACA control
--comport=com4                  : COM port for SAIL Uart
--log =c:\temp\sometest         : prefix for logfile
--mapfile = sailhyp.map         : Path to mapfile

## usage example

    python stack_unwind.py --alpaca=com4 --comport=com7 --logc:\temp\sometest --mapfile=sailhyp.map

## Output :

    Prints the unwinded stack

## Output example

Error Injected in TSENS

    SAILBSP Fatal Error. Module_ID :10  Error_ID : 6

    Stack unwind begins ..   
    (0802d4db)err_fatal
    (0803d14f)sailbsp_main
    (08029dcd)boot_sail_main                                                                                     
    (0803ca91)sailbsp_boot_cold_init     
    Stack unwind ends .. 

    