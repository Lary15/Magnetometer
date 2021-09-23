// Sketch for Arduino magnetometer
// Measures strength of magnetic field with SS49E hall sensor on A0
// Displays values on I2C SSD1306 128x64 0.96" monochrome OLED display
// Connect SCK to pin A5 and SDA to pin A4
// Connect null-button between GND and A1 for setting output to zero 

#include <SPI.h>
#include <Wire.h>
#include <string.h>

#define HALL_PIN A0
#define NULL_PIN A1

void setup() {
  Serial.begin(38400);
  pinMode(HALL_PIN,INPUT); //pullup increases current and reduces noise
  pinMode(NULL_PIN,INPUT_PULLUP); //avoids need for external pullup resistor
}

void loop() {
  int analog_val = analogRead(HALL_PIN);

  float adc_to_volt = 5.0/1024;
  float volt_to_gauss = 1.5/1000;

  float gauss = (analog_val-512)*(adc_to_volt/volt_to_gauss);

  Serial.println(gauss);
}
