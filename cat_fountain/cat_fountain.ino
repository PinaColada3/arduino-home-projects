#include "LowPower.h"

int sleep_counter = 0;
const int one_day = 2500;
const int water_pin = A2;
const int on_time = 3000;

void setup() {
  pinMode(water_pin, OUTPUT);
  digitalWrite(water_pin, HIGH);
  delay(on_time);
  digitalWrite(water_pin, LOW);
}

void loop() {
  // Turn off the outlet before starting
  bool sleep = true;
  while (sleep) {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    sleep_counter++;
    if (sleep_counter >= one_day) {
      sleep = false;
      sleep_counter = 0;
    }
  }
  digitalWrite(water_pin, HIGH);
  delay(on_time);
  digitalWrite(water_pin, LOW);
}
