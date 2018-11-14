# Arduino library Timer

Implements a simple timer. Allows you to use the timer through the millis() and micros() functions, given the overflow. Does not block the stream.

## Example

    #include <TimerMicros.h>

    // New timer
    TimerMicros tm;
    
    void setup() {
      Serial.begin(9600);
      // The timer will return true after 5 seconds
      tm.wait(5000000);
    }
    
    void loop() {
      if (tm.check()) {
        // 5 seconds have passed
        Serial.print("true  ");
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

Output:

    false: 10000
    false: 1010000
    false: 2020000
    ...
    true:  5050000
    false: 6060000
    false: 7070000
    ...
    false: 9090000
    true: 10050000
    ...


## Types of variables

Just remember that

| Type 1   | Type 2              | MIN         | MAX        |
|----------|---------------------|-------------|------------|
| int8_t   | char                | -128        | 127        |
| uint8_t  | byte, unsigned char | 0           | 255        |
| int16_t  | int                 | -32768      | 32767      |
| uint16_t | unsigned int, word  | 0           | 65535      |
| int32_t  | long                | -2147483648 | 2147483647 |
| uint32_t | unsigned long       | 0           | 4294967295 |
