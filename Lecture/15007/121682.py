def solution(n, board, position):
    answer = []
    
    picks = [[0, 1], [1, 0], [1, 1], [0, -1], [-1, 0], [-1, -1], [1, -1], [-1, 1]]
    
    for p in position:
        check = 0
        lensX = len(board) - 1
        lensY = len(board[0]) - 1
        
        for pick in picks:
            if (p[0] + pick[0] < 0) or (p[0] + pick[0] > lensX) or (p[1] + pick[1] < 0) or (p[1] + pick[1] > lensY):
                continue
            
            check += board[p[0] + pick[0]][p[1] + pick[1]]
        
        if board[p[0]][p[1]] == 0:
            answer.append(1 if (check == 2) else 0)
        else:
            answer.append(0 if ((check <= 2) or (check >= 5)) else 1)
    
    return answer