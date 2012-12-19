#!/usr/bin/python



x = range(1,1000)
woot = 0

for i in x:
	if not i%3 or not i%5:
	   print i, "is a multiple of 3 or 5"
	   #woot += i
	   woot = woot + i

print "Total:",woot
	






