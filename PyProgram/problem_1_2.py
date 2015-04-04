# count number of occurence of bob

s = 'bobbsbobobbobobboobhbobobobobodwobooctoboouboxob'
count = 0
for i in range(len(s)) :
    if s[i] == 'b' :
        if i+1 < len(s):
            if s[i+1] == 'o' :
                if i+2 < len(s):        
                    if s[i+2] == 'b' :     
                        count += 1
        
print('Number of times bob occurs is: '+ str(count))