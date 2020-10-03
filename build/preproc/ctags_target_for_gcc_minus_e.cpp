# 1 "d:\\line-following-robot\\src\\app\\app.ino"
# 2 "d:\\line-following-robot\\src\\app\\app.ino" 2
# 3 "d:\\line-following-robot\\src\\app\\app.ino" 2

void setup()
{
  Serial.begin(9600);
  pinMode(2, 0x1);
  pinMode(3, 0x1);
  digitalWrite(2, 0x0);
  digitalWrite(3, 0x0);
  // pinMode(PIN_SENSOR1, INPUT);
  // pinMode(PIN_SENSOR2, INPUT);
}

void loop()
{
  // Serial.println(digitalRead(PIN_SENSOR1));
  //Serial.println(digitalRead(SENSORPIN2));
  delay(200);
}
