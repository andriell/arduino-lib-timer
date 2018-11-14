#include <TimerMicros.h>

// New timer
TimerMicros tm;

void setup() {
  Serial.begin(9600);
  // The timer will return true after 5 seconds
  tm.wait(5000);
}

void loop() {
  if (tm.check()) {
    // 5 seconds have passed
    Serial.print("true ");
    // Create a new wait
    // Method wait have arguments (hours, minutes, seconds, micros)
    // Here used seconds and micros
    tm.wait(5, 0);
  } else {
    Serial.print("false ");
  }
  Serial.println(micros());
  delay(1000);
}
