#ifndef WAIT_UNIT_H
#define WAIT_UNIT_H

#ifdef _WIN32
    #include <windows.h>

    static void wait_ms(double ms) {
        Sleep((DWORD)ms);
    }

#else
    #include <time.h>

    static void wait_ms(double ms) {
        struct timespec ts;

        ts.tv_sec = (time_t)(ms / 1000.0);
        ts.tv_nsec = (long)((ms - (ts.tv_sec * 1000.0)) * 1000000.0);

        nanosleep(&ts, NULL);
    }

#endif

static void wait_sec(double sec) {
    if (sec > 0)
        wait_ms(sec * 1000.0);
}

static void wait_min(double min) {
    if (min > 0)
        wait_sec(min * 60.0);
}

static void wait_hr(double hr) {
    if (hr > 0)
        wait_min(hr * 60.0);
}

#endif