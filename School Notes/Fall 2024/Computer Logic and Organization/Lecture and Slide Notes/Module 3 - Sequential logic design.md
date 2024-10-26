Combinational Circuits:
- without memory 
- outputs are 
Comb are basically just functions 
input - output 
Nothing is stored


Sequential Circuits 
- implement memory
- they don't have memory they use memory or are memory 
- depend on inputs and the previous outputs 
Two inverters form a static memory cell 
|------1---------|	 
|-->0 - 0 - >0----|------- stored value

we selectively break the feedback path basically manually allowing the data to come in or loop through the cell 



Set-Reset Latch 

if set is 1 and reset is 0 
set continues to output 1 until reset is 1
state machine 

 set reset state
  0   0    hold
  0   1    0
  1   0    1
  1   1    unstable 

unclocked change outputs when the inputs change

clocks are regular periodic signals 
two portions - high and low 
either on the rising or falling clock edge 
elements change on the active clock edge 
state element - comb - state element 2
circuits need time to update 

make sure to set up a prior state 
clock goes 
stable changing stable changing 
the latch cant change when the clock is active 
this is to prevent the forbidden state ie: r & s = 1 


FLIP FLOP 
memory element for which the output is equal to the value of the stored state inside the element and for which the internal state is changed only on a clock edge 
they are built from latches

2 inputs - clock and data 
2 outputs - internal state and compliment of that

if D is 1 the SR latch is set if D is 0 the SR latch is reset
when the clock is low or DE asserted the SR latch is holding and the flip flop is closed  

when clock = 0 keep value 

Cascading Logic Circuits
- connect output of one latch to the input of another
Registers 

data registers 
pattern recognizers 
counters 
shift registers 
ddd