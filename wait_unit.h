#ifndef WAIT_UNIT_H
#define WAIT_UNIT_H

// Handles Windows vs Linux/Mac
#ifdef _WIN32
    #include <windows.h>
    #define _WAIT_MS(ms) Sleep((unsigned long)(ms))
#else
    #include <unistd.h>
    #define _WAIT_MS(ms) usleep((unsigned long)((ms) * 1000))
#endif

// The "Magic" loop trick that makes 'wait_sec 2.5' work in C
#define _WAIT_LOGIC(factor) \
    for (int _done = 0; !_done; ) \
        for (double _val = 0; !_done; _WAIT_MS(_val * factor * 1000.0), _done = 1) \
            _val = 

// These are the only definitions you need
#define wait_sec _WAIT_LOGIC(1.0)
#define wait_min _WAIT_LOGIC(60.0)
#define wait_hr  _WAIT_LOGIC(3600.0)

#endif