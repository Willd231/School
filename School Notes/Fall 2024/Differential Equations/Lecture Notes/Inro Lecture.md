What is a differential equation? 
A differential equation is an equation containing the derivatives of one or more independent variables. 

$$
x^2 + 5x +4 = 0

$$
unknown is x
$$
y'' + 5y' + 4y = 0
$$
unknown is f(x)


there are 3 main types of differential equations: 
linear, nonlinear, and partial

First Order
$$
dy/dx + 5y = e^x
$$
Second Order
$$
d^2y/dx^2 + dy/dx + 6y = 0
$$
Third Order (the squaring is only a square)
$$
(d^3y/dx^2)^2 + dy/dx = 0
$$

A partial differential equation is a differential equation that contains partial derivatives

This example is a second order partial DE
$$
∂^2u/∂x^2 + ∂u/∂x = 0 
$$


Another way to classify differential equations is by linearity 

A linear ODE has the form: 

$$
a_n(x)dy/dx + a_{n-1}(x)d^{n-1}y/dx^{n-1} + ...+a_1(x)dy/dx+a_0 = g(x)
$$
you can tell if an ODE is nonlinear if there are powers on the independent variable ie: 
$$
dy/dx = y^2 + x
$$
There are products of the dependent variable and its derivatives ie:
$$
d^2y/dx^2 + ydy/dx = sin(x)
$$
The dependent variable or its derivatives are inside of a nonlinear function ie: sin..
ie:
$$
d^2y/dx^2 + y dy/dx = sin(x)
$$We use ODES to model real life situations where an object is changing in some way

Ex: Population Dynamics
The rate of change of a population depends on the population at the current time 
$$
dp/dt = k*p
$$
Radioactive decay:
$$
dA/dt = kA
$$
Newtons Law of Cooling:
$$
dT/dt = k * (T-T_u)
$$

Disease spread: The rate at which a disease spreads is proportional to the number of people infected and the number of people who have not been exposed yet
$$
dx/dt = kxy
$$


The next topic at hand is how to solve differential equations. This will take the entire course to answer! Today the solution will be provided and we will verify it.
Ex. Verify that 
$$
y = x^4/16
$$
is a solution to the ode 
$$
dy/dx = xy^{1/2}
$$
left side = 
$$
dy/dx = 4x^3/16 = x^3/4
$$
Right side : 
$$
xy^{1/2} = x * x^2/4 = x^3/4
$$
as required 

Ex. Verify that 
$$
y = xe^x 
$$
is a solution to the ode 
$$
y'' - 2y' + y = 0 
$$
$$
y = xe^x
$$
$$
y' = x + xe^x
$$
$$
y'' = e^x = e^x + xe^x 
$$
substituting in 
$$
= 2e^x + xe^x - 2(e^x + xe^x) + xe^x
= xe^x - 2e^x - 2xe^x + xe^x
= xe^x - 2xe^x + xe^x 
= 0
$$
Therefore
$$
y=xe^x
$$
is a solution to the ODE

Example 2:
Verify that the implicit solution 
$$
x^2 + y^2 = 25
$$
solves the ode:
$$
dy/dx = -x/y
$$
first differentiate :
$$
2x + 2x*dy/dx = 0

$$
then just use algebra to simplify:
$$
=-x/y
$$
therefore the solution is correct 