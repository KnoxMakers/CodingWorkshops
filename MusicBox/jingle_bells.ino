//##############################################################################
// SETUP PINS
//
// PIN_BUZZER and PIN_BUTTON define which pins on the PC Board connect to the speaker and the push button
// These can be assigned to other pins as desired
#define PIN_SPEAKER        9
#define PIN_BUTTON        8


// PIN_BUILTIN_LED is 13 so as to use the LED built into the Arduino hardware
// if you reassign it, you'll need to add an external LED on the pin you chose
#define PIN_BUILTIN_LED  13


//##############################################################################
// This function runs once each time the Arduino is powered up
// For this project we just need to configure the GPIO pins we'll be using
void setup(){
  
  pinMode(PIN_BUILTIN_LED, OUTPUT);
  pinMode(PIN_SPEAKER, OUTPUT);
  
  // PIN_BUTTON gets connected to ground when the pushbutton is
  // pressed. We put the pin in INPUT_PULLUP mode, pulling the pin weakly HIGH.
  // When the button is pressed, the pin will be shorted to ground,
  // pulling it strongly LOW.
  pinMode(PIN_BUTTON, INPUT_PULLUP);

}

//##############################################################################
// This function runs over and over forever after setup() finishes
void loop(){
  
  // PIN_BUTTON will only be LOW if the button is being pressed.
  if (digitalRead(PIN_BUTTON) == LOW){
        play_jingle_bells();
  }
}


//##############################################################################
// SETUP TEMPO
// This defines the speed at which the song plays. TEMPO=60 means 60 BPM or 60 quarter notes per minute
#define TEMPO 175


//##############################################################################
// NOTE DURATION SETUP
// Rather than typing in the duration of each note (e.g. 250 for 250 milliseconds)
// we associate musical notation such as whole, half, quarter, eighth and sixteenth notes
#define QUARTER 60000/TEMPO
#define HALF QUARTER*2
#define WHOLE HALF*2
#define EIGHTH QUARTER/2
#define SIXTEENTH EIGHTH/2
#define HALF_DOT HALF*3/2
#define QUARTER_DOT QUARTER*3/2
#define EIGHTH_DOT EIGHTH*3/2
#define SIXTEENTH_DOT SIXTEENTH*3/2


//##############################################################################
// SETUP MUSICAL NOTES
// rather than remembering/typing the correct frequency for each note,
// we associate musical note names with their frequencies.
// that lets us use the names in place of the numbers.
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
#define MID_BFLAT       466
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

