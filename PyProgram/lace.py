def laceStrings(s1, s2):
    char = ''
    remStr = ''
    length = 0
    if len(s1) < len(s2) :
        length = len(s1)
        remStr = s2[length:]
    else :
        length = len(s2)
        remStr = s1[length:]    
    for i in range(length):
        char += s1[i]
        char += s2[i]
    
    char += remStr    
    return char
    
print laceStrings('','')