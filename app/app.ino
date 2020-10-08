#include "app.h"

LineSensor lineSensor1(PIN_SENSOR_LINE_1);
LineSensor lineSensor2(PIN_SENSOR_LINE_2);

UltrasonicSensor ultrasonicSensor(PIN_SENSOR_ULTRASONIC_TRIGGER, PIN_SENSOR_ULTRASONIC_ECHO, 100000);

MotorController motor2(PIN_MOTOR_BIN_1, PIN_MOTOR_BIN_2, PIN_MOTOR_PWMB, PIN_MOTOR_STBY, 1);
MotorController motor1(PIN_MOTOR_AIN_1, PIN_MOTOR_AIN_2, PIN_MOTOR_PWMA, PIN_MOTOR_STBY, 1);
Engine engine(motor1, motor2);

void app(LineSensor lineSensorLeft, LineSensor lineSensorRight, Engine engine)
{
  // Read sensor signal
  lineSensorLeft.setReading();
  lineSensorRight.setReading();

  engine.drive(200);

  // Check for derailment
  while (lineSensorRight.getReading() == 0)
  {
    engine.stopTurn(100, engine.right);
    delay(50);
    lineSensorRight.setReading();
  };

  while (lineSensorLeft.getReading() == 0)
  {
    engine.stopTurn(100, engine.left);
    delay(50);
    lineSensorLeft.setReading();
  };

}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  app(lineSensor1, lineSensor2, engine);
  delay(1);
}
