#problem 2_2

def checkPay(minPay, newBal):
    totalPaid = 0
    for i in range(12) :
        newBal -= minPay
        intAmt = balance * annualInterestRate / 12
        newBal += intAmt
    print(newBal)
    return newBal

balance = 3329
annualInterestRate = 0.2
minPay = annualInterestRate * balance / 12
iteration = 1
remain = 101
while (remain >= 0) :
    if(remain < 100 ):
        break
    iteration += 1
    minPay += 10
    remain = checkPay(minPay, balance)
    

print(iteration)    
print('Lowest Payment: ' + '%d ' % minPay + ' ' + str(remain))