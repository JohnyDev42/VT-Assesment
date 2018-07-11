#!/usr/bin/python3

try:
    print("Hello")
    print(7/0)
except ZeroDivisionError:
    print(Unknown)
except NameError:
    print("Undefined Var")
finally:
    print("Finish")
