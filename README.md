# Arduino based radio-controlled airplane
We created an arduino based rc-airplane.

We used an arduino nano v.3 to make the radio controller, which is 3D-printed, and the airplane is made of polystyrene.

The transciever we used is the <a href="https://github.com/Leowrin/Arduino-Airplane/blob/master/HC-12%20-Com/HC-12%20Documentation%20and%20AT%20Commands.pdf." target="_blank">HC-12</a> module board. The radio frequency is 433Mhz and has a range of between ~100[m] to ~1800[m] depending on the environment.

The airplane is controlled with 4 metal-geared servos, 1 for each aileron, 1 for the elevator and 1 for the yaw axis.

The analog value from the joystick, speed potentiometers, yaw buttons, are each sent to the airplane in a single raw every ~0.05[s] following a specific <a href="https://github.com/Leowrin/Arduino-Airplane/blob/master/Radio_Controller/Data%20pattern.jpg" target="_blank">pattern</a> shown in the wiki.

Raw data is then processed by the airplane.

speed potentiometer's value are mapped from [0;1023] to [40;180]. The new low value shall vary between each ESCs.

Maneuverability potentiometers are mapped from [0;1023] to [0;180], which corresponds to the standard servo motor opening angle.
