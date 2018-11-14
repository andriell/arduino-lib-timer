# Arduino lib timer

Implements a simple timer. Allows you to use the timer through the millis() function, given the overflow. Does not block the stream.

## Example

    #include <TimerMillis.h>

    // New timer
    TimerMillis tm;
    
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
        tm.wait(5, 0);
      } else {
        Serial.print("false ");
      }
      Serial.println(millis());
    }


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
