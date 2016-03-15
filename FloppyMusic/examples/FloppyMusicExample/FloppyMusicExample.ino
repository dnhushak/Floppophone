// Use FloppyMusic by Tyler Bletsch (Tyler.Bletsch@gmail.com) to play a few songs.

#include "pitches.h"
#include <TimerOne.h> // FloppyMusic requires the TimerOne library (http://playground.arduino.cc/code/timer1)
#include <FloppyMusic.h>

FloppyMusic f1(A15,A14); // DIRECTION, STEP
FloppyMusic f2(A13,A12); // DIRECTION, STEP
FloppyMusic f3(A11,A10); // DIRECTION, STEP
FloppyMusic f4(A9,A8); // DIRECTION, STEP
FloppyMusic f5(A7,A6); // DIRECTION, STEP
FloppyMusic f6(A5,A4); // DIRECTION, STEP

int melody_starwars[] = {
  NOTE_C2, 12,  // note, duration (8=eighth note, etc.)
  NOTE_C2, 12,
  NOTE_C2, 12,
  NOTE_F2, 2, 
  NOTE_C3, 2, 
  NOTE_AS2, 12,
  NOTE_A2, 12,
  NOTE_G2, 12,
  NOTE_F3, 2,
  NOTE_C3, 4,
  NOTE_AS2, 12,
  NOTE_A2, 12,
  NOTE_G2, 12,
  NOTE_F3, 2,
  NOTE_C3, 4,
  NOTE_AS2, 12,
  NOTE_A2, 12,
  NOTE_AS2, 12,
  NOTE_G2, 2,
};
int n_melody_starwars = sizeof(melody_starwars)/sizeof(*melody_starwars);

int melody_ptg[] = {
  0,       8,
  NOTE_A2, 8,
  NOTE_D2, 8,
  NOTE_F2, 8,
  NOTE_A2, 4, 
  NOTE_G3, 4, 
  NOTE_F2, 4,  
  
  0,       8,
  NOTE_A2, 8,  // note, duration (8=eighth note, etc.)
  NOTE_D2, 8,
  NOTE_F2, 8,
  NOTE_C3, 4, 
  NOTE_AS2, 4, 
  NOTE_A2, 4,
};
int n_melody_ptg = sizeof(melody_ptg)/sizeof(*melody_ptg);

int melody_shave[] = {
  NOTE_C4, 4, 
  NOTE_G3, 8, 
  NOTE_G3, 8, 
  NOTE_A3, 4, 
  NOTE_G3, 4, 
  0,       4, 
  NOTE_B3, 4, 
  NOTE_C4, 4,
};
int n_melody_shave = sizeof(melody_shave)/sizeof(*melody_shave);

void play_song(int melody[], int num_notes) {
  for (int i=0; i<num_notes; i+=2) {
    int note = melody[i];
    int duration = 1500/melody[i+1];

    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    f1.set_freq(note);
    f2.set_freq(note*2);
    f3.set_freq(note/2);
    f4.set_freq(note);
    f5.set_freq(note*2);
    f6.set_freq(note*2);
    delay(duration);

    int pauseBetweenNotes = duration / 3;
    f1.set_freq(0);
    f2.set_freq(0);
    f3.set_freq(0);    
    f4.set_freq(0);
    f5.set_freq(0);
    f6.set_freq(0);
    delay(pauseBetweenNotes);

  }
}

void setup() {
  Serial.begin(9600);  
  Serial.println("SETUP init");
  f1.begin();
  f2.begin();
  f3.begin();
  f4.begin();
  f5.begin();
  f6.begin();
  delay(300);
}

void loop() {
//  Serial.println("Playing 'Shave and a Haircut'");
//  play_song(melody_shave,n_melody_shave);
//  delay(500);
  
  play_song(melody_ptg,n_melody_ptg);
  delay(500);
}



