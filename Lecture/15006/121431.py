def solution(text, anagram, sw):
    textTmp = list(text)
    
    if sw:
        for i in range(len(text)):
            textTmp[anagram[i]] = text[i]
        
    else:
        for i in range(len(text)):
            textTmp[i] = text[anagram[i]]

    return "".join(textTmp)