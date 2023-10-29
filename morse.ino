int buttonPin = 2;
int ledPin = LED_BUILTIN;
int dotDuration = 250;   // Dot duration in milliseconds
int dashDuration = 750;  // Dash duration in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor for the button
}

void blinkDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);  // Gap between dots and dashes
}

void blinkDash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);  // Gap between dots and dashes
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    // R
    blinkDot();
    blinkDash();
    blinkDot();
    delay(1000);

    // A
    blinkDot();
    blinkDash();
    delay(1000);

    // H
    blinkDot();
    blinkDot();
    blinkDot();
    blinkDot();
    delay(1000);

    // U
    blinkDot();
    blinkDot();
    blinkDash();
    delay(1000);

    // L
    blinkDot();
    blinkDash();
    blinkDot();
    blinkDot();
    delay(1000);
  }
}