void play_jingle_bells(){

  // this deifnes the number of notes in the array below
  int note_count = 106;

  #define FREQUENCY 0
  #define DURATION 1

  int jingle_bells[note_count][2] = {
    {MID_C, QUARTER},
    {MID_A, QUARTER},    
    {MID_G, QUARTER},
    {MID_F, QUARTER},
    {MID_C, HALF_DOT},  
    {MID_C, EIGHTH},
    {MID_C, EIGHTH},
    {MID_C, QUARTER},
    {MID_A, QUARTER},
    {MID_G, QUARTER},
    {MID_F, QUARTER},
    {MID_D, HALF_DOT},
    {SILENCE, QUARTER},  
    {MID_D, QUARTER},
    {MID_BFLAT, QUARTER},
    {MID_A, QUARTER},
    {MID_G, QUARTER},
    {MID_E, HALF_DOT},
    {SILENCE, QUARTER},
    {HI_C, QUARTER},
    {HI_C, QUARTER},
    {MID_BFLAT, QUARTER},
    {MID_G, QUARTER},
    {MID_A, HALF_DOT},
    {SILENCE, QUARTER},
    {MID_C, QUARTER},
    {MID_A, QUARTER},    
    {MID_G, QUARTER},
    {MID_F, QUARTER},
    {MID_C, HALF_DOT},  
    {SILENCE, QUARTER},
    {MID_C, QUARTER},
    {MID_A, QUARTER},
    {MID_G, QUARTER},
    {MID_F, QUARTER},
    {MID_D, HALF_DOT},
    {MID_D, QUARTER},
    {MID_D, QUARTER},
    {MID_BFLAT, QUARTER},
    {MID_A, QUARTER},
    {MID_G, QUARTER},
    {HI_C, QUARTER},
    {HI_C, QUARTER},
    {HI_C, QUARTER},
    {HI_C, EIGHTH},
    {HI_C, EIGHTH},
    {HI_D, QUARTER},
    {HI_C, QUARTER},
    {MID_BFLAT, QUARTER},
    {MID_G, QUARTER},
    {MID_F, HALF},
    {HI_C, HALF},
    
    // Start Jingle Bells Refrain    
    {MID_A, QUARTER},
    {MID_A, QUARTER},
    {MID_A, HALF},
    {MID_A, QUARTER},
    {MID_A, QUARTER},
    {MID_A, HALF},
    {MID_A, QUARTER},
    {HI_C, QUARTER},
    {MID_F, QUARTER_DOT},
    {MID_G, EIGHTH},    
    {MID_A, WHOLE},

    {MID_BFLAT, QUARTER},
    {MID_BFLAT, QUARTER},
    {MID_BFLAT, QUARTER_DOT},
    {MID_BFLAT, EIGHTH},
    {MID_BFLAT, QUARTER},
    {MID_A, QUARTER},
    {MID_A, QUARTER},
    {MID_A, EIGHTH},
    {MID_A, EIGHTH},
    {MID_A, QUARTER},
    {MID_G, QUARTER},
    {MID_G, QUARTER},
    {MID_A, QUARTER},
    {MID_G, HALF},
    {HI_C, HALF},

    {MID_A, QUARTER},
    {MID_A, QUARTER},
    {MID_A, HALF},
    {MID_A, QUARTER},
    {MID_A, QUARTER},
    {MID_A, HALF},
    {MID_A, QUARTER},
    {HI_C, QUARTER},
    {MID_F, QUARTER_DOT},
    {MID_G, EIGHTH},    
    {MID_A, WHOLE},

    {MID_BFLAT, QUARTER},
    {MID_BFLAT, QUARTER},
    {MID_BFLAT, QUARTER_DOT},
    {MID_BFLAT, EIGHTH},
    {MID_BFLAT, QUARTER},
    {MID_A, QUARTER},
    {MID_A, QUARTER},
    {MID_A, EIGHTH},
    {MID_A, EIGHTH},
    {HI_C, QUARTER},
    {HI_C, QUARTER},
    {MID_BFLAT, QUARTER},
    {MID_G, QUARTER},
    {MID_F, WHOLE},

    {SILENCE, WHOLE}
  };

  // variable "i" is our position within the "jingle_bells" structure
  for (int i=0; i<note_count; i++){

    // if this particular note isn't SILENCE, turn on the LED and emit a tone at FREQUENCY
    if (jingle_bells[i][FREQUENCY] != SILENCE){
      digitalWrite(PIN_BUILTIN_LED, HIGH);
      tone(PIN_SPEAKER, jingle_bells[i][FREQUENCY]);
    }

    // The DURATION of the note is broken up into two slices, the tone itself and a small bit of silence.
    // This small bit of quiet time appears between notes and makes the music sound more natural
    //   slice 1: for 7/8 of the DURATION the tone is emitted
    //   slice 2: for 1/8 of the DURATION the speaker is silent

    // The following line is a fast way to do a divide by 8 and assigns 1/8 of the duration to "quiet_time"
    int quiet_time = jingle_bells[i][DURATION]>>3;

    // wait for the prescribed DURATION to elapse (slice 1)
    delay(jingle_bells[i][DURATION] - quiet_time);
    
    // extinguish the LED and silence the buzzer
    digitalWrite(PIN_BUILTIN_LED, LOW);
    noTone(PIN_SPEAKER);
    
    // wait for the quiet time before moving to the next NOTE
    delay(quiet_time);
  }  
}

//##############################################################################
