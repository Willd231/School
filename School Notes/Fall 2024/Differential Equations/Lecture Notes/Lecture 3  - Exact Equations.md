 A differential equation is exact if it can be written in the form:
 ∂M/∂y(M) = ∂N/∂x(N)
 
 Basically, take the partial derivative with respect to y on the first part of the equation with the dx attached and then take the partial derivative with respect to x of the second half

 Following this: we take the M part of the Equation and integrate with respect to x or if you are using N because it is easier, with respect to y

 And since we declared this equation to be exact we are saying that the integral of either side plus some function should equal the other side ie: integral (M) + g(y) = N 

 The final step is to take the derivative of the whole thing with respect to whatever is inside g - should be opposite of M
 and then u should get 
 M + g'(y) = N
 then all you need to do is solve for g'(y) by integrating and then place g(y) in the original for M+g(y) = N and then reduce it to whatever form u are looking for

Examples:
1. (2x+3y)dx + (3x+2y)dy = 0 
		∂M/∂y = 3
		∂N/∂x = 3
		Therefore exact 
		∫M = x^2 + 3yx + g(y)
		3x + g'(y) = 3x + 2y
		g(y) = y^2
	therefore the answer to this exact ode is x^2+3xy+y^2 = 0		
ig u dont add on the N at the end, that is definitely what made all of us fail this test

