# MicroDispatch
Microcontroller Task Scheduler

Super lightweight task scheduler aimed at 8 bit micro-controllers (perfect for Arduino), although it can easily be used on other hardware like Microchip PIC.

It uses simple round-robin scheduling so no priority levels can be set. You choose the time interval by calling dispatchTick(), this is usually in a timer interrupt.

Range for number of tasks: 0 to 255 tasks
Range for delay: 0 to 65535 ticks

Each task only uses 5 byte of RAM. The one task LED blink example only uses 5 bytes of RAM and 476 bytes of program memory for the whole program.
