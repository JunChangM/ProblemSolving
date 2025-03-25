n = int(input())
arr = [0] * n
for i in range(n):
    arr[i] = list(map(int, input().split()))
    
for i in range(n):
    for j in range(n):
        for k in range(n):
            if arr[j][i] and arr[i][k]:
                arr[j][k] = 1

for row in arr:
    print(' '.join(map(str, row)))