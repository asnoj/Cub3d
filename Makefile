# **************************************************************************** #
#                                                                              #
#    cub3D - Makefile                                                          #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -O3
RM          = rm -rf

SRC_DIR     = srcs
OBJ_DIR     = objs
INC_DIR     = includes
LIBFT_DIR   = libft
GNL_DIR     = gnl
MLX_DIR     = minilibx-linux
MLX_REPO    = https://github.com/42Paris/minilibx-linux.git

#  Main
SRCS        = $(SRC_DIR)/main.c

#  Parsing
SRCS        += $(SRC_DIR)/parsing/parse_file.c \
               $(SRC_DIR)/parsing/parse_elements.c \
               $(SRC_DIR)/parsing/parse_colors.c \
               $(SRC_DIR)/parsing/parse_map.c \
               $(SRC_DIR)/parsing/validate_map.c \
               $(SRC_DIR)/parsing/parse_utils.c \
               $(SRC_DIR)/parsing/validate_map_2.c

#  Init
SRCS        += $(SRC_DIR)/init/init_data.c \
               $(SRC_DIR)/init/init_sprite.c \
               $(SRC_DIR)/init/init_sprite2.c \
               $(SRC_DIR)/init/init_textures.c

#  Raycasting
SRCS        += $(SRC_DIR)/raycasting/raycasting.c \
               $(SRC_DIR)/raycasting/dda.c \
               $(SRC_DIR)/raycasting/render_floor_ceiling.c \
               $(SRC_DIR)/raycasting/render_walls.c

#  Player
SRCS        += $(SRC_DIR)/player/movement.c \
               $(SRC_DIR)/player/rotation.c \
               $(SRC_DIR)/player/interact.c

#  Render
SRCS        += $(SRC_DIR)/render/draw.c \
               $(SRC_DIR)/render/render_character.c \
               $(SRC_DIR)/render/minimap.c

#  Events
SRCS        += $(SRC_DIR)/events/hooks.c \
               $(SRC_DIR)/events/hooks_2.c

#  Utils
SRCS        += $(SRC_DIR)/utils/error.c \
               $(SRC_DIR)/utils/free.c \
               $(SRC_DIR)/utils/utils.c

#  Debug (à retirer avant la correction)
SRCS        += $(SRC_DIR)/parsing/debug_parsing.c

#  GNL
GNL_SRCS    = $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c

OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)
GNL_OBJS    = $(GNL_SRCS:%.c=$(OBJ_DIR)/%.o)
ALL_OBJS    = $(OBJS) $(GNL_OBJS)

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

INCLUDES    = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)

GREEN       = \033[1;32m
YELLOW      = \033[1;33m
CYAN        = \033[1;36m
RESET       = \033[0m

all:        $(NAME)

$(NAME):    $(LIBFT) $(MLX) $(ALL_OBJS)
	@$(CC) $(CFLAGS) $(ALL_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully$(RESET)"

$(LIBFT):
	@echo "$(CYAN)► Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "$(CYAN)► Cloning miniLibX...$(RESET)"; \
		git clone $(MLX_REPO) $(MLX_DIR) --quiet; \
	fi
	@echo "$(CYAN)► Compiling miniLibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --silent

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/cub3d.h $(INC_DIR)/defines.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)  Compiling: $<$(RESET)"

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean --silent; fi
	@echo "$(CYAN)✓ Object files cleaned$(RESET)"

fclean:     clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@$(RM) $(MLX_DIR)
	@echo "$(CYAN)✓ $(NAME) and miniLibX removed$(RESET)"

re:         fclean all

bonus:      all

.PHONY:     all clean fclean re bonus