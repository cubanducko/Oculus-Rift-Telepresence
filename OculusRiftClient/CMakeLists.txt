cmake_minimum_required(VERSION 2.8.4)
project(OculusRiftClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/ovr_sdk_linux_0.4.4/LibOVR/Include
                    ${CMAKE_CURRENT_SOURCE_DIR}/lib/ovr_sdk_linux_0.4.4/LibOVR/Src)
set(SOURCE_FILES src/main.cpp)
add_executable(OculusRiftClient ${SOURCE_FILES})
target_link_libraries( OculusRiftClient ${CMAKE_CURRENT_SOURCE_DIR}/lib/ovr_sdk_linux_0.4.4/LibOVR/Lib/Linux/Release/x86_64/libovr.a
                        pthread
                        udev
                        GL
                        X11
                        Xrandr
                        boost_system
                        boost_date_time
                        boost_thread
                        rt)
