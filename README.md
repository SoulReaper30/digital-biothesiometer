This project presents a portable, extremely affordable Digital Biothesiometer system designed to empower decentralized diagnostics. The device is based on the Arduino Uno R4 micro-controller and uses a Linear Resonant Actuator (LRA) to generate 235Hz vibrations. This frequency is specifically targeted at the Meissner corpuscles, the most dominant mechanoreceptors in the skin that allow humans to perceive fine touch. The biggest challenge in designing a portable vibration tester is addressing biological variability. Conventional cheap testers are inaccurate due to skin thickness and calluses buffering the motor. To address this issue, I developed a feedback control system using the ADXL345 accelerometer on the head of the probe. This enables to directly measure the physical displacement of the head. If the patient has thicker skin and the motor has trouble pushing through, the system will recognise the damping and automatically adjust to achieve the same level of accuracy as the hospital, regardless of a patient's skin thickness or the presence of calluses. Using a Bekesy algorithm, the software detects the mathematical point where the sensation is lost. This allows a patient's nerve damage to be detected six to 12 months before a visible ulcer develops.

**Hardware Architecture**
This device is based on an Arduino Uno R4 microcontroller with a custom built probe designed for a handheld controller.

Vibration Generation: Using a Linear Resonant Actuator (LRA) to generate targeted vibrations at 235Hz. This frequency in particular activates the main mechanoreceptors in human skin, namely the Meissner corpuscles.

**Closed-Loop Feedback Control**
<img width="1280" height="960" alt="WhatsApp Image 2026-05-04 at 13 15 00" src="https://github.com/user-attachments/assets/0404c975-95d5-4c02-b724-c3ebf00ccb37" />

**
Key Features**
Decentralized Access: Low-cost components enable reliable neurological screening beyond large hospital networks.

Continuous acceleration monitoring prevents errors due to different thicknesses of skin (Callus Deflection Compensation).

Pre-Ulcer Screening: The tracking software identifies sensory degradation 6-12 months prior to physical ulcers developing on the skin.

Automated Patient Testing: uses a modified Békésy tracking algorithm to measure the exact point of transition between physical sensation and its loss.
<img width="1024" height="768" alt="EC2BF34B-7763-43E1-9254-5BB6FB8E9B3C_1_105_c" src="https://github.com/user-attachments/assets/0672e846-9dab-4f50-8688-d1f283f19426" />


**System Pin Configuration**
Pin C: 12

LRA Motor Line 1: 9 (H-Bridge Driver Input A)

LRA Motor Line 2: 10 (H-Bridge Driver Input B)

SDA: SDA (I2C Data Line)

ADXL345 SCL: SCL (I2C Clock Line)

The I2C Data Bus is shared between SH1106 OLED and SDA.
Shared I2C Clock Bus: SH1106 OLED SCL SCL

**Firmware Installation**
Library Dependencies
Install these libraries using your Arduino Library Manager BEFORE compiling the code:

Wire

Adafruit_SH110X

Adafruit_ADXL345_U

Adafruit_Sensor

Performing a diagnostic procedure
1. Program the Arduino with the new firmware.
2. Open your desktop terminal or Serial Monitor at a baud rate of 115200.
3. Use the terminal interface to send the designated start command (31A) to start the motor control loop.
4. Record the user's responses at each power step in the routine using the physical input or serial commands.
