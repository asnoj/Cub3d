*This project has been created as part of the 42 curriculum by jcrochet, aronnet.*

# cub3D

A 3D game engine built from scratch in C using raycasting, inspired by the legendary Wolfenstein 3D (1992). Navigate through a maze in first-person perspective with textured walls, interactive doors, and animated sprites.

## Description

cub3D is a graphics project that renders a pseudo-3D environment from a 2D map using the raycasting technique popularized by id Software. The engine reads a `.cub` scene file that defines wall textures, floor/ceiling colors, and a maze layout, then renders the scene in real-time with player movement and rotation.

The project covers parsing and validation of scene files, mathematical foundations of raycasting (DDA algorithm, perpendicular distance correction), texture mapping on walls and floor/ceiling, and real-time keyboard and mouse input handling.

### Features

**Mandatory:**
- Raycasting engine with textured walls (North, South, East, West)
- Configurable floor and ceiling colors
- Player movement (WASD) and rotation (arrow keys)
- Scene file parsing with comprehensive error handling
- Map validation (flood fill to ensure closed walls)

**Bonus:**
- Wall collision detection with sliding
- Interactive minimap overlay
- Doors that open and close (press Space)
- Animated player sprite with directional frames
- Mouse-controlled camera rotation
- Textured floor and ceiling with multiple randomized ceiling textures

## Instructions

### Prerequisites

- Linux (tested on Ubuntu 24)
- GCC / cc
- Make
- X11 development libraries (`libx11-dev`, `libxext-dev`)

### Compilation

```bash
make        # compile the project
make clean  # remove object files
make fclean # remove object files and binary
make re     # recompile from scratch
make bonus  # compile with bonus features
```

### Execution

```bash
./cub3D <path_to_map.cub>
```

Example:
```bash
./cub3D maps/maps.cub
```

### Controls

| Key | Action |
|---|---|
| W | Move forward |
| A | Strafe left |
| S | Move backward |
| D | Strafe right |
| ← → | Rotate camera |
| Mouse | Rotate camera (bonus) |
| Space | Open/close doors (bonus) |
| ESC | Quit |

### Map format (.cub)

A `.cub` file contains texture paths, colors, and a map grid:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

Map characters: `1` = wall, `0` = empty space, `N/S/E/W` = player spawn and orientation, `D` = door (bonus).

## Resources

- [Lodev Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — Primary reference for the raycasting algorithm, DDA implementation, and texture mapping math.
- [42 Docs — miniLibX](https://harm-smits.github.io/42docs/libs/minilibx) — Documentation for the miniLibX graphics library.
- [Wolfenstein 3D](http://users.atw.hu/wolf3d/) — The original game that inspired this project, useful for understanding the expected rendering behavior.

### AI usage

AI tools (Claude) were used during development for the following tasks:
- Understanding the mathematical concepts behind raycasting (DDA algorithm, perpendicular distance correction, texture coordinate calculation).
- Structuring the project architecture (file organization, data structures, function prototypes).
- Debugging memory leaks and segmentation faults using valgrind output analysis.
- Converting image files to .xpm format compatible with miniLibX.
- Writing valgrind suppression files for X11/miniLibX internal leaks.

All AI-generated code was reviewed, understood, and adapted by the team before integration. The bonus features (minimap, doors, mouse rotation, sprite animation) were implemented independently using only conceptual explanations from AI, without receiving code.
