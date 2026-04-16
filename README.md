*This project has been created as part of the 42 curriculum by aronnet & jcrochet.*

<div align="center">

<h1>🎮 CUB3D</h1>

**A raycasting 3D game engine inspired by Wolfenstein 3D — written in C**

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42)](https://42lehavre.fr)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-v3-brightgreen?style=flat-square)](https://github.com/42School/norminette)

</div>

---

## 📖 Description

**cub3D** is a 42 School project that implements a first-person 3D engine from scratch using raycasting — the same technique used in Wolfenstein 3D (1992). A 2D map is rendered in real time as a pseudo-3D perspective using MiniLibX.

The project was built in pair programming and covers computer graphics fundamentals: ray-wall intersection, texture mapping, camera projection, and pixel-level rendering.

---

## ✨ Features

### Mandatory
- Real-time raycasting with the **DDA algorithm**
- **4 directional wall textures** (NO / SO / WE / EA), each mapped correctly per face
- Configurable **floor and ceiling colors** via `.cub` file
- Smooth **WASD movement** with collision detection
- **Left/Right arrow** camera rotation
- Clean `.cub` map parsing with full error handling

### Bonus
- 🗺️ **Minimap** — top-down view rendered in the corner, showing walls, floors and player position
- 🚪 **Doors** — interactive `D` tiles openable/closable with `Space`
- 🖱️ **Mouse look** — camera follows mouse movement, locked to window center
- 🎨 **Textured floor & ceiling** — per-cell texture variation using hash-based index selection
- 🧍 **Animated character sprite** — directional walk cycle with separate sprint animation

---

## 🕹️ Controls

| Input | Action |
|---|---|
| `W` `A` `S` `D` | Move forward / strafe left / backward / strafe right |
| `←` `→` | Rotate camera left / right |
| `Mouse` | Rotate camera (continuous tracking) |
| `Space` | Open / close door in front of player |
| `ESC` | Quit |

---

## 🗺️ Map format (`.cub`)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100101
1D0N01
110001
111111
```

| Character | Meaning |
|---|---|
| `1` | Wall |
| `0` | Empty floor |
| `N` `S` `E` `W` | Player spawn + initial direction |
| `D` | Door (interactive, bonus) |

**Validation rules:** the map must be fully enclosed by walls, contain exactly one player spawn, and use only valid characters. A flood-fill algorithm verifies closure from the spawn point.

---

## 🏗️ Architecture

```
cub3d/
├── includes/
│   ├── cub3d.h               # All structs, enums and prototypes
│   └── defines.h             # Constants, keycodes, error messages, game settings
├── libft/                    # 42 standard library
├── maps/                     # .cub map files
├── srcs/
│   ├── events/
│   │   ├── hooks.c           # Key press/release handlers, close handler
│   │   └── hooks_2.c         # game_loop, setup_hooks, mouse tracking
│   ├── init/
│   │   ├── init_data.c       # MLX init, window/image creation
│   │   ├── init_sprite.c     # Sprite sheet loading and setup
│   │   ├── init_sprite2.c    # Directional sprite variants
│   │   └── init_textures.c   # Load wall/floor/ceiling textures from paths
│   ├── parsing/
│   │   ├── debug_parsing.c   # Debug printer for config, map and player state
│   │   ├── parse_colors.c    # RGB color parsing (F / C lines)
│   │   ├── parse_elements.c  # Texture path parsing and file existence check
│   │   ├── parse_file.c      # Entry point — reads .cub, dispatches to sub-parsers
│   │   ├── parse_map.c       # Map grid construction line by line
│   │   ├── parse_utils.c     # skip_spaces, is_empty_line, is_valid_map_char
│   │   ├── validate_map.c    # Flood-fill closure check, player extraction
│   │   └── validate_map_2.c  # Player direction vectors setup
│   ├── player/
│   │   ├── interact.c        # Door open/close on Space
│   │   ├── movement.c        # move_forward/backward, strafe + collision
│   │   └── rotation.c        # rotate_left/right using 2D rotation matrix
│   ├── raycasting/
│   │   ├── dda.c             # DDA traversal — finds first wall/door hit
│   │   ├── raycasting.c      # Ray init, step/side dist calculation, main loop
│   │   ├── render_floor_ceiling.c  # Textured floor & ceiling with cell variation
│   │   └── render_walls.c    # draw_column() — wall slice with texture mapping
│   ├── render/
│   │   ├── draw.c            # put_pixel() — bounds-checked pixel write
│   │   ├── minimap.c         # Top-down minimap rendering
│   │   └── render_character.c# Animated sprite — walk cycle, sprint detection
│   └── utils/
│       ├── error.c           # print_error() and error codes
│       ├── free.c            # free_all, free_config, free_map
│       └── utils.c           # General helpers
└── main.c                    # parse → init → hooks → mlx_loop
```

**Rendering pipeline (per frame):**

```
mlx_loop_hook
     │
     ▼
render_floor_ceiling()   ← textured floor & ceiling rows
     │
     ▼
perform_raycasting()     ← for each column x:
     │                      init_ray → calculate_step → DDA → draw_column
     ▼
draw_minimap()           ← overlay top-down map
     │
     ▼
character_rander_loop()  ← animated sprite overlay (bottom-right)
     │
     ▼
mlx_put_image_to_window()
```

---

## 🧮 Technical Highlights

**DDA (Digital Differential Analysis)** — rather than checking every point along a ray, the DDA algorithm jumps directly from grid line to grid line, making each ray-cast O(map_size) instead of O(resolution). Side distances are precomputed and incremented, with the shorter one selected each step.

**Perpendicular wall distance** — to avoid the fisheye distortion that comes from using Euclidean distance, the projected wall height is computed from `perp_wall_dist` — the distance to the wall plane perpendicular to the camera direction, not to the player position.

**Camera plane** — the FOV is represented as a 2D vector perpendicular to the direction vector, with length 0.66 (≈66° FOV). Rotation applies a 2D matrix to both `dir` and `plane` simultaneously, preserving their perpendicularity.

**Textured floor/ceiling** — the floor is cast by projecting each screen row back into world space using the inverse of the projection formula. Per-cell texture variation is achieved with a hash `(cell_x * 7 + cell_y * 13) % NB_CEIL_TEX`, giving deterministic but varied ceiling patterns without any overhead.

**Mouse lock** — mouse events move the camera via `camera_track`, then `mlx_mouse_move` recenters the cursor to `WIN_WIDTH/2` every frame. This creates infinite-rotation mouse look without the cursor ever reaching the screen edge.

**Flood-fill map validation** — a copy of the map grid is flood-filled from the player's spawn. If the fill reaches any out-of-bounds coordinate or a space character, the map is considered open and rejected. This correctly catches non-rectangular maps with irregular borders.

---

## 🔧 Instructions

**Prerequisites:** `gcc`, `make`, MiniLibX, X11 dev libraries

```bash
# Ubuntu / Debian
sudo apt-get install libx11-dev libxext-dev libbsd-dev

git clone https://github.com/<your-username>/cub3d.git
cd cub3d
make

./cub3d maps/map.cub
```

```bash
make clean    # Remove object files
make fclean   # Remove objects + binary
make re       # Full rebuild
```

---

## 📚 Resources

- [Lode's raycasting tutorial](https://lodev.org/cgtutor/raycasting.html) — the reference implementation
- [DDA algorithm — Wikipedia](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
- [Wolfenstein 3D engine overview](https://en.wikipedia.org/wiki/Wolfenstein_3D)
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)

**AI usage:** AI was used exclusively for README writing and formatting. All source code was written manually without AI assistance, in compliance with the 42 AI policy for foundational projects.

---

<div align="center">

Made with ☕ at [42 Le Havre](https://42lehavre.fr) — **aronnet & jcrochet**

</div>
