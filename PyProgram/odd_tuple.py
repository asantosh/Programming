Input = ('I', 'am', 'a', 'test', 'tuple')
Output = ()

for i in range(len(Input)):
    if( (i+1) % 2 != 0) :
        Output += ((Input)[i],)
   
    
print Output