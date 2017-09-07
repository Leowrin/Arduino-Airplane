# Drone
We created an arduino based rc airplane.

We used two arduino nano v.3 to make the radio control, which is 3D-printed, and the airplane is made of foam.

The transciever we used is the <a href="https://github.com/Leowrin/Drone/tree/master/HC-12%20-Com." target="_blank">HC-12</a> module board. The radio frequency is 433Mhz and has a range between ~100[m] to ~1800[m] depending on the environment.

The airplane is controlled with 4 metal-geared (~0.0134[kg] each) servos.

The raw analog data from the joystick, speed potentiometers, yaw buttons, are each sent to the airplane in a single raw every ~0.05[s] following a spesific <a href="https://github.com/Leowrin/Drone/blob/master/Arduino_Code/Arduino_TX/Data%20pattern.jpg" target="_blank">pattern</a> shown in the wiki.

Raw data is then processed on the airplane.
