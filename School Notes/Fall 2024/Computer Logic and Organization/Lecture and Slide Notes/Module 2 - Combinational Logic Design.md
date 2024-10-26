Digital Electronics don't actually only use exact 0s and 1s, they either have high voltage levels or low voltage values and characterize the former as 0 and the latter as 1, anything in between the high and low can be characterized as transition values 

These high and low values can vary highly between systems 

Computational blocks perform a set of logical functions in either a combinational or sequential method 

inputs -> system -> outputs

a block diagram is a figure similar to what i wrote above which shows the system and its inputs and outputs, sort of like a truth table 

Combinational vs. Sequential:

Combinational - No Feedback
			  - Output defined completely in terms of the inputs 
X1 -> T -> Z1
.
.
.
Xn -> T -> Zn

			
Sequential - Feedback
		   - System goes through different states 
		   - New state depends on inputs and current state 


Truth Tables: 
- You can simplify logic blocks by stating all of the inputs and outputs of the block using the truth table
- for every input there are 2^n entries in the truth table, each entry specifies the values of all of the outputs for the current combination 

Possible functions:

- If there are two input variables there should be 4 entries
	  
X ->
	--> F
Y ->


--Incrementing in binary : 000, 001, 010, 011, 100, 101, 110, 111
D is true when at least 1 is true, E is true when at least 2 are true, and F is true when at least 3 are true 
Inputs Outputs  
A B C D E F  
0 0 0 0 0 0
0 0 1 1 0 0
0 1 0 1 0 0
0 1 1 1 1 0
1 0 0 1 0 0
1 0 1 1 1 0
1 1 0 1 1 0
1 1 1 1 0 1

Logical Operators: 

Or:
- written as + as in A+B essentially combining the options
- this is further elucidated as it is referred to as a logical sum
And: 
- written as * like A*B
- called the logical product
Not:
- written as A'
Rules are very similar to logic rules in discrete, very simple 

Axioms and theorems: 
- Identity: X + 0 = X || x * 1 = x 
- Null : X + 1 = 1 || x * 0 = 0
- Idempotency: X + X = X || X * X = X 
- Involution: (X')' = X
- Inverse = X + X' = 1 || X * X' = 0
- Commutative: X + Y = Y + X || X * Y = Y * X
- Associativity: (x + y) + z = x + (y + z) || (x * y) * z = x * (y * z)
- Distributive: X * (Y * Z) = (X*Y) + (X * Z) || X + (Y * Z) = (X + Y) * (X + Z)
- uniting: (X * Y + X * Y') = X || (X+Y) * (X + Y') = X
- Absorption: (X+X*Y = X) || X * (X + Y) = X 
- (X +  Y') * Y = X * Y
- (X * Y') + Y = X +  Y
- Factoring: (X+Y) * (X' + Z) = X * Z + X' * Y ||
	X * Y + X' * Z = (X + Z) * (X' + Y)
- Consensus: (X*Y) + (Y * Z) + (X' * Z) = X * Y + X' * Z ||
  (X + Y) * (Y + Z) * (X' + Z) = (X + Y) * (X' + Z)
- de Morgan's: (X + Y + ...)' =  X' * Y' * ... || (X * Y ...)' = X' + Y' + ...


ADDER p1. 
1 bit binary adder 
- inputs A, B carry in 
- outputs Sum, carry-out
add literally 1 + 1 
in order to add bigger number we need to chain them together, need to start someone
Sum is 1 when any is true, giant or statement
A


Logic Gates:
- NOT: X', xbar, ~X  X ->0 y
 ![[Pasted image 20240923201834.png]]
- AND: X*Y x ^ y,\
 ![[Pasted image 20240923201807.png]]![[]]
- OR: X + Y, X v Y 
![[Pasted image 20240923201910.png]]


ADDER, Part 2 
- Logic gates for sum(shown without Cin)
Sum = A'B + AB'

Ideally we want to 


Reduce the number of inputs:
- Literal: can approximate it as being two transistors per input, we dont count inverters because we can invert at the beginning 
- Fewer literals means less transistors 
- reduce the number of gates, the fewer gates means reduced circuit size and less signal delay = 


Disjunctive normal form or minterm = where f is  1
Conjunctive normal form or maxterm = where f is 0

To find the canon form or min form just write with a + b + c and simplify 

1 is A' or B' or C' 


Maxterm is every term thats not in the min term and we can use them to solve for each other

Drawing relationships between negation and product of sums 
Negations will match ie minterm' = maxterm 

sometimes you get outputs you dont care about ie 'dont cares'
or incompletely specified functions 
just mark them as an x  

usually mark 10-16 0-9 are what we want 

just or them with the min terms or max terms 

minimization - canonical forms dont guarantee the most minimal form 


Karnaugh map 

implicant  - if 1 implies the output is 1 every combin of covers
prime impl - impl that is as big as it can be 
ess prime impl - must be in the final  
you can use dont cares as wild cards
or 1 to get a four row 

  use these two maps to practice **http://www.32x8.com/index.html** https://ictlab.kz/extra/Kmap/ and  review multiplex