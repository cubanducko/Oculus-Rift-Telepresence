cmake_minimum_required(VERSION 2.8.4)
project(ServoUDPServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(SOURCE_FILES src/main.cpp
                    src/servoHandler/servoHandler.cpp
                    src/server.cpp)
add_executable(ServoUDPServer ${SOURCE_FILES})
target_link_libraries(  ServoUDPServer pthread
                            boost_system
                            boost_thread)
