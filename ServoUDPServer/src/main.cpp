#include <cstdlib>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "servoHandler/servoHandler.h"
#include "server.h"

using boost::asio::ip::udp;
using namespace std;
using namespace boost;

#define PORT 9080
#define SERVO_X "/sys/devices/ocp.3/pwm_test_P9_14.16/"
#define SERVO_Y "/sys/devices/ocp.3/pwm_test_P8_13.15/"

int main(int argc, char *argv[]) {

    server mainServer(SERVO_X, SERVO_Y, PORT);
    boost::thread t(&server::run, mainServer);
    while(1) {
        cout << "1. Press E to exit" << endl;
        cout << "2. Press D to switch the debug" << endl;
        char option;
        cin >> option;
        if(option == 'e' || option == 'E') {
            t.interrupt();
            //Turn off the servos
            mainServer.stop();
            return 0;
        }
        if(option == 'd' || option == 'D')
            mainServer.switchDebug();
    }
}