# 큰 수의 법칙
# M번 더하여 가장 큰 수 만들기, 같은 수를 최대 연속으로 K번 더할 수 있다.

def bigger():
    # input 받기, map 과 list 이용
    n, m, k = map(int, input().split())
    data = list(map(int, input().split()))
    data.sort() # 오름차순 정렬 => 내림차순은 reverse=ture 이용
    first = data[-1]
    second = data[-2]

    # case 1 : while 문을 이용하여 하나씩 더하기
    # s = 0
    # while m > 0:
    #     for i in range(k):
    #         s += first
    #         m -= 1
    #
    #     if m != 0:
    #         s += second
    #         m -= 1

    # case 2 : 하나의 cycle을 기준으로 계산하기
    s = first * k + second # 한 번의 cycle 에서 더하는 수
    answer = (m // (k+1)) * s + first * (m % (k+1)) # cycle 수 * s + 남은 횟수
    print(answer)


if __name__ == '__main__':
    bigger()

