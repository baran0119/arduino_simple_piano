/*
 * Simple one-octave piano
 * Source of frequencies:   https://www.arduino.cc/en/Tutorial/Melody
 *
 * No.  note  f, [Hz]         T, [us]       T/2, [us]
 *           (frequency) 	 (period (1/f)) (half of period)
 * 1    c     261             3830          1915
 * 2    d     294             3400          1700
 * 3    e     329             3038          1519
 * 4    f     349             2864          1432
 * 5    g     392             2550          1275
 * 6    a     440             2272          1136
 * 7    b     493             2028          1014
 * 8    C     523             1912          956
 * 
 */

int pinOut = 9;
static int i = 0;
int notes[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

void play(int pin);

void setup() {
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(pinOut, OUTPUT);
}

void loop() {
  for ( i = 1 ; i < 9 ; i++)
    if ( digitalRead(i) == LOW )
      play(i);
}

void play(int pin) {
  digitalWrite(pinOut, HIGH);
  delayMicroseconds(notes[pin - 1]);
  digitalWrite(pinOut, LOW);
  delayMicroseconds(notes[pin - 1]);
}