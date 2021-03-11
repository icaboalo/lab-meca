int G1 = 13;
int Y1 = 12;
int R1 = 11;
int G2 = 10;
int Y2 = 9;
int R2 = 8;
int buttonState;
int freq = 5000;

void setup() {
pinMode(G1, OUTPUT);
pinMode(Y1, OUTPUT);
pinMode(R1, OUTPUT);
pinMode(G2, OUTPUT);
pinMode(R2, OUTPUT);
pinMode(Y2, OUTPUT);
Serial.begin(9600);
}

void loop() {
    digitalWrite(Y2, LOW);
    digitalWrite(Y1, LOW);
    digitalWrite(G2, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(G1, HIGH);
    digitalWrite(R2, HIGH);
    delay(freq);
    digitalWrite(G1, LOW);
    digitalWrite(Y1, HIGH);
    delay(freq/5);
    digitalWrite(Y1, LOW);
    digitalWrite(G2, HIGH);
    digitalWrite(R1, HIGH);
    delay(freq);
    digitalWrite(G2, LOW);
    digitalWrite(Y2, HIGH);
    delay(freq/5);
}