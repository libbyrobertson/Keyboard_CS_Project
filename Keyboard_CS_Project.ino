
#include "pitches.h"
#include "ardumidi.h"
int pin13 = 13;
int pin2 = 2;
int pin8 = 8;
int piezoPin = 4;
int buttonState13 = 0;
int buttonState8 = 0;
int buttonState2 = 0;
int note_on = 0;

int notes[] = {
NOTE_G4, NOTE_A4, NOTE_B4
};


void setup() {
  // put your setup code here, to run once:
pinMode (pin2, INPUT);
pinMode (pin8, INPUT);
pinMode (pin13, INPUT);
pinMode(piezoPin, OUTPUT);
Serial.begin (115200);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState13 = digitalRead (pin13);
if ((buttonState13 == HIGH))
 {//tone(piezoPin, notes[0]);
  Serial.write ("13");
  midi_note_on(0, MIDI_G, 127);//playing the G

 }
  buttonState8 = digitalRead (pin8);
  if((buttonState8 == HIGH))
 { //tone(piezoPin, notes[1]);
  Serial.write ("8");
  midi_note_on(0, MIDI_A, 127);//playing the A
  
 }
  buttonState2 = digitalRead (pin2);
  if (buttonState2 == HIGH)
  {Serial.write ("2");
  midi_note_on(0, MIDI_B, 127);
  //tone(piezoPin, notes[2]);
  }
 else if ((buttonState13==LOW)&&(buttonState8==LOW)&&(buttonState2==LOW))
{Serial.write ("all off");
midi_note_off(0,MIDI_G,127);
midi_note_off(0,MIDI_A,127);
midi_note_off(0,MIDI_B,127);
//noTone (piezoPin);
}
delay (100);
}
