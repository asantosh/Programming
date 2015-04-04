#problem 2_2

balance = 320000
annualInterestRate  = 0.2
lowPay= 0
count = 0
while (True) :
    count += 1
    lowPay += 10
    newBal = balance
    i = 0
    
    for i in range(12) :
        unpaid = newBal - lowPay
        newBal = unpaid + unpaid * annualInterestRate / 12

    if(newBal <= 0):
        break
print(count)
print('Lowest Payment: ' + str(lowPay))
