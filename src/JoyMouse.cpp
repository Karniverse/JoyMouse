// JoyMouse.cpp

#include "JoyMouse.h"

// Global variables for joystick axis calibration
int minima[] = {1023, 1023}; // actual analogRead minima for {x, y}
int maxima[] = {1, -1};      // actual analogRead maxima for {x, y}
int xAxisPin, yAxisPin;      // pin numbers for X and Y axes

// Function to initialize joystick-based mouse movement
void initJoystickMouse(int xPin, int yPin)
{
    Mouse.begin();
    xAxisPin = xPin;
    yAxisPin = yPin;
}

// Function to handle mouse movement based on joystick input
void updateJoystickMouse()
{
    int xReading = readAxis(0);
    int yReading = readAxis(1);

    // Move the mouse based on the joystick reading
    Mouse.move(xReading, yReading, 0);
    delay(responseDelay);
}

// Function to read and process joystick axis
int readAxis(int axisNumber)
{
    int distance = 0;                                      // distance from the center of the output range
    int axisPin = (axisNumber == 0) ? xAxisPin : yAxisPin; // Choose pin based on axis

    // Read the analog input from the joystick
    int reading = analogRead(axisPin);

    // Calibrate the min and max values for this axis
    if (reading < minima[axisNumber])
    {
        minima[axisNumber] = reading;
    }
    if (reading > maxima[axisNumber])
    {
        maxima[axisNumber] = reading;
    }

    // Map the reading from the analog input range to the output range
    reading = map(reading, minima[axisNumber], maxima[axisNumber], 0, range);

    // If the output reading is outside the rest position threshold, use it
    if (abs(reading - center) > threshold)
    {
        distance = (reading - center);
    }

    // Invert the Y-axis to map movement correctly
    if (axisNumber == 1)
    {
        distance = -distance;
    }

    // Return the distance for this axis
    return distance;
}
