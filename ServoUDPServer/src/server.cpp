#include "server.h"
#include "servoHandler/servoHandler.h"
#include <boost/atomic.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

using boost::asio::ip::udp;
using namespace std;
using namespace boost;
boost::atomic<bool> done;

server::server(string servoX, string servoY, int port) {
    this->servoX = servoHandler(servoX);
    this->servoY = servoHandler(servoY);
    this->port=port;
    this->maxLength=1024;
    this->debug = false;
    done = false;

    //Start the motors
    this->servoX.turnOn();
    this->servoY.turnOn();

}

void server::run() {
    asio::io_service io_service;
    udp::socket sock(io_service, udp::endpoint(udp::v4(), port));
    char rawData[maxLength];
    while(!done) {
        //Receive the packet
        udp::endpoint sender_endpoint;
        size_t length = sock.receive_from(asio::buffer(rawData, maxLength), sender_endpoint);

        //Split the UDP datagrams in floats
        vector<string> data;
        string strRawData(rawData,length);
        split(data,strRawData,is_any_of("/"),token_compress_on);
        if(debug)
            cout << "X: " << data[0] << " Y: " << data[1] << endl;
        servoX.setDuty(atoi(data[0].c_str()));
        servoY.setDuty(atoi(data[1].c_str()));
    }
}


void server::stop() {
    done = true;
    servoX.turnOff();
    servoY.turnOff();
}

void server::switchDebug() {
    this->debug = !debug;
}