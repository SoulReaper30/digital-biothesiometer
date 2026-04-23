# digital-biothesiometer
This project introduces a handheld, ultra-low-cost Digital Biothesiometer engineered to decentralize medical diagnostics. 
Built on the Arduino Uno R4 platform, the device utilizes a Linear Resonant Actuator (LRA) to deliver vibrations at exactly 235Hz. This precise frequency is tuned to stimulate the Meissner corpuscles, the primary mechanoreceptors in human skin responsible for fine touch perception.
The most significant engineering challenge in portable vibration testing is biological variability. Traditional low-cost testers are often inaccurate because skin thickness and calluses dampen motor output. 
To solve this, I engineered a closed-loop feedback system using an ADXL345 accelerometer mounted directly on the probe head. 
This allows the device to measure actual physical displacement in real-time. If a patient has thick skin that resists the motor, the system detects the damping and automatically maintains hospital-grade accuracy, ensuring reliable results regardless of skin type or callus buildup.
By executing a Bekesy tracking algorithm, the software identifies the exact mathematical threshold where sensation begins to fade. This enables the detection of nerve degradation six to twelve months before a physical ulcer ever appears. 
