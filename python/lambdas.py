#!/usr/bin/python3

#named function>>>
def polyn(x):
    return x**2 + x*3 + 1

print("function Calling:",polyn(-4))

#lambda function>>>

print("lambda Calling:",(lambda x:x**2 + x*3 + 1)(-4))

lamfun = (lambda x:x*x)

print(lamfun(-2))
