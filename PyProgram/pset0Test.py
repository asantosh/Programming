x = 12345
epsilon = 0.01
high = x
low = 0
guess = (high + low )/ 2.0
count = 0

while abs(guess**2 - x) >= epsilon:
    count += 1
    print(str(count) + '  ' + str(guess))

    if guess**2 < x :
        low = guess
    else :
        high = guess
     
    guess = (high + low )/ 2.0

print('guess :' + str(guess))