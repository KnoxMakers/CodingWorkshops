#define PIN_SPEAKER       9
#define PIN_BUTTON        8
#define PIN_BUILTIN_LED  13


void setup(){
  pinMode(PIN_BUILTIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}


void loop(){

  if (digitalRead(PIN_BUTTON) == LOW){
      digitalWrite(PIN_BUILTIN_LED, HIGH);
      delay(500);
      digitalWrite(PIN_BUILTIN_LED, LOW);
  }
}
