#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_ADXL345_U.h>
int m1 = 9;
int m2 = 10;
// int freq = 235;
// long interval = 2127;

int pwr = 40;
int max_m = 55;
unsigned long timer1 = 0;
unsigned long timer2 = 0;
int state = 0;
bool running = false;
int res[5]
int step_count = 0;
bool isUp = true;

Adafruit_SH1106G oled(128, 64, &Wire, -1);
Adafruit_ADXL345_Unified adxl = Adafruit_ADXL345_Unified(12345);
float z_val = 0;
float mx = -100;
float mn = 100;
void setup() {
  Serial.begin(115200);
  
  oled.begin(0x3C, true);
  oled.setTextSize(1);
  oled.setTextColor(SH110X_WHITE);
  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.println("booting...");
  oled.display();
  adxl.begin();
  adxl.setRange(ADXL345_RANGE_2_G);
  pinMode(m1, OUTPUT);
  pinMode(m1, OUTPUT);
  Serial.println("ready");
}
void loop() {
  
  // motor codee
  if (running == true) {
    if (micros() - timer1 > 2127) { // 2127 is for 235hz
      timer1 = micros();
      if(state == 0) {
        analogWrite(m1, pwr);
        analogWrite(m2, 0);
        state = 1;
      } else {
        analogWrite(m1, 0);
        analogWrite(m2, pwr);
        state = 0;
      }
    }
  }
  if (Serial.available()) {
    char c = Serial.read();
    
    if(c == 's') {
      running = true;
      pwr = 20;
      step_count = 0;
      isUp = true;
      Serial.println("start");
    }
    if(c == 'y' && running) {
       if(isUp) {
         isUp = false;
         res[step_count] = pwr;
         step_count++;
       }
    }
    if(c == 'n' && running) {
      if(!isUp) {
        isUp = true;
        res[step_count] = pwr;
        step_count++;
      }
    }
  }
  if(running) {
    sensors_event_t evt;
    adxl.getEvent(&evt);
    z_val = (0.2 * evt.acceleration.z) + (0.8 * z_val);
    if(z_val > mx) mx = z_val;
    if(z_val < mn) mn = z_val;
    if(millis() -timer2 > 800) {
      timer2 = millis();
      float disp = ((mx - mn) * 9.81/2180052) * 1000000.0;
      Serial.print("p: ");
      Serial.print(pwr);
      Serial.print("d: "); Serial.println(disp);
      if(isUp) pwr++;
      else pwr--;
      mx = -100;
      mn = 100;

    }
  }
