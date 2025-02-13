class Air_Quality {
public:
    Air_Quality(int pin1, int pin2);
    void init();
    float avgVoltage();
    int getAirQualityIndex();

private:
    int _pin1; // Vsensor
    int _pin2; // Vheater
    float _slope;
};

Air_Quality::Air_Quality(int pin1, int pin2) : _pin1(pin1), _pin2(pin2), _slope(0.0) {}

void Air_Quality::init() {
    pinMode(_pin1, INPUT);
    pinMode(_pin2, OUTPUT);
    digitalWrite(_pin2, HIGH); // Activate heater
}

float Air_Quality::avgVoltage() {
    float total = 0.0;
    for (int i = 0; i < 10; i++) {
        total += analogRead(_pin1);
        delay(10);
    }
    return total / 10.0;
}

int Air_Quality::getAirQualityIndex() {
    // Implement the logic to calculate air quality index based on sensor readings
    // This is a placeholder implementation
    return static_cast<int>(avgVoltage() * 100 / 1023); // Example conversion
}