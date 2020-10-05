#include <Arduino.h>

class LineSensor
{
public:
    int pin;
    // Constructor to setup pin
    LineSensor(int sensorPin);

    // Get internal reading variable
    int getReading() const { return internal_reading; };

    // Set internal reading variable
    // @params reading - reading value from sensor
    void setReading(int reading);

protected:
        int internal_reading = 0;
};
