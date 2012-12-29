#!/usr/local/bin/python3
import time 

amicable = {}
divisors = {} 
abundant = [] 
#r = 28123
r=1000

startabund = time.time()
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
		sumation += j
	if(sumation > i):
		abundant.append( i )
stopabund = time.time()

startsummed = time.time()
summed = [] 
notsum = [] 
l = len(abundant)
for j in range(l):
	for k in range(j, l):
		summed.append(abundant[j]+abundant[k])
s = set(summed)

for i in range(r):
	if( not i in s):
		notsum.append(i)

summation = 0
for i in notsum:
	summation += i
stopsummed = time.time()
print("Sum: ", summation)
t1 = stopabund - startabund
t2 = stopsummed - startsummed
tt = t1 + t2
print("Total time: {:.3} Abundant: {:.3} ({:.0%}) summed:  {:.3} ({:.0%})".format(tt, t1, t1/tt, t2, t2/tt))

