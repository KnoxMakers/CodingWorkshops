//##############################################################################
// SETUP PINS

// PIN_BUZZER and PIN_BUTTON are arbitrary; you can reassign them and connect
// the buzzer and/or button to different pins
#define PIN_BUZZER        9
#define PIN_BUTTON        8
// PIN_BUILTIN_LED is 13 so as to use the LED built into the Arduino hardware
// if you reassign it, you'll need to add an external LED on the pin you chose
#define PIN_BUILTIN_LED  13

//##############################################################################
// SETUP MUSICAL NOTES
// rather than remembering/typing the correct frequency for each note,
// we associate musical note names with their frequencies. that lets us use
// the names in place of the numbers.

#define SILENCE           0
#define LO_C            156
#define LO_D            165
#define LO_E            175
#define LO_F            185
#define LO_G            196
#define LO_GSHARP       208
#define LO_A            220
#define LO_ASHARP       233
#define LO_B            246
#define MID_C           261
#define MID_D           294
#define MID_E           329
#define MID_F           349
#define MID_G           391
#define MID_GSHARP      415
#define MID_A           440
#define MID_ASHARP      466
#define MID_B           494
#define HI_C            523
#define HI_CSHARP       554
#define HI_D            587
#define HI_DSHARP       622
#define HI_E            659
#define HI_F            698
#define HI_FSHARP       740
#define HI_G            784
#define HI_GSHARP       830
#define HI_A            880
#define HI_HI_C         1026

//##############################################################################

// these constants will be used to address the individual song structures later.
// the structures will have two "slots" defining each note:
// the FREQUENCY to be played will be stored in slot 0
#define FREQUENCY         0
// and the DURATION to play the note will be stored in slot 1
#define DURATION          1

//##############################################################################

void setup(){
  // This function runs once, when the Arduino first powers up.
  // For this project, we just have to configure the GPIO pins we'll be using.
  
  pinMode(PIN_BUILTIN_LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  
  // PIN_BUTTON gets connected to ground when a normally-open pushbutton is
  // pressed. We put the pin in INPUT_PULLUP mode, pulling the pin weakly HIGH.
  // When the button is pressed, the pin will be shorted to ground,
  // pulling it strongly LOW.
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  
}

//##############################################################################

void loop(){

  // PIN_BUTTON will only be LOW if the button is being pressed.
  if (digitalRead(PIN_BUTTON) == LOW){
      play_fur_elise();
  }

}

//##############################################################################

void play_fur_elise(){

  int note_count = 40;
  int fur_elise[note_count][2] = {
    {HI_E,      200},
    {HI_DSHARP, 200},    
    {HI_E,      200},
    {HI_DSHARP, 200},    
    {HI_E,      200},
    {MID_B,     200},    
    {HI_D,      200},    
    {HI_C,      200},    
    {MID_A,     580},
    {SILENCE,    20},
    {MID_C,     200},    
    {MID_E,     200},    
    {MID_A,     200},    
    {MID_B,     580},    
    {SILENCE,    20},
    {MID_E,     200},    
    {MID_GSHARP,200},    
    {MID_B,     200},    
    {HI_C,      580},    
    {SILENCE,    20},
    {MID_E,     200},
    {HI_E,      200},
    {HI_DSHARP, 200},    
    {HI_E,      200},
    {HI_DSHARP+1, 200},     // A very strange bug occurs without the +1 where this tone doesn't play properly
    {HI_E,      200},
    {MID_B,     200},    
    {HI_D,      200},    
    {HI_C,      200},    
    {MID_A,     580},
    {SILENCE,    20},
    {MID_C,     200},    
    {MID_E,     200},    
    {MID_A,     200},    
    {MID_B,     580},    
    {SILENCE,    20},
    {MID_E,     200},    
    {HI_C,      200},    
    {MID_B,     200},    
    {MID_A,     1000}
  };

  // variable "i" is our position within the "fur_elise" structure
  for (int i=0; i<note_count; i++){

    // if this particular note isn't SILENCE, turn on the LED and emit a tone at FREQUENCY
    if (fur_elise[i][FREQUENCY] != SILENCE){
      digitalWrite(PIN_BUILTIN_LED, HIGH);
      tone(PIN_BUZZER, fur_elise[i][FREQUENCY]);
    }
    // wait for the prescribed DURATION to elapse
    delay(fur_elise[i][DURATION]);
    // extinguish the LED and silence the buzzer
    digitalWrite(PIN_BUILTIN_LED, LOW);
    noTone(PIN_BUZZER);
    // wait just a moment before moving to the next NOTE
    delay(50);
  }  
}

//##############################################################################
