def isWordGuessed(secretWord, lettersGuessed):
    for char1 in secretWord :
        found = 0
        for char2 in lettersGuessed :          
            if char1 == char2 :
                found = 1
                break
        if found != 1:
            return False
    return True
	
def getGuessedWord(secretWord, lettersGuessed):
    printStr = ''
    for ch in secretWord:
        if isWordGuessed(ch, lettersGuessed) == True :
            printStr += ch
        else :
            printStr += '_ '
    return printStr
	
def getAvailableLetters(lettersGuessed):
    import string
    printStrnew = string.ascii_lowercase
    for char in lettersGuessed :
        printStr = printStrnew
        printStrnew = ''
        for ch in printStr:
            if char != ch :
                printStrnew += ch
    return printStrnew
    
def hangman(secretWord):
    print 'Welcome to the game, Hangman!'
    print 'I am thinking of a word that is '+ str(len(secretWord)) + ' letters long.'
    print '-------------'
    found = 0
    mistakesMade = 0
    lettersGuessed = ''
    availableLetters = ''
    while mistakesMade < 8:
        print 'You have ' + str(8-mistakesMade) + ' guesses left.'
        print 'Available letters: ' + getAvailableLetters(availableLetters)
        letter = raw_input('Please guess a letter: ')
        letter = letter.lower()
        
        if isWordGuessed(letter, availableLetters) == True :
            print "Oops! You've already guessed that letter: " + getGuessedWord(secretWord, lettersGuessed)
            print '------------'
            continue
        availableLetters += letter
        
        for ch in secretWord:
            if ch == letter:
                lettersGuessed += ch
                print 'Good guess: ' + getGuessedWord(secretWord, lettersGuessed)
                found = 1
                break
        if found != 1:
            print 'Oops! That letter is not in my word: ' + getGuessedWord(secretWord, lettersGuessed)
            mistakesMade += 1
        else :
            found = 0
            
        print '------------'
        if isWordGuessed(secretWord, lettersGuessed) == True:
            print 'Congratulations, you won!'
            break
    if isWordGuessed(secretWord, lettersGuessed) == False:
        print 'Sorry, you ran out of guesses. The word was '+ secretWord + '.'
        
import ps3_hangman
#word = ps3_hangman.chooseWord()
hangman('asdfadsf')
            