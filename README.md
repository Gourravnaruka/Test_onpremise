# Autonomus-Mobile-Robot
 
Amit Embedded System Diploma
Autonomous Car project

By: Ahmed Mohamed Elsayed Mohamed Moustafa

The project is a wheeled mobile robot. The robot with two modes (Autonomous mode and RC mode)

Autonomous mode: 
---------------
It is the mode in which the car can navigate autonomously and avoid obstacles in its path using an ultrasonic sensor. 
The ultrasonic sensor is mounted over a servo motor. The servo motor makes a rotation over 180 degrees, giving the sensor a scanning degree of 180 in front of the car.

The car stops when the ultrasonic sensor detects an obstacel within 50cm or less in front of the car. After that, the car scan right and left and decided the new 
path according to the clear path

RC mode:
-------
In this mode, the car is controlled manually via Bluetooth communication (UART) from an APP on a mobile robot. In this mode, the driver can control the in every direction. Also, the speed of the car can be controlled from the app
The LCD display is used to display the car status. For instance, in the autonomous mode, the LCD message "Autonomous" indicated the car mode and the distance measuring by the 
ultrasonic sensor. However, in the RC model, the LCD "manual" indicates the mode and display the "forward, backward, turning left, turning right," which are the command 
received from the controller.


Controller:
-----------
The car is based on an AVR microcontroller (Atmega32). AVR development kit (designed by Amit) is used for easy wiring and mounting other peripherals
