int BUTTON = 12;
int buttonState;
int freq = 2000;
        
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON);
  if (buttonState == HIGH) {
    freq = 500;
    
  } else {
    //digitalWrite(LED, LOW);
    freq= 1000;
  }  
  
    digitalWrite(LED, HIGH);
    delay(freq);
    digitalWrite(LED, LOW);
    delay(freq);
}
