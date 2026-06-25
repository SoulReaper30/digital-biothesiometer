This portable, low cost digital biothesiometer that I built to perform nerve testing outside of the typical hospital system. It has an Arduino-controlled linear resonant actuator to produce a stable 235Hz vibration. The exact frequency is the one that activates the main receptors in our skin for the fine touch, called the Meissner corpuscles.

The challenging aspect of creating a portable tester is that each person's skin is unique. Cheap testers are pretty inacurate, since the motor is protected by calluses and thick skin. To solve this problem, I stuck an ADXL345 accelerometer directly onto the probe head to create a feedback loop. This indicates the amount of actual tip motion. The system will automatically adjust to provide the necessary power to achieve the desired depth if it detects thick skin damping the vibrations. The speed and accuracy is like the hospital, but without the size. Plus, it has a Békésy algorithm which identifies the mathematical threshold where one feels numb, and alerts to the possible presence of nerve damage six months to one year prior to the appearance of an ulcer.

---

## Hardware Architecture

The combination of the microcontroller and a custom 3D-printed handheld probe.

To stimulate the touch receptors, the 235Hz buzzing is performed by a linear resonant actuator known as vibration generation.

### Closed-Loop Feedback Control:

---

## Key Features

* **Screening Anywhere:** Cheap parts mean reliable neurological testing can occur out in the field, rather than only in big clinics.
* **Callus Correction:** No measurement errors due to tough or thick skin.
* **Early Warning:** Detects loss of sensitivity even months before wounds are visible.
* **Auto Testing:** employs a stepping routine to determine the exact point at which it is no longer felt.

---

## System Pin Configuration

* **Pin 12:** Connected to Pin C
* **Pin 9:** Motor Line 1 (wires to H-Bridge Driver Input A)
* **Pin 10:** This is the Motor Line 2 which goes to H-Bridge Driver Input B, pin 10.
* **SDA Pin:** Shared I2C Data Line for the board, the SH1106 OLED and the ADXL345
* **SCL Pin (Shared I2C Clock Line):** The I2C clock line shared by the board and the SH1106 OLED and the ADXL345.

---

## Firmware Installation

### Library Dependencies

Before you compile, download these four libraries from your Arduino Library Manager:

* Wire
* Adafruit_SH110X
* Adafruit_ADXL345_U
* Adafruit_Sensor

---

## To run a Diagnostic Procedure

1. Load the program into your board.
2. As a first, open a terminal or the built-in Serial Monitor at 115200 baud.
3. To start up the motor control loop, type and send the start command 31A.
4. Use the serial interface or physical buttons to record the answers at each power level.


Item,Model,Qty,Purpose
Microcontroller,Arduino Uno R4 WiFi,1,runs the main code and handles the LED matrix built in
Accelerometer,Adafruit ADXL345,1,reads the live physical vibrations from the probe
Display,1.3-inch 128x64 OLED SH1106G,1,shows the live test data and final results
Motor Driver,DRV8833,1,to power the vibration motor
Actuator,LRA,1,creates the physical buzzing
Wiring,Breadboard jumper wires,1 set,Connects all the electronic parts together
Power Supply,5V 2A USB-C 9V battery and USB-C cable to arduino,1,Keeps the power stable so the motor does not crash the screen
Mounting,Custom 3D Printed Casing,1,Holds everything together in a single handheld unit
