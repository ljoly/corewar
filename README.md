# corewar
Creating an assembler to compile programs (the "champions"), and a virtual “arena” in which the champions will fight.

## vm usage:

-dump N: prints hex dump after N cycles (can't be used with any graphic option)  

-v: graphic visualiser in continuous mode
 * press S to start and it runs until the end
 * speed can be increased or decreased using the arrows up and down
 
 -p: graphic visualiser in mode step by step
* press S for every cycle

-n N: assigning a number to a player
* can be used only before a valid .cor file
* N indicates the player number
* accepts all positive numbers and negative numbers except 0
* the same number can't be used for more than one player
* max: 4 players, minimum: 1

********************************************************************************
