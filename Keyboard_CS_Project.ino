
#include "pitches.h"

int pin13 = 13;
int pin2 = 2;
int pin8 = 8;
int piezoPin = 4;
int buttonState13 = 0;
int buttonState8 = 0;
int buttonState2 = 0;


int notes[] = {
NOTE_G4, NOTE_A4, NOTE_B4
};


void setup() {
  // put your setup code here, to run once:
pinMode (pin2, INPUT);
pinMode (pin8, INPUT);
pinMode (pin13, INPUT);
pinMode(piezoPin, OUTPUT);
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState13 = digitalRead (pin13);
if ((buttonState13 == HIGH))
 {tone(piezoPin, notes[0]);
Serial.println ("13");
 }
  buttonState8 = digitalRead (pin8);
  if((buttonState8 == HIGH))
 { tone(piezoPin, notes[1]);
  Serial.println ("8");
 }
  buttonState2 = digitalRead (pin2);
  if (buttonState2 == HIGH)
  {Serial.println ("2");
  tone(piezoPin, notes[2]);
  }
  if ((buttonState13==LOW)&&(buttonState8==LOW)&&(buttonState2==LOW))
{Serial.println ("all off");
noTone (piezoPin);
}
delay (100);
}
