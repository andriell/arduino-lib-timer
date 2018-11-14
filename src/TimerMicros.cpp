#include "TimerMicros.h"
#define UL_MAX 4294967295ul

TimerMicros::TimerMicros() {
    startMicros = UL_MAX;
}

void TimerMicros::wait(uint32_t intervalMicros) {
    callMicros = micros();
    if (UL_MAX - intervalMicros < callMicros) {
        startMicros = intervalMicros - (UL_MAX - callMicros);
    } else {
        startMicros = callMicros + intervalMicros;
    }
}

void TimerMicros::wait(uint32_t intervalSeconds, uint32_t intervalMicros) {
    wait(intervalSeconds * 1000ul + intervalMicros);
}

void TimerMicros::wait(uint32_t intervalMinutes, uint32_t intervalSeconds, uint32_t intervalMicros) {
    wait(intervalMinutes * 60000ul + intervalSeconds * 1000ul + intervalMicros);
}

void TimerMicros::wait(uint32_t intervalHours, uint32_t intervalMinutes, uint32_t intervalSeconds, uint32_t intervalMicros) {
    wait(intervalHours * 3600000ul + intervalMinutes * 60000ul + intervalSeconds * 1000ul + intervalMicros);
}

bool TimerMicros::check() {
    uint32_t currentMicros = micros();
    if (startMicros < callMicros) {
        // |--S+++++++++C--|
        return startMicros <= currentMicros && currentMicros < callMicros;
    } else {
        // |++++C----S++++|
        return startMicros <= currentMicros || currentMicros < callMicros;
    }
}
