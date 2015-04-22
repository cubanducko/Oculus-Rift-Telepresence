#ifndef servoHandler_h
#define servoHandler_h

#include <iostream>

using namespace std;

class servoHandler {

private:
    string run;
    string duty;

public:
    servoHandler() {}
    servoHandler(string path);
    void setDuty(int duty);
    void turnOn();
    void turnOff();
};

#endif