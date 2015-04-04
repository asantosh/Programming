#Write a program that prints the longest substring of s in which the letters
#occur in alphabetical order

s = 'abcbcd'
ss_pos = 0
ss_len = 1
ss_len_max = 0

for i in range(len(s)) :
    ss_len = 1

    for j in range(i, len(s)) :
        if j+1 < len(s) and s[j] <= s[j+1] :
                ss_len += 1
        else :
            break
               
    if ss_len > ss_len_max :
        ss_len_max = ss_len
        ss_pos = i

print(s[ss_pos : ss_pos+ss_len_max])