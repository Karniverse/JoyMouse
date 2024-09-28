// #include <JoyMouse.h>
#include "JoyMouse.h"

void setup()
{
    // Initialize joystick with X and Y axis analog pins (A7 and A6 in this case)
    initJoystickMouse(A7, A6);
}

void loop()
{
    // Update mouse movement based on joystick input
    updateJoystickMouse();
}
