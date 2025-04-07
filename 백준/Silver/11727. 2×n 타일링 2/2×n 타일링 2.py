# 11727 : 2 * n tiling 2

n = int(input())

# n 이 1일때 1
# n 이 2일때 3
# n 이 3일때 5
# f(n) 을 n일 때의 타일 수 라고 하자.
# f(4) = f(3) + f(2) * 2 = 11
# f(k) = f(k-1) + f(k-2) * 2

if n == 1:
    print(1)
elif n == 2:
    print(3)
else:
    dp = [0] * (n + 1)
    dp[1] = 1
    dp[2] = 3
    for i in range(3, n + 1):
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007
    print(dp[n])
