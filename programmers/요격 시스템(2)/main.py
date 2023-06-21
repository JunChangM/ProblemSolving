'''
최소의 미사일로 폭격 미사일 요격
2차원 : 폭격 미사일 x축 , 요격 미사일 y축으로 날아감
각 폭격 미사일의 x 좌표의 범위 목록 targets : (start,end)

1. start 좌표가 기준이 되는 s와 e 사이에 존재하는 경우의 교집합을 찾아가면서 풀어보려고 하였다. test case는 통과할 수 있었지만 모든 case에 대해서는 실패하였다.
이중 배열 정렬에 미숙했던 부분이 있었고, key를 통해 조건을 추가하였다.

2. 기준을 end로 계산 하였을 때, continue와 같은 예외처리를 할 필요가 없기 때문에 end를 기준으로 정렬 후 end를 넘어서는 경우 새로운 미사일을 쏘는 형식으로 구현하였다.
'''

def solution(targets):
    answer = 0
    
    targets.sort(key = lambda x : [x[1],x[0]]) # end (x[0])를 기준으로 정렬
    
    end = 0

    for x1, x2 in targets:
        if x1 >= end:
            answer+=1
            end = x2

    
    return answer
