<p align="center">
  <img src="/graphics/engba-logo.png" alt="EnGBA Logo" width="200" />
</p>

# EnGBA

An open-source C++ Game Boy Advance emulator.

## Usage

```
git clone https://github.com/montasirmoyen/engba
cd engba
cmake -S . -B build && cmake --build build                               
build/sdl/engba <path-to-rom>
```

## Features

**Emulation**

- Cross-platform support (Windows, macOS, Linux)
- Compatible with a wide range of GBA games
- Smooth performance up to 60 FPS on most devices
- Fast ROM loading (under 2 seconds)
- Clear, consistent audio output
- Sharp, well-defined pixel rendering

**Codebase**

- Modern C++ architecture with clean structure
- Well-organized, modular directory layout
- Built-in debugging tools for development and testing

### Rationale

Most GBA emulators are written in C because it’s portable, predictable, and easy to optimize across many platforms.

EnGBA takes a different approach. It's built in modern C++ to take advantage of stronger abstractions and a cleaner architecture while still keeping performance in mind, offering:

- Clearer hardware modules through classes and RAII
- Type‑safe interfaces instead of macro‑heavy patterns
- A more maintainable structure for things like the CPU, Bus, PPU, and scheduler
- Better separation of concerns, which makes the hardware model easier to reason about
- A codebase that’s easier to learn from, since readability is a priority

The goal isn’t to chase maximum optimization or support every platform, current GBA emulators exist for that.

The goal is to build a modern, understandable GBA emulator that’s fun to work on and easy to extend.

#### Attributes

EnGBA is built on top of the open-source mGBA (Copyright © 2013–2026 Jeffrey Pfau and contributors) project, it's used as a large reference for understanding GBA hardware behavior.

All usage is in accordance with the [Mozilla Public License version 2.0](https://www.mozilla.org/MPL/2.0/).

- inih - Copyright © 2009–2020 Ben Hoyt (BSD‑3‑Clause)
- LZMA SDK - Public domain
- MurmurHash3 by Austin Appleby - Public domain
- getopt for MSVC - Public domain
- SQLite3 - Public domain