n = int(input())
arr = list(map(int, input().split()))

ans = 0
left = 0
count = [0] * 10
distinct_count = 0

for right in range(n):
    if count[arr[right]] == 0:
        distinct_count += 1
    count[arr[right]] += 1
    # print(arr[right])
    while distinct_count > 2:
        count[arr[left]] -= 1
        if count[arr[left]] == 0:
            distinct_count -= 1
        left += 1
    # print(count)
    ans = max(ans, right - left + 1)
# print (left, right)
print(ans)