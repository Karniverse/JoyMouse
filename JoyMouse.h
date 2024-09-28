// JoyMouse.h

#ifndef JOYMOUSE_H
#define JOYMOUSE_H

#include <Arduino.h>
#include <HID-Project.h>
//#include <Mouse.h>

// Default parameters
const int range = 12;            // output range of X or Y movement
const int responseDelay = 15;    // response delay of the mouse, in ms
const int threshold = range / 4; // resting threshold
const int center = range / 2;    // resting position value

// Global variables for axis pins
extern int xAxisPin, yAxisPin;

// Function to initialize joystick-based mouse movement
void initJoystickMouse(int xPin, int yPin);

// Function to handle mouse movement based on joystick input
void updateJoystickMouse();

// Internal function to read the joystick axis
int readAxis(int axisNumber);

#endif
