# Keyboard_CS_Project

 - Elizabeth Robertson
 - 200351424
 - October 24 2015

This is the repository for my Project.
In this project I'm going to make music. 


# Overview
This project will convert a toy piano to play different music using MIDI
  - User will press a button and sound will come from the computer
  - User can switch between different music modes using a 3 position switch
  - With each different switch a different set of sounds will be played
  - Music is played through a Serial to Midi converter and using a music Application

# Goals
 - Have six sets of MIDI sounds
 - have led connected to the buttons as well although this may be in the distant future
 - I wish to add a Memory or recording feature in the future. 

# Critique
I am very much learning as I go and so much of the code is commented out at this point.I still plan on gaing knowledge on the MIDI system and being able to add much more to the code.

# Known Issues
The first buttons has had its wire cut.
I am still trying to get more Midi notes in the midi library.

# Source Code
-Download Keyboard_CS_Project.ino
-Download ardumidi.cpp
-Download ardumidi.h
-Upload the code to the board
-Download hairless Serial to Midi Serial bridge for your platform
-If using a PC will need to download loopMidi as well and create a specific port 
-Using whatever music program you have connect it to the Midi port through input
-Run all programs
-Turn on Serial to Midi bridge on the hairless converter

#Hardware
To use this project one needs the specific hacked chidlren's keyboard connected to an Arduino uno associated with this project. The arduino must be attached to a computer via USB cable. 
 - Simply press the button and it will play if the proper software is in place. 



