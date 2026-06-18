# Radar-System-using-Arduino


A radar-inspired object detection system built using Arduino, **2 servo motors**, and **2 HC-SR04 ultrasonic sensors**. The system scans its surroundings and measures the distance of nearby objects while displaying the results through a web-based visualization interface.

## Hardware Components
* Arduino Uno
* 2 × HC-SR04 Ultrasonic Sensors
* 2 × Servo Motors

## Scanning Modes
### 1. Servos working in Sync

In this mode, both servo motors move simultaneously.
* Servo A and Servo B rotate together.
* Both ultrasonic sensors collect distance measurements at the same time.
* Provides faster scanning of the environment.

Note: The Arduino code works, but the web application currently does not support this mode properly.

---

### 2. Servo Working Separately

In this mode, the servos scan sequentially.

Scanning sequence:
1. Servo A rotates from **0° to 180°**
2. Servo B rotates from **180° to 360°**
3. The cycle repeats continuously

This creates a wider scanning range while reducing simultaneous sensor operations.

## Web Application
The radar visualization interface was generated using **Google Gemini AI**.
The web application receives sensor data and displays detected objects in a radar-like view.


## Future Improvements

* Add full support for synchronized servo mode in the web application
* Add the distance and speed customization button within the web application

