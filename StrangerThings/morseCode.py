import string
import re
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

GPIO.setwarnings(False)

GPIO.setup(7, GPIO.OUT)

values = {
	'a':1,
	'b':2,
	'c':3,
	'd':4,
	'e':5,
	'f':6,
	'g':7,
	'h':8,
	'i':9,
	'j':10,
	'k':11,
	'l':12,
	'm':13,
	'n':14,
	'o':15,
	'p':16,
	'q':17,
	'r':18,
	's':19,
	't':20,
	'u':21,
	'v':22,
	'w':23,
	'x':24,
	'y':25,
	'z':26,
}		

def dot():
	GPIO.output(7,True)
	time.sleep(.1)
	GPIO.output(7,False)
	time.sleep(.1)
def dash():
	GPIO.output(7,True)
	time.sleep(.3)
	GPIO.output(7,False)
	time.sleep(.1)
while True:		
	word = str(raw_input("Enter a word: ").lower())
	if re.match("^[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]*$", word):

		for i in range (len(word)):

				if (values[word[i]]) == 1:
					dot()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 2:
					dash()
					dot()
					dot()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 3:
					dash()
					dot()
					dash()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 4:
					dash()
					dot()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 5:
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 6:
					dot()
					dot()
					dash()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 7:
					dash()
					dash()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 8:
					dot()
					dot()
					dot()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 9:
					dot()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 10:
					dot()
					dash()
					dash()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 11:
					dash()
					dot()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 12:
					dot()
					dash()
					dot()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 13:
					dash()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 14:
					dash()
					dot()	
					time.sleep(.2)
				elif (values[word[i]]) == 15:
					dash()
					dash()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 16:
					dot()
					dash()
					dash()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 17:
					dash()
					dash()
					dot()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 18:
					dot()
					dash()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 19:
					dot()
					dot()
					dot()
					time.sleep(.2)
				elif (values[word[i]]) == 20:
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 21:
					dot()
					dot()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 22:
					dot()
					dot()
					dot()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 23:
					dot()
					dash()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 24:
					dash()
					dot()
					dot()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 25:
					dash()
					dot()
					dash()
					dash()
					time.sleep(.2)
				elif (values[word[i]]) == 26:
					dash()
					dash()
					dot()
					dot()
					time.sleep(.2)

	else:
		if not re.match("^[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]*$", word):
			continue

GPIO.cleanup()


