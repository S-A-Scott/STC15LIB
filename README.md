# STC15LIB
Library for STC15 serials MCU

# Structure

The structure of this project is showed as below.
```
Project
 |             |--- main.c
 |--- [MAIN] --|
 |             |--- startup.a51
 |
 |             |--- main.h
 |--- [INC] -- |--- port.h
 |             |--- uart.h
 |             |--- etc.
 |
 |             |--- uart.c
 |--- [SRC] -- |--- pwm.c
 |             |--- timeout.c
 |             |--- etc.
 |
 |--- [OUT] -- |--- module.hex
 |             |--- *.obj (which is no use to programmer)
 |
 |             |--- uartDEMO.c
 |--- [DEMO] --|--- adcDEMO.c
 |             |--- etc.
 |
 |--- [PROJECT]--|--- module.uvopt (the start file of KEIL4)
 |
 |--- [LISTING]--|-- *.lst (also no use to programmer)

[] = directory
```

Where:
