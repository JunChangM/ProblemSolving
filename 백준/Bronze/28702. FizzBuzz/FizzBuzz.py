x= []
for i in range(3):
    x.append(input())
    
for i in range(3):
    if x[i].isdigit():
        flag = False
        ans = int(x[i]) + ( 2 - i ) + 1
        if ans % 5 == 0 and ans % 3 == 0:
            print("FizzBuzz")
        elif  ans % 5 == 0:
             print("Buzz")
        elif  ans % 3 == 0:
             print("Fizz")
        else:
            print(ans)
        break;