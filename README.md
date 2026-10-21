<div align="center">

# 🚀 TRY NOT TO SHOOT

### A smooth, fast-feeling space-ship shooter built from scratch in C++ and SDL3

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![SDL3](https://img.shields.io/badge/SDL-3-1E90FF?style=for-the-badge)
![Status](https://img.shields.io/badge/status-work%20in%20progress-orange?style=for-the-badge)

</div>

---

## 🎮 About

**Try Not To Shoot** is an arcade-style space-ship shooter. You pilot a ship, dodge what's coming, and blast your way through the dark, and the whole thing is built around one idea: **it should feel smooth**.

No big engine, no heavy framework. Just C++, SDL3, and the basics, written to be simple, fast, and satisfying to play.

> 🛠️ **This project is a work in progress.** Things will change, break, and get better.

---

## 🖼️ Concept mockup

A rough idea of the in-game screen (not final art):

```
┌──────────────────────────────────────────────┐
│  SCORE 004200                         ♥ ♥ ♥  │
│                                              │
│      ▼         ▼         ▼         ▼         │
│           ▼         ▼         ▼              │
│                                              │
│                      ·                       │
│                      ▲                       │
│                     ╱█╲                      │
└──────────────────────────────────────────────┘
```

<!-- When you have real screenshots, drop them in Images/ and use:
![Gameplay](Images/your-screenshot.png)
-->

---

## ✨ Design goals

| Goal | What it means |
| --- | --- |
| **Smooth** | Steady frame pacing, no stutter, movement that doesn't depend on frame rate |
| **Responsive** | Input that feels instant, with no mushy controls |
| **Simple** | Plain C++ and SDL3, easy to read and easy to build on |
| **Fun first** | Tight, readable arcade action over feature bloat |

---

## 🧰 Tech stack

| | |
| --- | --- |
| **Language** | C++ |
| **Windowing, rendering, input** | [SDL3](https://www.libsdl.org/) |
| **Assets** | Sprites and images live in [`Images/`](Images) |

---

## 🚀 Getting started

### Prerequisites

- A C++ compiler (GCC, Clang, or MSVC)
- [SDL3](https://github.com/libsdl-org/SDL) installed on your system

### Clone

```bash
git clone https://github.com/nishantnigam-van/try_not_to_shoot.git
cd try_not_to_shoot
```

### Build and run

<!-- TODO: replace this with your real build command (CMake, Makefile, etc.) -->

```bash
g++ src/*.cpp -std=c++17 $(pkg-config --cflags --libs sdl3) -o try_not_to_shoot
./try_not_to_shoot
```

---

## 🕹️ Controls (planned)

| Action | Key |
| --- | --- |
| Move | `W` `A` `S` `D` or Arrow keys |
| Shoot | `Space` |
| Quit | `Esc` |

---

## 📁 Project structure

```
try_not_to_shoot/
├── Images/       # sprites and artwork
├── src/          # game source code (C++)
└── README.md
```

---

## 🗺️ Roadmap

Tick these off as you build them:

- [ ] Window, renderer, and a stable game loop
- [ ] Player ship with smooth movement
- [ ] Shooting and projectiles
- [ ] Enemies and spawning
- [ ] Collisions and damage
- [ ] Score and lives HUD
- [ ] Title screen and game over screen
- [ ] Sound effects and music
- [ ] Polish: particles, screen shake, difficulty curve

---

<div align="center">

Made with ☕ and SDL3 by [@nishantnigam-van](https://github.com/nishantnigam-van)

⭐ If you like where this is going, drop a star.

</div>
