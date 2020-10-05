#include "app.h"

LineSensor line_sensor1(PIN_SENSOR_LINE_1);
LineSensor line_sensor2(PIN_SENSOR_LINE_2);

Motor motor1(PIN_MOTOR_BIN_1, PIN_MOTOR_BIN_2, PIN_MOTOR_PWMB, PIN_MOTOR_STBY, -1);
Motor motor2(PIN_MOTOR_AIN_1, PIN_MOTOR_AIN_2, PIN_MOTOR_PWMA, PIN_MOTOR_STBY, 1);
Engine engine(motor1, motor2);

void app(LineSensor line_sensor_left, LineSensor line_sensor_right)
{
  line_sensor_left.setReading(digitalRead(line_sensor_left.pin));
  line_sensor_right.setReading(digitalRead(line_sensor_right.pin));
  
  Serial.println(line_sensor_left.getReading());
  Serial.println(line_sensor_right.getReading());
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  app(line_sensor1, line_sensor2);
  delay(2000);
  
}
