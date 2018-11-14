#ifndef TimerMicros_h
#define TimerMicros_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class TimerMicros {
    public:
        TimerMicros();
        void wait(                                                                            uint32_t intervalMicros);
        void wait(                                                  uint32_t intervalSeconds, uint32_t intervalMicros);
        void wait(                        uint32_t intervalMinutes, uint32_t intervalSeconds, uint32_t intervalMicros);
        void wait(uint32_t intervalHours, uint32_t intervalMinutes, uint32_t intervalSeconds, uint32_t intervalMicros);
        boolean check();
    private:
        uint32_t callMicros;
        uint32_t startMicros;
};

#endif // #ifndef TimerMicros_h
