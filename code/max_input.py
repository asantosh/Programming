#!/bin/python

n = long(raw_input())
k = long(raw_input())
l = 0

for i in range(0, n) :
	j = long(raw_input())
	if (j % k == 0) :
		l += 1

print l
