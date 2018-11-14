#include "TimerMillis.h"
#define UL_MAX 4294967295ul

TimerMillis::TimerMillis() {
    startTime = UL_MAX;
}

void TimerMillis::wait(uint32_t intervalMillis) {
    callMillis = millis();
    if (UL_MAX - intervalMillis < callMillis) {
        startMillis = intervalMillis - (UL_MAX - callMillis);
    } else {
        startMillis = callMillis + intervalMillis;
    }
}

bool TimerMillis::check() {
    uint32_t currentMillis = millis();
    if (startMillis < callMillis) {
        // |--S+++++++++C--|
        return startMillis <= currentMillis && currentMillis < callMillis;
    } else {
        // |++++C----S++++|
        return startMillis <= currentMillis || currentMillis < callMillis;
    }
}
