#ifndef TimerMillis_h
#define TimerMillis_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class TimerMillis {
    public:
        TimerMillis();
        void wait(uint32_t intervalMillis);
        boolean check();
    private:
        uint32_t callMillis;
        uint32_t startMillis;
};

#endif // #ifndef TimerMillis_h
