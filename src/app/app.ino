#include <Arduino.h>
#include "libraries/Pins.h"

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
