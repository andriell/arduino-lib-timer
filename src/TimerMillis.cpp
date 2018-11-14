#include "TimerMillis.h"
#define UL_MAX 4294967295ul

TimerMillis::TimerMillis() {
    startMillis = UL_MAX;
}

void TimerMillis::wait(uint32_t intervalMillis) {
    callMillis = millis();
    if (UL_MAX - intervalMillis < callMillis) {
        startMillis = intervalMillis - (UL_MAX - callMillis);
    } else {
        startMillis = callMillis + intervalMillis;
    }
}

void TimerMillis::wait(uint32_t intervalSeconds, uint32_t intervalMillis) {
    wait(intervalSeconds * 1000ul + intervalMillis);
}

void TimerMillis::wait(uint32_t intervalMinutes, uint32_t intervalSeconds, uint32_t intervalMillis) {
    wait(intervalMinutes * 60000ul + intervalSeconds * 1000ul + intervalMillis);
}

void TimerMillis::wait(uint32_t intervalHours, uint32_t intervalMinutes, uint32_t intervalSeconds, uint32_t intervalMillis) {
    wait(intervalHours * 3600000ul + intervalMinutes * 60000ul + intervalSeconds * 1000ul + intervalMillis);
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
