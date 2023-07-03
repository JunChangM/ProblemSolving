# 1이 될 때까지
# 단순 구현이 아닐까 한다. 나누어 질 수 있을 때만 나눈다.

def go_one():
    n,k = map(int, input().split())
    count = 0
    # case 1 : k로 나누어 지면 나누고, 아니면 -1
    # while n != 1:
    #     if n % k == 0:
    #         n /= k
    #         count += 1
    #     else:
    #         n -= 1
    #         count += 1


    # case 2 : 효율적인 -1 연산을 위해서 계산을 통해 한번에 빼도록 한다.
    while n != 1:
        value = int(n % k) # value 가 0 이면 아래 연산은 아무런 영향을 미치지 않는다. if 문과 비교 해서 무엇이 더 비용이 높은지는 모르겠다.
        n -= value
        count += value

        if n != 1:
            n /= k
            count += 1

    print(count)


if __name__ == '__main__':
    go_one()

