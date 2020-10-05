#include "app.h"

LineSensor lineSensor1(PIN_SENSOR_LINE_1);
LineSensor lineSensor2(PIN_SENSOR_LINE_2);

Motor motor1(PIN_MOTOR_BIN_1, PIN_MOTOR_BIN_2, PIN_MOTOR_PWMB, PIN_MOTOR_STBY, -1);
Motor motor2(PIN_MOTOR_AIN_1, PIN_MOTOR_AIN_2, PIN_MOTOR_PWMA, PIN_MOTOR_STBY, 1);
Engine engine(motor1, motor2);

void app(LineSensor lineSensorLeft, LineSensor lineSensorRight)
{
  lineSensorLeft.setReading(digitalRead(lineSensorLeft.pin));
  lineSensorRight.setReading(digitalRead(lineSensorRight.pin));

  Serial.println(lineSensorLeft.getReading());
  Serial.println(lineSensorRight.getReading());
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  app(lineSensor1, lineSensor2);
  delay(2000);
}
