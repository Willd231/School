Review: Linked Lists
-Singly Linked Lists: direct:
 --struct list_item{
 int id;
 int stuff;
 char more_stuff[32]
 }
struct list{
struct list_item *head;
struct list_item *tail
}

h -> n -> n -> n -> NULL
			^
			|
			t

Version without a tail*


(ring list):
-> h -> n -> n ->
or circular lol 
when you go off of one end you go to the other side of the universe


what is a circ linked list good for:
	Music Playlist
	Round robin process sched - 'lets scheduler be real stupid'
	bro said and the next one like 500 times


with a singly linked list, how long does it take to insert at the front of the list
how long does it take to insert at the back of the list if you have the tail versus not 

O(n)
yippee 


how long does it take to find in a linked list - Order n or n/2 

Eviltron - device that beeps every 3 hours

its order n because n/2 is n times a constant - a constant factor does not change it

we are going to move the Mesopotamian empire now 


We are computer scientists - we only care about the worst case - murphy's law

Quick sort - is actually bubble sort lmao
Quick sort best case is great  but its worst case...
Fundementally a cynical observation, but it works to make sure we don't leave it.
Murphy's law is just ocd if you believe it in the literal sense. 
DONT LEAVE THINGS TO CHANCE!


Dr. Gerber was walking from parking garage h to CB2 and sees a scooter. It jumpscares him and then he fucking falls on the ground and hurts his hand and *taps his chin lightly on the ground*. It requires him to go to the er and the doctor says he doesn't have a concussion. He has to go back to the urgent care for a follow up but they said he was never there. He is required to have documentation of a follow up for worker's comp. They refuse to give him documentation so he call's worker's comp. They told him to fill out a refusal of care form. His mother raised him well so he refuses to sign the refusal form. Then he goes to multiple different ers. The university paid for all of it. So basically the signs to get off of the sidewalk for scooters may actually be his fault.


How long does it take to delete a node in linked list using tail or not is order n. 
Every operation except add takes order n. 

The only 2 things a singly linked list without a tail is good for is:
Stacks and the Foundation Exam. 
For Queues you need the other end.

the type of pointer we don't talk about - void pointer
a void pointer is a pointer to anything
malloc returns a void pointer

please turn the discord chime off
please turn the discord chime off
please turn the discord chime off
please turn the discord chime off
please turn the discord chime off
please turn the discord chime off

and THIS IS A DOUBLY LINKED LIST

struct list_item{
struct list_item *prev;
struct list_item *next;
int id;
int stuff;
char more_stuff[32];
}

struct list{
struct list_item *head;
struct list_item *tail;
}
	NULL
	^
	|
h -> p  n
		^
	   /
      p

Why would you use a linked list?
:If the vast majority of the time, your data is sequential
soihfoiseHfroquhehiuqbwf 

what the fuck lmao

why am i keeping some log based list least squares algorithmic nightmare if my data is sequential then a linked list is not only adequate than it is better 

principal of constructive stupidity 
Real version.

intermission ??? 
featuring adults in peanuts

HAHA found it.

Resetting the firmware in lightbulbs 
its just a video of someone turning on/off a lamp for like 10 fucking minutes

the company disabled comments and doesn't want people to see the video but the professor showed the original 
https://www.youtube.com/watch?v=1BB6wj6Ryko

300 dollar Bluetooth toaster 
it can probably run doom says Doctor Gerber 
if you try to play skyrim on it your toast starts levitating slightly over the toaster


principal of constructive stupidity - do not make things smarter than they need to be
Do not underestimate the power of just getting things done a normal and straightforward way

x10? 
RIP RadioShack

"moron yapping about maps or something"

LINKED LISTS ARE TERRIBLE 
FUCK LINKED LISTS UNLESS YOU NEED THE FIRST SECOND OR LAST THING
really bad at random access 


Binary Search trees: 
struct int_bst{
int_bst *left;
int value;
int_bst *right;
}


he forgot a pointer to the parent :(
The example above is a "happy binary search tree"
Binary search trees solve the random access problems great unless something goes wrong 
AVL trees solve this
what the fuck does avl stand for? 
adelson-velskey and landis

a significant amount of cs work has been done by non americans
the big fancy Z for integers 
what does integer in german start with 
zynteger? 

*jumpscare*

He is going to show a method next week that has less churn than avl 
its called a 2 4 tree 
we dont really actually use it 
we actually use a red black tree but its hard to explain 
in the interest of having a much less annoying class he is just going to make us do a 2-4 tree 
yippee



































