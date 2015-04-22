## Oculus Rift telepresence

Create a telepresence system with a embedded linux system (Beaglebone, Raspberry PI, ..), two Servos and two H264 compatible webcams.

### Features
- 3D Video streaming.
- Control the cameras with the Oculus Rift tracking system.

### Requirements
- GStreamer 1.4
- GStreamer plugins (base, good, bad, ugly)
- Boost libraries, for a cross platform implementation of UDP Sockets and Threads.
- Oculus Rift SDK

### Usage
This project is under heavy development, the usage may be unintuitive, hopefully, future realeases will improve ease of use.
I used a Beaglebone Black, with Arch Linux as base system, for testing purposes.

Beaglebone:
- Initialice Servos with the provided script.
- Launch the provided UDP Server to establish the socket that will control the Servos.
- Execute the provided server-side GStreamer command.

Client (Linux):
- Execute the provided client-side GStreamer command.
- Move the GStreamer window to the Oculus Rift Monitor (Unfinished).
- Launch the client to control the Servos.

### Work in progress
- Implementation of GStreamer libraries for ease of use
- Audio support
- QT Client side interface

### Terms and Conditions

The MIT License (MIT)

Copyright (c) 2015 Ricardo Domínguez Álvarez

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.