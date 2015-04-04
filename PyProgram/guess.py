#guess the users number

print('Please think of a number between 0 and 100!')
high = 100
low = 0
ans = (high + low) / 2

while True:
    print('Is your secret number ' + str(ans) + '?')
    input = raw_input("Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly. ")
    if input == 'c' :
        print("Game over. Your secret number was:" +  str(ans))
        break;
    elif input == 'l':
        low = ans
        
    elif input == 'h':
        high = ans
        
    else :
        print("Sorry, I did not understand your input.")

    ans = (high + low) / 2