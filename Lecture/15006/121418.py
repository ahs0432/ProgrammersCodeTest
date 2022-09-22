def solution(num_list):
    answer = []
    
    for i in num_list:
        check = True
        
        if i > 1:
            for j in range(2, i // 2 + 1):
                if i % j == 0:
                    check = False
                    break
        
        answer.append(check)
    
    return answer