sack = {'1':30, '2':30, '3':30,}
posts = 30

print 'post  sack1  sack2  sack3'

for i in range(posts):
    
    if sack.get('1') > 0:
        sack['1'] = sack.get('1') - 1
        
    if sack.get('2') > 0:
        sack['2'] = sack.get('2') - 1
        
    if sack.get('3') > 0:
        sack['3'] = sack.get('3') - 1
    
    if sack.get('1',0) + sack.get('2',0) <= 30 and sack.get('1') > 0 and sack.get('2') > 0 :
        sack['1'] = sack.get('1') + sack.get('2')
        sack['2'] = 0
       
    if sack.get('2',0) + sack.get('3',0) <= 30 and sack.get('2') > 0 and sack.get('3') > 0 :
        sack['2'] = sack.get('2') + sack.get('3')
        sack['3'] = 0
       
    if sack.get('1',0) + sack.get('3',0) <= 30 and sack.get('1') > 0 and sack.get('3') > 0 :
        sack['1'] = sack.get('1') + sack.get('3')
        sack['3'] = 0
        
    print str(i+1) +'    '+ str(sack.get('1'))+'    '+ str(sack.get('2'))+'    '+ str(sack.get('3'))