def solution(serial):
    answer = ''
    
    if serial[0:2] == "01":
        answer += 'male/'
    else:
        answer += 'female/'
    
    tmp = serial[2:4]
    
    if tmp == "10":
        answer += 'operation/'
    elif tmp == "11":
        answer += 'sales/'
    elif tmp == "12":
        answer += 'develop/'
    elif tmp == "13":
        answer += 'finance/'
    elif tmp == "14":
        answer += 'law/'
    elif tmp == "15":
        answer += 'research/'
        
    answer += str(int(serial[4:6])) + 'team/'
    
    tmp = int(int(serial) / 100)
    vaild = 0
    
    while(tmp != 0):
        vaild += (tmp % 10)
        tmp = int(tmp / 10)
    
    answer += ("valid" if (vaild % 13) == int(serial[6:8]) else "invalid")

    return answer