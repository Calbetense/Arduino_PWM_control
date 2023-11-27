# Arduino_PWM_control
__Arduino PWM control for a Piston with an H-Bridge__

The H-Bridge has a MODE to make piston go Forwards or Backwards if it's HIGH or LOW. And algo a PWM for the speed's control.

This code is an example to be handed to control of the piston.

First defines the Arduino's Timer2 to 62.5kHz. Then goes forwards and backwards for 5 seconds in 50%, 100% and 25% of PWM's Duty Cycle.
