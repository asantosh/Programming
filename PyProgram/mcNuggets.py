def McNuggets(n):
    for a in range(100):
        for b in range(100):
            for c in range(100):
                if (6*a + 9*b + 20*c) == n:
                    return True
    return False
    
print McNuggets(16)