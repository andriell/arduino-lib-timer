#include "TimerMillis.h"

TimerMillis::TimerMillis() {
    startTime = 4294967295ul;
}

void TimerMillis::start(uint32_t intervalMillis) {
    uint32_t currentMillis = millis();
    currentMillis = currentMillis >> 1;
    intervalMillis = intervalMillis >> 1;
    startTime = currentMillis + intervalMillis;
}

bool TimerMillis::check() {
    return millis() >= startTime;
}
