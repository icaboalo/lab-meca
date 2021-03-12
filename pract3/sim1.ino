//Pines
int VRx = A0;
int VRy = A1;
int SW = 5;

float x = 0;
float y = 0;
float mapSW = 0;
float mapX = 0;
float mapY = 0;

bool useX = true;

float previousX = 0;
float previousY = 0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
}

void loop() {
  previousX = mapX;
  previousY = mapY;
  x = analogRead(VRx);
  y = analogRead(VRy);
  mapSW = digitalRead(SW);
  mapX = map(x, 0, 1023, -1, 1);
  mapY = map(y, 0, 1023, -1, 1);

  if (mapSW == 0) {
    useX = !useX;
  }

  if (useX && previousX != mapX) {
    Serial.print(" X: ");
    Serial.print(mapX);
    Serial.print(" Y: ");
    Serial.print(0);
    /*Serial.print(" Boton: ");
    Serial.println(mapSW);*/
  }/* else {
    Serial.print(" X: ");
    Serial.print(previousX);
  }*/

  if (!useX && previousY != mapY) {
    Serial.print(" X: ");
    Serial.print(0);
    Serial.print(" Y: ");
    Serial.print(mapY);
  }/* else {
    Serial.print(" Y: ");
    Serial.print(previousY);
  }
  */

  if (previousX != x || previousY != y) {
    Serial.println();
  }

  //delay(50);
}

float map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}