#define PIN_LE 10 //LE(CA1)
#define PIN_CLK 11
#define PIN_SDI 9
#define PIN_OE 7

void setup() {
  pinMode(PIN_LE, OUTPUT);
  pinMode(PIN_CLK, OUTPUT);
  pinMode(PIN_SDI, OUTPUT);
  pinMode(PIN_OE, OUTPUT);

  setBrightness(brightness);
}

void loop() {
  digitalWrite(PIN_LATCH, LOW);
  // диоды не горят
  shiftOut(PIN_DAI, PIN_CLOCK, LSBFIRST, 0b00000000);
  shiftOut(PIN_DAI, PIN_CLOCK, LSBFIRST, 0b00000000);
  digitalWrite(PIN_LATCH, HIGH);
  delay(40);
}

void doClock() {
  digitalWrite(PIN_CLOCK, HIGH);
  digitalWrite(PIN_CLOCK, LOW);
}

// value = 0...127
void setBrightness(byte value) {
  digitalWrite(PIN_LATCH, LOW);
  digitalWrite(PIN_CLOCK, LOW);

  digitalWrite(PIN_LATCH, LOW);
  digitalWrite(PIN_OE, HIGH);
  doClock();
  digitalWrite(PIN_OE, LOW);
  doClock();
  digitalWrite(PIN_OE, HIGH);
  doClock();
  digitalWrite(PIN_LATCH, HIGH);
  doClock();
  digitalWrite(PIN_LATCH, LOW);
  doClock();
  
  shiftOut(PIN_DAI, PIN_CLOCK, LSBFIRST, value);  
  digitalWrite(PIN_LATCH, HIGH);
  digitalWrite(PIN_LATCH, LOW);
  digitalWrite(PIN_OE, HIGH);
  doClock();
  digitalWrite(PIN_OE, LOW);
  doClock();
  digitalWrite(PIN_OE, HIGH);
  doClock();
  doClock();
  doClock();

  digitalWrite(PIN_LATCH, LOW);
  digitalWrite(PIN_CLOCK, LOW);
  digitalWrite(PIN_OE, LOW);
}
