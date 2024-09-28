//#include <JoyMouse.h>
#include "JoyMouse.h"



void setup() {
    // Initialize joystick with X and Y axis analog pins (A0 and A1 in this case)
    initJoystickMouse(A7, A6);
}

void loop() {
    // Update mouse movement based on joystick input
    updateJoystickMouse();
}
