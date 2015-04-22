#include <iostream>
#include "OVR_CAPI.h"
#include "OVR.h"
#include <boost/asio.hpp>
#include <boost/atomic.hpp>
#include <boost/thread.hpp>

using namespace std;
using namespace OVR;

using boost::asio::ip::udp;

boost::atomic<bool> done;
bool debug;
ovrHmd hmd;

void mainMenu () {
    while(1) {
        cout << "1. Press R to reset the tracking position" << endl;
        cout << "2. Press E to exit" << endl;
        cout << "3. Press D to switch the debuging" << endl;
        char option;
        cin >> option;
        if (option == 'R' || option == 'r')
            ovrHmd_RecenterPose(hmd);
        if (option == 'D' || option == 'd')
            debug = !debug;
        if (option == 'E' || option == 'e') {
            done = true;
            return;
        }
    }
}

int main(int argc, char *argv[]) {

    //Initialize the Oculus Rift tracking
    cout << "Initializing the Oculus Rift tracking module..." << endl;
    ovr_Initialize();
    hmd = ovrHmd_Create(0);
    //Initialize the tracking position
    ovrHmd_ConfigureTracking(hmd, ovrTrackingCap_Orientation
            | ovrTrackingCap_MagYawCorrection
            | ovrTrackingCap_Position, 0);

    //Initialize the UDP socket
    cout << "Initializing the UDP socket..." << endl;
    boost::asio::io_service io_service;

    udp::socket s(io_service, udp::endpoint(udp::v4(), 0));
    udp::resolver resolver(io_service);
    udp::resolver::query query(udp::v4(), "192.168.7.2", "9080");
    udp::resolver::iterator iterator = resolver.resolve(query);

    //Launch the main menu thread
    boost::thread t(&mainMenu);
    debug = false;

    while (!done) {
        ovrTrackingState ts = ovrHmd_GetTrackingState(hmd, ovr_GetTimeInSeconds());
        if (ts.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
            ovrQuatf coordinates = ts.HeadPose.ThePose.Orientation;
            //We need to send a value between 2400*1000 and 4400*1000, and the x and y coordinates of the oculus vary between -1 and 1
            //So we transform the values with a simple equation "NewValue = (((OldValue - OldMin) * (NewMax - NewMin)) / (OldMax - OldMin)) + NewMin"
            //Note: Coordinates are fliped, and x coordinate needs to be inverted.
            string request = to_string(((int)((coordinates.y+1) * 2000) / (2) + 2600)*1000) + "/" + to_string(((int)(((0-coordinates.x)+1) * 2000) / (2) + 1800)*1000);
            size_t request_length = strlen(request.c_str());
            if(debug)
                cout << "Sending: " << request << endl;
            s.send_to(boost::asio::buffer(request, request_length), *iterator);
        }
        //Send a new value every 5 ms
        usleep(5 * 1000);
        //Debug sleep
        //usleep(1000*1000);
    }
    cout << "Goodbye..." << endl;
    ovrHmd_Destroy(hmd);
    ovr_Shutdown();
    return 0;
}