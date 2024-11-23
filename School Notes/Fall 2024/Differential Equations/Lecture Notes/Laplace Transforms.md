Laplace transforms are used to convert ODES to algebraic equations 
ie: y'' - y' - 6y = 0, y(0) = 2 , y'(0) = -1

turns into 
(s^2 - s - 6) Y(s) - 2s + 3 = 0

notation = L{f(t)} = F(s)
input function f(t) -> output function F(s)

F(S) = integral(0, infinity){e^(-st)f(t) dt}