import string
import re
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

GPIO.setwarnings(False)

GPIO.setup(7, GPIO.OUT)
GPIO.setup(11, GPIO.OUT)
GPIO.setup(13, GPIO.OUT)
GPIO.setup(15, GPIO.OUT)
GPIO.setup(29, GPIO.OUT)
GPIO.setup(31, GPIO.OUT)
GPIO.setup(33, GPIO.OUT)
GPIO.setup(35, GPIO.OUT)
GPIO.setup(37, GPIO.OUT)

values = {
	'k':7,
	'n':11,
	'o':13,
	'x':15,
	'm':29,
	'a':31,
	'e':33,
	'r':35,
	's':37,
}		
def cls(): print ("\n" * 13)
center = 30
while True:
	cls()
	cls()
	print "                                    Strange Code"
	print "                                   by Knox Makers"
	print " "
	print "                                    sponsored by:"
	print "                            Hawkins National Laboratories"
	print "                               Hawkins Power and Light"
	cls()
	word = str(raw_input("Enter a word: ").lower())
	if re.match("^[k,n,o,x,m,a,e,r,s]*$", word):
		cls()
		cls()
		print "                   Spooky.. looks like something is starting to happen.."
		cls()
		time.sleep(2)
		GPIO.output(31,True)
		time.sleep(.3)
		GPIO.output(31,False)
		GPIO.output(33,True)
		time.sleep(.3)
		GPIO.output(33,False)
		GPIO.output(7,True)
		time.sleep(.3)
		GPIO.output(7,False)
		GPIO.output(29,True)
		time.sleep(.3)
		GPIO.output(29,False)
		GPIO.output(11,True)
		time.sleep(.3)
		GPIO.output(11,False)
		GPIO.output(13,True)
		time.sleep(.3)
		GPIO.output(13,False)
		GPIO.output(35,True)
		time.sleep(.3)
		GPIO.output(35,False)
		GPIO.output(37,True)
		time.sleep(.3)
		GPIO.output(37,False)
		GPIO.output(15,True)
		time.sleep(.3)
		GPIO.output(15,False)
		time.sleep(.2)
		GPIO.output(15,True)
		time.sleep(.2)
		GPIO.output(15,False)
		time.sleep(1)
		if word == ("knoxmakers"):
			cls()
			cls()
			print "                      What did you do? Something is happening.." 	
			cls()
			time.sleep(2)
			cls()
			cls()
			print "                                      Uh oh.."
			cls()
	else:
		if not re.match("^[k,n,o,x,m,a,k,e,r,s]*$", word):
			cls()
			cls()
			print "        Hmm.. Due to a strange force, only the letters AEKMNORSX are allowed."
			cls()
			time.sleep(4)
			cls()
			cls()
			cls()
			continue


	for i in range (len(word)):
			GPIO.output((values[word[i]]),True)
			time.sleep(2)
			if word == ("knoxmakers"):
				if (values[word[i]]) == 7:
					cls()
					cls()	
					print "                          Did you hear that? I'm scared.."
					cls()
				elif (values[word[i]]) == 11:
					cls()
					cls()
					print "                         No, I definitely heard something."
					cls()
				elif (values[word[i]]) == 13:
					cls()
					cls()
					print "                         What did you do?! That noise.."
					cls()
				elif (values[word[i]]) == 15:
					cls()
					cls()
					print "           That must have been a secret code, I wish you hadn't typed that in."
					cls()
				elif (values[word[i]]) == 29:
					cls()
					cls()
					print "                      I can hear it, it is much louder now.."
					cls()
				elif (values[word[i]]) == 31:
					cls()
					cls()
					print "                           Oh no, it's almost here!"
					cls()
				elif (values[word[i]]) == 33:
					cls()
					cls()
					print "                        I can hear words! That voice.."
					cls()
				elif (values[word[i]]) == 35:
					cls()
					cls()
					print "                                   It's saying.."
					cls()
				elif (values[word[i]]) == 37:
					cls()
					cls()
					print "'...Be sure to drink your Ovaltine?' Ovaltine?? A crummy commercial? Son of a bitch."
					cls()
					time.sleep(5)
			GPIO.output((values[word[i]]),False)
			time.sleep(1)

GPIO.cleanup()


