#define PIN_SENSOR1 2
#define PIN_SENSOR2 3

void setup() {
  Serial.begin(9600);
  pinMode(PIN_SENSOR1, INPUT);
  pinMode(PIN_SENSOR2, INPUT);
}

void loop() {
  Serial.println(digitalRead(PIN_SENSOR1));
  //Serial.println(digitalRead(SENSORPIN2));
  delay(200);    
}
