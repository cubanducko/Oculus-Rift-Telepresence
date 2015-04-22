#include <fstream>
#include "servoHandler.h"

#define PERIOD 5000000

servoHandler::servoHandler(string path) {
    this->run = path+"run";
    this->duty = path+"duty";

    //Configure the servo motor
    turnOn();

    ofstream periodFile;
    periodFile.open ((path+"period").c_str());
    periodFile << PERIOD;
    periodFile.close();
}

void servoHandler::setDuty(int duty) {
    ofstream dutyFile;
    dutyFile.open (this->duty.c_str());
    dutyFile << duty;
    dutyFile.close();
}

void servoHandler::turnOn() {
    ofstream runFile;
    runFile.open (this->run.c_str());
    runFile << 1;
    runFile.close();
}

void servoHandler::turnOff() {
    ofstream runFile;
    runFile.open (this->run.c_str());
    runFile << 0;
    runFile.close();
}