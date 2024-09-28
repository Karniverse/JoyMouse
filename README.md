<<<<<<< HEAD
### My sincere thanks to HID-Project from NicoHood which i used to compile this header.

----------------------------------------------------------------------------------------------------------
# JoyMouse.h

=======
# JoyMouse.h
>>>>>>> c299bb6eaecee27773804c94236b778b7edf8c62
An Arduino Library to simplify code to control Mouse movement by just declaring two analog pins of dual axis controller

**Supported boards tested so far:**
>Arduino Leonardo
>Arduino Leonardo Pro micro

just declare the two analog pins of dual axis joystick in setup in this format

```c
    // Initialize joystick with X and Y axis analog pins (A7 and A6 in this case)
    initJoystickMouse(A7, A6);
```

and then call the function in loop

```c
    // Update mouse movement based on joystick input
    updateJoystickMouse();
```
the same can be seen in example for easy reference

and thats it, connect the ky-023(dual axis joystick) to respective pins and after upload u can control the mouse movement of your device using the joystick.
