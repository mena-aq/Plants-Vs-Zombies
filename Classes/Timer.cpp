#include "Timer.h"

Timer::Timer() {
    runTime = 0;
    paused = false;
    clock.restart();
}
void Timer::reset() {
    runTime = 0;
    clock.restart();
    runTime = 0;
    paused = false;
}
void Timer::start() {
    if (paused) {
        clock.restart();
    }
    paused = false;
}
void Timer::pause() {
    if (!paused) {
        runTime += clock.getElapsedTime().asSeconds();
    }
    paused = true;
}
float Timer::getTime() {
    if (!paused) {
        return runTime + clock.getElapsedTime().asSeconds();
    }
    return runTime;
}