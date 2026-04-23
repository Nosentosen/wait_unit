# wait_unit ⏳

## Overview

`wait_unit` is a tiny C header that makes time delays more readable and less annoying to write.

Instead of thinking in raw milliseconds or low-level sleep calls, you can write:

```c
wait_sec(2);
wait_min(1);
wait_hr(1);
```

Same behavior underneath. Just a cleaner way to express it.

## What it does

Provides three delay helpers:

- `wait_sec(seconds)` — seconds (supports decimals)
- `wait_min(minutes)` — minutes
- `wait_hr(hours)` — hours

All values are converted internally into milliseconds and passed to the system’s native sleep functions.

## How it works

- 🪟 Windows → `Sleep()`
- 🐧 Linux / 🍎 macOS → `nanosleep()`

Everything is implemented as `static` functions inside a single header file, so no linking or setup is required.

## Features

- Single-header design 📦  
- Cross-platform support 🧭  
- Fractional time support (e.g. `wait_sec(2.5)`)  
- Minimal, readable API 👀  
- No external dependencies  

## Installation

Just include the header:

```c
#include "wait_unit.h"
```

That’s it.

## Example

```c
#include <stdio.h>
#include "wait_unit.h"

int main() {
    printf("Starting...\n");

    wait_sec(2);
    wait_sec(1.5);

    printf("Running...\n");

    wait_min(0.1);

    printf("Done.\n");

    return 0;
}
```

## Notes

- This does not increase timing precision; it wraps native OS sleep functions
- Accuracy depends on the operating system scheduler
- Designed for simple delays and readability, not real-time systems

## Project background

- The concept for this project was created by me  
- The implementation was generated with the help of AI  
- I am currently learning C using Bro Code’s free C programming course  

## License

MIT License — free to use, modify, and distribute.
