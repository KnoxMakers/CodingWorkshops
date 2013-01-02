#!/usr/local/bin/python3
from decimal import *
import sys

#Set the precision to 100 decimal digits
getcontext().prec = 100

#Sum the 100 digits of the sqrt of the number passed in. Number before the
#decimal point will always be 0 (sqrt%1). Count code can be u 
def sumdig(n):
	summation = 0
	d = str(Decimal(n).sqrt()%1)
	count = 0
	for j in range(2,101):
		if(j <= len(d)):
			count += 1
			summation += int(d[j])
	#print("count ",count)
	return summation

sum2 = 0
for i in range(1, 100):
	s = sumdig(i)
	sum2 += s
	print(i, s, sum2, Decimal(i).sqrt())

print(sum2)
