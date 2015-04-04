#problem 2_1

balance = 4213
annualInterestRate = 0.2
monthlyPaymentRate = 0.04
totalPaid = 0
        
for i in range(12) :
    minPay = monthlyPaymentRate * balance
    totalPaid += minPay
    balance = balance - minPay
    intAmt = balance * annualInterestRate / 12.0
    balance = balance + intAmt
      
    print('Month: ' + str(i+1))
    print('Minimum monthly payment: ' + '%.2f' % minPay)
    print('Remaining balance: ' + '%.2f' % balance)

print('Total paid: '+ '%.2f' % totalPaid)
print('Remaining balance: ' + '%.2f' % balance)