#ifndef server_h
#define server_h

#include <boost/atomic.hpp>
#include "servoHandler/servoHandler.h"

using namespace std;

class server {

private:
    servoHandler servoX;
    servoHandler servoY;
    int port;
    int maxLength;
    bool debug;

public:
    server(string servoX, string servoY, int port);
    void run();
    void stop();
    void switchDebug();
};

#endif