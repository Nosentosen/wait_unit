# wait_unit ⏳

## Overview

`wait_unit` is a tiny C header that makes delays look less like math homework and more like intent.

Instead of thinking in milliseconds, you write:

```c
wait_sec(2);
wait_min(1);
wait_hr(1);
```

And the program just… waits. As expected.

## What it does

It provides three simple delay helpers:

- `wait_sec(seconds)` — seconds (supports decimals)
- `wait_min(minutes)` — minutes
- `wait_hr(hours)` — hours

All of them end up doing the same thing: pausing execution for a bit.

Just expressed in a way that reads like human thought instead of system calls.

## How it works

Under the hood, it uses the platform’s native sleep system:

- 🪟 Windows → `Sleep()`
- 🐧 Linux / 🍎 macOS → `nanosleep()`

Everything is wrapped in `static` helper functions inside a single header file, so there’s nothing to link or configure.

## Features

- Single header setup 📦  
- Cross-platform support 🧭  
- Fractional time support (yes, `wait_sec(2.5)` works)  
- Minimal and readable API 👀  
- No dependencies, no setup rituals  

## Installation

Drop the file into your project and include it:

```c
#include "wait_unit.h"
```

That’s the setup.

## Example

```c
#include <stdio.h>
#include "wait_unit.h"

int main() {
    printf("Booting...\n");

    wait_sec(2);
    wait_sec(1.5);

    printf("Ready.\n");

    wait_min(0.1); // short break

    printf("Done.\n");

    return 0;
}
```

## Notes

- This does not bend time (unfortunately)
- It relies entirely on OS-level sleep functions
- Precision depends on the system scheduler, not the wrapper
- It’s meant for simple delays, not real-time systems or high-frequency timing

## License

MIT License — use it, change it, break it, improve it.
