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
    void start(unsigned long millis);
    bool check();
private:
    unsigned long start;
    unsigned long end;
};


#endif // #ifndef TimerMillis_h