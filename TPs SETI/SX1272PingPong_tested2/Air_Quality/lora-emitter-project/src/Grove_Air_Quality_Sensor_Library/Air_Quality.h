#ifndef AIR_QUALITY_H
#define AIR_QUALITY_H

#include <Arduino.h>

class Air_Quality {
public:
    Air_Quality(int pinVsensor, int pinVheater);
    void init();
    float readAirQuality();
    float avgVoltage();

private:
    int _pinVsensor;
    int _pinVheater;
};

#endif // AIR_QUALITY_H