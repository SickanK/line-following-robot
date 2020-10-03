#include "app.h"

void setup()
{
  Serial.begin(9600);

  // LED TEST
  pinMode(PIN_SENSOR_LINE_1, OUTPUT);
  pinMode(PIN_SENSOR_LINE_2, OUTPUT);

  // PROD
  // pinMode(PIN_SENSOR1, INPUT);
  // pinMode(PIN_SENSOR2, INPUT);
}

void loop()
{
}
