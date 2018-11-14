#ifndef Timer_h
#define Timer_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class Timer
{
public:
    Timer();
    void startMillis(unsigned long millis);
    void startSec(int sec);
    bool check();
private:
    unsigned long millisStart;
    unsigned long millisEnd;
};


#endif // #ifndef Timer_h