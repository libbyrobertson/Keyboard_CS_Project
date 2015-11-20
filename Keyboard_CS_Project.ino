/*
Elizabeth Robertson
200351424

LAst update
November 18 2015



*/
#include "pitches.h"
#include "ardumidi.h"


int pin13 = 13;
int pin2 = 2;
int pin8 = 8;
int piezoPin = 4;
int Spin9 = 9;
int Spin7 = 7;


int buttonState13 = 0;
int buttonState8 = 0;
int buttonState2 = 0;
int switchState9 = 0;
int switchState7 = 0;

int switch_on = 0;
int note_on = 0;

int notes[] = {
NOTE_G4, NOTE_A4, NOTE_B4
};

int midiNotes[]=
{
  MIDI_C,MIDI_D,MIDI_E,MIDI_F,MIDI_G,MIDI_A,MIDI_B,MIDI_SHARP,MIDI_FLAT
};
void setup() {
  // put your setup code here, to run once:
pinMode (pin2, INPUT);
pinMode (pin8, INPUT);
pinMode (pin13, INPUT);
pinMode(Spin9,INPUT);
pinMode(Spin7, INPUT);
pinMode(piezoPin, OUTPUT);
Serial.begin (115200);
//Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

switchState9 = digitalRead(Spin9);
switchState7 = digitalRead(Spin7);

if ((switchState9 == HIGH)&&(switchState7==LOW))
{switch_on = 0;
//Serial.println("1");
}
if((switchState9==LOW)&&(switchState7 == LOW))
{switch_on = 3;
//Serial.println("2");
}
if ((switchState9 == LOW)&&(switchState7 == LOW))
{switch_on = 6;
//Serial.println("3");
}


buttonState13 = digitalRead (pin13);
if (buttonState13 == HIGH)
 {//tone(piezoPin, notes[0]);
  Serial.write ("13");
  midi_note_on(0, midiNotes[switch_on], 127);//playing the G

 }
  buttonState8 = digitalRead (pin8);
  if(buttonState8 == HIGH)
 { //tone(piezoPin, notes[1]);
  Serial.write ("8");
  midi_note_on(0, midiNotes[switch_on + 1], 127);//playing the A
  
 }
  buttonState2 = digitalRead (pin2);
  if (buttonState2 == HIGH)
  {Serial.write ("2");
  midi_note_on(0, midiNotes[switch_on + 2], 127);
  //tone(piezoPin, notes[2]);
  }
 else if ((buttonState13==LOW)&&(buttonState8==LOW)&&(buttonState2==LOW))
{Serial.write ("all off");
for (int num = 0; num < 9; num++)
midi_note_off(0,midiNotes[num],127);
//noTone (piezoPin);
}
delay (100);
}
