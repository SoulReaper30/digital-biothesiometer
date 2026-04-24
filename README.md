# digital-biothesiometer
This project presents a portable, extremely affordable Digital Biothesiometer system designed to empower decentralized diagnostics. 
The device is based on the Arduino Uno R4 micro-controller and uses a Linear Resonant Actuator (LRA) to generate 235Hz vibrations. This frequency is specifically targeted at the Meissner corpuscles, the most dominant mechanoreceptors in the skin that allow humans to perceive fine touch.
The biggest challenge in designing a portable vibration tester is addressing biological variability. Conventional cheap testers are inaccurate due to skin thickness and calluses buffering the motor. 
To address this issue, I developed a feedback control system using the ADXL345 accelerometer on the head of the probe. 
This enables to directly measure the physical displacement of the head. If the patient has thicker skin and the motor has trouble pushing through, the system will recognise the damping and automatically adjust to achieve the same level of accuracy as the hospital, regardless of a patient's skin thickness or the presence of calluses.
Using a Bekesy algorithm, the software detects the mathematical point where the sensation is lost. This allows a patient's nerve damage to be detected six to 12 months before a visible ulcer develops.
