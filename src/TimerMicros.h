#ifndef TimerMicros_h
#define TimerMicros_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class TimerMicros
{
public:
    Timer();
    void start(unsigned long micros);
    bool check();
private:
    unsigned long start;
    unsigned long end;
};


#endif // #ifndef TimerMicros_h