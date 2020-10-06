#include "app.h"

LineSensor lineSensor1(PIN_SENSOR_LINE_1);
LineSensor lineSensor2(PIN_SENSOR_LINE_2);

MotorController motor1(PIN_MOTOR_BIN_1, PIN_MOTOR_BIN_2, PIN_MOTOR_PWMB, PIN_MOTOR_STBY, -1);
MotorController motor2(PIN_MOTOR_AIN_1, PIN_MOTOR_AIN_2, PIN_MOTOR_PWMA, PIN_MOTOR_STBY, 1);
Engine engine(motor1, motor2);

void app(LineSensor lineSensorLeft, LineSensor lineSensorRight, Engine engine)
{
  // Read sensor signal
  lineSensorLeft.setReading(digitalRead(lineSensorLeft.pin));
  lineSensorRight.setReading(digitalRead(lineSensorRight.pin));

  // Check for derailment
  while (lineSensorLeft.getReading())
  {
    lineSensorLeft.setReading(digitalRead(lineSensorLeft.pin));
    engine.stopTurn(255, engine.right);
    delay(500);
  };

  while (lineSensorRight.getReading())
  {
    lineSensorRight.setReading(digitalRead(lineSensorRight.pin));
    engine.stopTurn(255, engine.left);
    delay(500);
  };

  // Begin drive again
  engine.drive(255);
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  app(lineSensor1, lineSensor2, engine);
  delay(800);
}
