AVL TREES



Trees that we are actually going to talk about: 

2-4 trees:
- a 2node - tree with one data element and associated key and 2 children
- 3node has 2 elements and three children
- 4node has 3 data elements and four children 
- a leaf with one two or three data element but no children
-
The data elements are sorted
2nodes work like ordinary bst 
left lower right higher 
3nodes left must be less right must be greater and center must be between 
4nodes - same but two center, left center - greater than left but less than right center 

L<lC<RC<R 

search remains Ologn because there are a constant number of permutations 

insertion is easy when dealing with 2nodes and 3nodes 

split fournodes on the way down 

lava is dr gerbers natural enemy 
mc pro 


make sure we dont have any 4 nodes between ourselves and the root 
		  if the root is a 2node you are deleting 
		  if the root is a twonode and both of its children are 2nodes
