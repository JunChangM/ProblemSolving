import math
N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = 0
for x in a:
    ans = ans + math.ceil(x/b[0])

print(ans)

print(N//b[1], N % b[1])