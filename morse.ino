
const led_pin = LED_BUILTIN;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void dot {
  digitalWrite(ledPin, HIGH);
  delay(1000);
}
void dash {
  digitalWrite(ledPin, HIGH);
  delay(3000);
}

void R() {
  dot();
  dash();
  dot();
}
void A() {
  dot();
  dash();
}
void H() {
  dot();
  dot();
  dot();
  dot();
}
void U() {
  dot();
  dot();
  dash();
}
void L() {
  dot();
  dash();
  dot();
  dot();
}
void loop() {

  R();
  A();
  H();
  U();
  L();
}
