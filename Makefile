NAME = cub3D
NAME_BONUS = cub3D_bonus
LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
COMPRESS = ar rcs
RM = rm -rf

# Mandatory files
SRC_DIR = sources/sources_normal
OBJ_DIR = objects
SRC_DIRS = $(SRC_DIR)/1.read_input $(SRC_DIR)/2.validate_input $(SRC_DIR)/3.init_mlx \
			$(SRC_DIR)/4.raycast $(SRC_DIR)/5.movements $(SRC_DIR)/main_utils $(SRC_DIR)
SRC_READ_INPUT = read_input.c read_input_utils.c read_map_utils.c read_textures_utils.c read_textures_utils2.c
SRC_VALIDATE_INPUT = validate_map_utils.c validate_map_utils2.c validate_map.c
SRC_INIT_MLX = init_mlx.c init_textures.c start_game.c
SRC_RAYCAST = raycaster_utils.c raycaster_utils2.c raycaster.c
SRC_MOVEMENTS = events.c movements.c
SRC_MAIN_UTILS = close_program.c free.c init_map.c print_file.c
SRC_MAIN = cub3d.c
SRC =
SRC += $(addprefix $(SRC_DIR)/1.read_input/,$(SRC_READ_INPUT))
SRC += $(addprefix $(SRC_DIR)/2.validate_input/,$(SRC_VALIDATE_INPUT))
SRC += $(addprefix $(SRC_DIR)/3.init_mlx/,$(SRC_INIT_MLX))
SRC += $(addprefix $(SRC_DIR)/4.raycast/,$(SRC_RAYCAST))
SRC += $(addprefix $(SRC_DIR)/5.movements/,$(SRC_MOVEMENTS))
SRC += $(addprefix $(SRC_DIR)/main_utils/,$(SRC_MAIN_UTILS))
SRC += $(addprefix $(SRC_DIR)/,$(SRC_MAIN))
OBJ = $(SRC:$(SRC_DIRECTORY)/%.c=$(OBJ_DIR)/%.o)

# Bonus files
BONUS_DIR = sources/sources_bonus
OBJ_BONUS_DIR = bonus_objects
BONUS_DIRS = $(BONUS_DIR)/1.read_input $(BONUS_DIR)/2.validate_input $(BONUS_DIR)/3.init_mlx \
			$(BONUS_DIR)/4.raycast $(BONUS_DIR)/5.movements $(BONUS_DIR)/6.minimap \
			$(BONUS_DIR)/7.sprites $(BONUS_DIR)/main_utils $(BONUS_DIR)
BONUS_READ_INPUT = read_input_bonus.c read_input_utils_bonus.c read_map_utils_bonus.c read_textures_utils_bonus.c read_textures_utils_bonus2.c
BONUS_VALIDATE_INPUT = validate_map_utils_bonus.c validate_map_utils2_bonus.c validate_map_bonus.c
BONUS_INIT_MLX = init_mlx_bonus.c init_textures_bonus.c init_textures_utils_bonus.c start_game_bonus.c start_game_utils_bonus.c
BONUS_RAYCAST = raycaster_utils_bonus.c raycaster_utils2_bonus.c raycaster_bonus.c
BONUS_MOVEMENTS = events_bonus.c movements_bonus.c movements_utils_bonus.c
BONUS_MINIMAP= draw_ray_utils_bonus.c minimap_bonus.c minimap_rays_bonus.c minimap_rays_utils_bonus.c minimap_utils_bonus.c
BONUS_SPRITES = enemies_position_bonus.c sprites_bonus.c sprites_utils_bonus.c sprites_utils2_bonus.c weapon_bonus.c
BONUS_MAIN_UTILS = close_program_bonus.c free_bonus.c init_map_bonus.c print_file_bonus.c
BONUS_MAIN = cub3d_bonus.c
BONUS =
BONUS += $(addprefix $(BONUS_DIR)/1.read_input/,$(BONUS_READ_INPUT))
BONUS += $(addprefix $(BONUS_DIR)/2.validate_input/,$(BONUS_VALIDATE_INPUT))
BONUS += $(addprefix $(BONUS_DIR)/3.init_mlx/,$(BONUS_INIT_MLX))
BONUS += $(addprefix $(BONUS_DIR)/4.raycast/,$(BONUS_RAYCAST))
BONUS += $(addprefix $(BONUS_DIR)/5.movements/,$(BONUS_MOVEMENTS))
BONUS += $(addprefix $(BONUS_DIR)/6.minimap/,$(BONUS_MINIMAP))
BONUS += $(addprefix $(BONUS_DIR)/7.sprites/,$(BONUS_SPRITES))
BONUS += $(addprefix $(BONUS_DIR)/main_utils/,$(BONUS_MAIN_UTILS))
BONUS += $(addprefix $(BONUS_DIR)/,$(BONUS_MAIN))
BONUS_OBJ = $(BONUS:$(BONUS_DIRECTORY)/%.c=$(OBJ_BONUS_DIR)/%.o)

# Detecting system
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_DIR = libraries/minilibx-linux
	MLX = $(MLX_DIR)/libmlx_Linux.a
	MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
	CFLAGS += -DLINUX
else
	MLX_DIR = libraries/minilibx-mac
	MLX = $(MLX_DIR)/libmlx.a
	MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/libmlx
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# Colours
GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)
	@echo "$(CYAN)make$(RESET)   $@ $(GREEN)[OK]$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS_DIR) $(BONUS_OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(CYAN)make$(RESET)   bonus $(GREEN)[OK]$(RESET)"

$(MLX):
	@$(MAKE) -s -C $(MLX_DIR) --no-print-directory

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(foreach dir, $(SRC_DIRS), $(OBJ_DIR)/$(notdir $(dir))) \
		$(foreach dir, $(BONUS_SRC_DIRS), $(OBJ_DIR)/$(notdir $(dir)))

$(OBJ_DIR)/%.o: $(SRC_DIR)/1.read_input/%.c $(SRC_DIR)/2.validate_input/%.c \
				$(SRC_DIR)/3.init_mlx/%.c $(SRC_DIR)/4.raycast/%.c $(SRC_DIR)/5.movements/%.c \
				$(SRC_DIR)/main_utils/%.c $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR) $(foreach dir, $(BONUS_DIRS), $(OBJ_BONUS_DIR)/$(notdir $(dir))) \
		$(foreach dir, $(BONUS_SRC_DIRS), $(OBJ_BONUS_DIR)/$(notdir $(dir)))

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/1.read_input/%.c $(BONUS_DIR)/2.validate_input/%.c \
				$(BONUS_DIR)/3.init_mlx/%.c $(BONUS_DIR)/4.raycast/%.c $(BONUS_DIR)/5.movements/%.c \
				$(BONUS_DIR)/6.minimap $(BONUS_DIR)/7.sprites $(BONUS_DIR)/main_utils/%.c $(BONUS_DIR)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"

re: fclean all

v: all
	@echo "\n"
	valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME) maps/map_small.cub

.PHONY: all clean fclean re bonus v
