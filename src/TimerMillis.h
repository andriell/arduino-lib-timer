#ifndef TimerMillis_h
#define TimerMillis_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class TimerMillis
{
public:
    Timer();
    void start(uint16_t interval_millis);
    bool check();
private:
    uint16_t start;
    uint16_t end;
};


#endif // #ifndef TimerMillis_h