def myLog(x, b):
    min = 0
    x = round(abs(x))
    b = round(abs(b))
    if x == 0 or x == 1:
        return 0
    for i in range(1,x):
        if b ** i <= x :
            min = i            
    return min

print myLog(0.2,2)