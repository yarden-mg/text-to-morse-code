
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  


  const int ledPin = 4;
  const int dotTime = 200;
  const char* morseLeng[26] = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.."
  };

void blinkSymbol(char symbol) {
  digitalWrite(ledPin, HIGH);
  if (symbol == '.') {
    delay(dotTime);
    }
  else if (symbol == '-') {
    delay(dotTime*3)
  }
  digitalWrite(ledPin ,LOW);
  delay(dotTime)
  }

  void sendMorseLetter (const char* morseCode) {
    for (int i = 0; morseCode[i] != '\0'; i++) {
      blinkSymbol(morseCode[i]);
    }
    delay(dotTime*2);

  }

void loop() {
  if (Serial.available() > 0) {
    char letter = Serial.read();
    if(letter >= 'A' && letter <= 'Z') {
      letter = letter + 32;
    }
    if (letter >= 'a' && letter <= 'z') {
     int index = letter - 97;
     sendMorseLetter(morseAlphabet[index]);  
    }
  else if (letter == ' ') {
    delay(dotTime*6);
  }
}
}
