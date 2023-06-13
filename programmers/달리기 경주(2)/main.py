def solution(players, callings):
    
    # Time Out : for 문을 돌면서 index를 찾는 cost가 높음.
    # for name in callings:
    #     index = players.index(name)
    #     temp = players[index]
    #     players[index] = players[index-1]
    #     players[index-1] = temp
    
    # 2개의 dictionary를 이용. enumerate 사용하여 index를 등수로 사용.
    i = { index : name for index, name in enumerate(players)} # order -> name
    n = { name : index for index, name in enumerate(players)} # name -> order
    
    for name in callings:
        current_order = n[name] # 현재 등수
        forward_order = current_order - 1 # 앞의 등수
        forward_name = i[forward_order] # 앞 사람의 이름
        
        # swap
        i[forward_order] = name # name의 위치를 한 칸 전진
        i[current_order] = forward_name # 앞 사람의 이름을 한 칸 후진
        n[name] = forward_order # name의 위치 한 칸 전진
        n[forward_name] = current_order # 앞 사람의 위치 한 칸 후진
    
    answer = [i[order] for order in range(0,len(players))] # 등수에 맞게 answer 만들기.
    return answer
