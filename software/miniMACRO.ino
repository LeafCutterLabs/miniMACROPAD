 /*
led removed from pin 1 due to input issues
button0 is closest to USB
key values https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkKeyboard/DigiKeyboard.h
*/

#include "DigiKeyboard.h"

//pins 3 & 4 used for usb connection
bool buttonState0 = 0;
bool buttonState1 = 0;
bool buttonState2 = 0;
bool buttonState3 = 0;

void setup() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(5, INPUT);
  digitalWrite(0, HIGH); //turn on pull-up resistor
  digitalWrite(1, HIGH); //turn on pull-up resistor
  digitalWrite(2, HIGH); //turn on pull-up resistor
  digitalWrite(5, HIGH); //turn on pull-up resistor
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  if ((digitalRead(0) != buttonState0)||(digitalRead(1) != buttonState1)||(digitalRead(2) != buttonState2)||(digitalRead(5) != buttonState5)){
    DigiKeyboard.delay(5); //debounce delay, see if its a true reading
    
    //button 0
    if (digitalRead(0)!= buttonState0){
      buttonState0 = digitalRead(0);
      if (buttonState0 == LOW) DigiKeyboard.sendKeyStroke(KEY_Z, MOD_CONTROL_LEFT); //ctrl Z
    }
    
    //button 1
    if (digitalRead(2)!= buttonState1){
      buttonState1 = digitalRead(2);
      if (buttonState1 == LOW) DigiKeyboard.sendKeyStroke(KEY_Y, MOD_CONTROL_LEFT); //ctrl Y
    }
    
    //button 2
    if (digitalRead(1)!= buttonState2){
      buttonState2 = digitalRead(1);
      if (buttonState2 == LOW) DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT); //ctrl C 
    }
    
    //button 3
    if (digitalRead(5)!= buttonState3){
      buttonState3 = digitalRead(5);
      if (buttonState3 == LOW) DigiKeyboard.sendKeyStroke(KEY_V, MOD_CONTROL_LEFT); //ctrl V 
    }
  }
}
