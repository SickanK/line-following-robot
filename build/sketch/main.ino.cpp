#line 1 "d:\\line-following-robot\\src\\main\\main.ino"
#line 1 "d:\\line-following-robot\\src\\main\\main.ino"
#include <Arduino.h>
#include "./Pins.h"

#line 4 "d:\\line-following-robot\\src\\main\\main.ino"
void setup();
#line 15 "d:\\line-following-robot\\src\\main\\main.ino"
void loop();
#line 4 "d:\\line-following-robot\\src\\main\\main.ino"
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_SENSOR1, OUTPUT);
  pinMode(PIN_SENSOR2, OUTPUT);
  digitalWrite(PIN_SENSOR1, LOW);
  digitalWrite(PIN_SENSOR2, LOW);
  // pinMode(PIN_SENSOR1, INPUT);
  // pinMode(PIN_SENSOR2, INPUT);
}

void loop()
{
  // Serial.println(digitalRead(PIN_SENSOR1));
  //Serial.println(digitalRead(SENSORPIN2));
  delay(200);
}

