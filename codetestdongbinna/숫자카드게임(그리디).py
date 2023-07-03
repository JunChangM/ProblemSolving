# 숫자 카드 게임
# while getting input, select the minimum value in the line and compare the bigger value

def bigger():
    n,m = map(int, input().split())
    max_num = 0
    for i in range(n):
        data = list(map(int,input().split()))
        min_num = min(data)
        
        if max_num < min_num: # we can change this part : max_num = max(max_num,min_num) 
            max_num = min_num

    print(max_num)


if __name__ == '__main__':
    bigger()

