#!/usr/bin/python3


while True:
    print("1.Add 2.Subtract 3.Multiply 4.Divide 5.Quit")
    op=int(input())
    num1=float(input("Num1:"))
    num2=float(input("Num2:"))
    if op==1:
        res=str(num1+num2)
        print("Result:"+res)
    elif op==2:
        res=str(num1-num2)
    elif op==3:
        res=str(num1*num2)
    elif op==4:
        res=str(num1/num2)
    elif op==5:
        break
    else:
        print("Unknown option")
print("Result:"+res)
