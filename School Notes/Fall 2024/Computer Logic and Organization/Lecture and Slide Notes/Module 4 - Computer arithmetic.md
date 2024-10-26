when we chain adders togethe  
look at ways to shortcut 


1 bit half adder 
Carry in and out for full adder
Ripple carry - chain adders together
issues with ripple - circuits canbe complex 
carry lookahead and select 

1 bit half adder 

A B Sum Cout
0 0 0   0
0 1 1   0
1 0 1   0 
1 1 0   1 

Sum = A'B + AB' = AxorB -  sum = 1 only when they differ
Cout = AB


1 bit full adder 

A B Cin Cout Sum
0 0 0   0    0     
0 0 1   0    1
0 1 0   0    1
0 1 1   1    0 
1 0 0   0    1
1 0 1   1    0
1 1 0   1    0
1 1 1   1    1

sum = A XOR B XOR cin 
COUT = A * B + A * Cin + B * Cin


RIPPLE CARRY 
to add binary numbers of length greater than 1 we cascade one bit adders together 

Example 
3 + 2 = 5 
0011 + 0010 = 0101

A3 B3      A2 B2     A1 B1    A0 B0 
0  0       0  0      1  1     1  0 

  A  B       A  B      A  B     A  B 
	Cout Cin  0 Cout Cin 1 Cout Cin 0 Cout Cin  <--- 0cin is always 0 beg
	  Sum         Sum       Sum        Sum
	  S3          S2         S1         S0
		0			1		  0 	1 = 1 + 0
Overflow
no overflow 


overflow is basically when the value exceeds 
we need to detect if the bit increases ie = 7 + 7 = 14 
we cant do that in 4 bit 


RIPPLE CARRY ADDER: SUBTRACTION 

we initialize the top row by adding B' to each column 
the two values ie B0B'0 they are read into a multiplexor which decides which one to use 
make cin = 1 

Disadvantages can be that the time to propagate from lowest to highest which causes a delay and this can stack up 
as that one gets carried from full adder there is an increased delay 


Carry Lookahead Logic: 
Carry Gen -- Gi = AiBi 
must generate a carry when A = B = 1 

Carry Prop : Pi = Ai + Bi 
carry in will equal carry out 

COUT can be expressed in these terms 
Ci + 1 = AiBi + AiCi + BiCi
       = AiBi + Ci(Ai + Bi)
	   = Gi + CiPi
split up 32 bit in 4 8 bit adders

ALU 
- Performs addition and subtraction 
- AND, OR, NOR
- Less than, Equal to 
- doesn't perform mult or division it just repeatably adds and subs 

Need at least a 32 bit ALU
Uses and , or gate in a multiplexor 0:1

Addition: 1 bit alu will perform AND OR and ADD
Multiplexor chooses between them

Subtraction - to invert b add a 2:1 multiplexor to choose either b or b' 

NOR  - adds an A' - uses A' and B' -- De morgan's

Less than - SLT is a mips 
SLT - for alu to perform this we need method to determine A < B
we can do if(A-B)<0 if its less than zero then its false

EQUAL TO - just a NOR gate 

A 32 bit ALU - 31 without overflow detection, overflow only makes sense at 1 ALU most sig bit

The number of bits in the product is larger than the number in both of the things multiplying 
m bits x n bits = m + n product 
overflow happens 

1000
1001
just multiply normally 
except shift the multiplicand left one digit each step 


0 0   00000000 00001011 1001 
1 1a  00001011 00001011 1001
1 2,3 00001011 00010110 0100
2 1   00001011 00010110 0100
2 2,3 00001011 00101100 0010
3 1   00001011 00101100 0010
3 2,3 00001011 01011000 0001
4 1a  01100011 01011000 0001
4 2,3 01100011 10110000 0000

We want to avoid mult bcs so time consuming

Half of the bits of the multiplicand are always 0 


ver 3 

iter  step Product  Multiplicand Action
___
0     0    00001001  1011   init
1     1a   10111001  1011   add the mult to the left hand of the prod
1     2    01011100  1011   shift 
2     1    01011100  1011   noadd
2     2    00101110  1011   shift
3     1    00101110  1011   test noadd
3     2    00010111  1011   shift
4    1a    11000111  1011   add
4     2    01100011  1011   shift



multiplying by a constant
shifting the bits left has the same effect as multiplying by 2

signed multiplication

BOOTH's Algorithm 
- Multiply 2's compliment signed numbers 
- optimization and expand 
Consider 2 X 6 = 0010 x 0110 

0010
0110 
___
    0000 shift (0 in multiplier)
   0010  add   (1 in multiplier)
  0010   add   (1 in multiplier)
0000 
___
00001100

Alu can help you arrive at a similar result 
6x = 4x + 2x or 6x = -2x + 8x
111 = 1000 - 0001
1111 = 10000 - 00001
1111XXX = 10000XXX - 00001XXX

Boothes Algo oper 
1:
- 00 = do nothing
- 01 = add the multiplicant to the left half of the product
- 10 = beginning of a string of 1s, subtract the multiplicand from the left half of the product 
- 11 = middle of a string of 1s, nothing 
2. Shift the Product right 1 bit