#problem 2_3

balance = 999999
annualInterestRate  = 0.18
lowPay = (balance * ( 1 + annualInterestRate ))/ 12.0
highPay = (balance * ( 1 + annualInterestRate ) ** (1 / 12.0)) / 12.0
minPay = (lowPay + highPay) / 2.0
iteration = 0

def checkBal(minPay, Bal):
    for i in range(12) :
        unpaid = Bal - minPay
        Bal = unpaid + unpaid * annualInterestRate / 12.0
    
    return Bal

while (True) :
    iteration += 1
    newBal = checkBal(minPay, balance)        

    if(round(lowPay) == round(highPay)):
        break
    elif(newBal < 0):
        lowPay = minPay
    else :
        highPay = minPay
    
    minPay = (lowPay + highPay) / 2
    print(str(lowPay) + ' ' + str(minPay) + ' ' + str(highPay) )

print('')
print(iteration)    
print('Lowest Payment: ' + '%.2f' %minPay)
