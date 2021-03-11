int analogPin = A0;
float val = 0;
int LED_13 = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_13, OUTPUT);
}

void loop()
{
  val = analogRead(analogPin);
  Serial.print("Voltaje: ");
  val = val*5/1023;
  Serial.println(val);
  
  if(val >= 3){
    digitalWrite(LED_13, HIGH);
  }else{
    digitalWrite(LED_13, LOW);
  }
}