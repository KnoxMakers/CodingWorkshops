#!/usr/local/bin/python3
import sys

amicable = {}
divisors = {} 
abundant = [] 

#Maximum range
#r = 28123
r=1000

#Find and store abundant numbers
for i in range(r):
	if(i==0):
		continue
	d = 2
	divisors = {}
	while(d <= (i/2)):
		if (( i % d ) == 0 ):
			divisors[d] = d
		d += 1

	sumation = 1 
	for j in divisors:
		if(i==997):
			print(i, j)
		sumation += j
	if(sumation > i):
		abundant.append( i )


#For each number in our testing range, iterate over possible combinations of
#abundant numbers when summed will equal the current test number. If they are
#equal mark the number to be *not* stored. 
notsum = [] 
l = len(abundant)
for i in range(r):
	summed = False
	for j in range(l):
		for k in range(j, l):
			if( i == (abundant[j]+abundant[k]) ):
				summed = True
	if( not summed ):
		notsum.append(i)

#Sum the 
summation = 0
for i in notsum:
	summation += i
print("Sum: ", summation)
