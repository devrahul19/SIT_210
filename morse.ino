const int buttonPin = 3;
const int ledPin = 12;

int buttonState = LOW;
int lastButtonState = LOW;
bool blinking = false;
const char* name = "Vasudha"; 
int nameLength = strlen(name);

// Define Morse code for each letter (A-Z)
const char* morseCode[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
  "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      blinking = !blinking; // Toggle blinking state
      if (blinking) {
        blinkName();
      } else {
        digitalWrite(ledPin, LOW); // Turn off LED if blinking is stopped
      }
    }
    lastButtonState = buttonState;
  }
}

void blinkMorseCharacter(const char* morseCharacter) {
  for (int i = 0; morseCharacter[i] != '\0'; i++) {
    if (morseCharacter[i] == '.') {
      digitalWrite(ledPin, HIGH);
      delay(200); // Dot duration
    } else if (morseCharacter[i] == '-') {
      digitalWrite(ledPin, HIGH);
      delay(600); // Dash duration
    }
    digitalWrite(ledPin, LOW);
    delay(200); // Gap between dots and dashes
  }
}

void blinkName() {
  for (int i = 0; i < nameLength; i++) {
    char letter = toupper(name[i]);
    if (letter >= 'A' && letter <= 'Z') {
      int index = letter - 'A';
      if (index >= 0 && index < 26) {
        const char* morse = morseCode[index];
        blinkMorseCharacter(morse);
      }
      delay(600); // Gap between letters
}
}
}
