NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lX11 -lXext
LIBFT_DIR = ./Libft
PRINTF_DIR = ./printf
MLX_DIR = ./minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a
MLX_EX = $(MLX) $(MLX_FLAGS)

SRCS = ./src/main.c \
	   ./src/get_map.c \
	   ./src/map.c \
	   ./src/map_check.c \
	   ./src/utils.c \
	   ./src/flood_fill.c \
	   ./src/initialize_struct.c \
	   ./src/key_hook.c \
	   ./src/movements.c \
	   ./src/free_all.c \
	   ./src/ber_check.c \
	   ./get_next_line/get_next_line_utils.c \
	   ./get_next_line/get_next_line.c \
	   ./get_next_line/get_next_utils.c \

OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

# Build so_long
$(NAME): libft printf mlx $(OBJS)
	@echo "\033[1;93m [WAIT]\033[0m\t\033[1;35m so_long is being built...\033[0m"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m [OK] \033[0m\t\033[1;35m so_long built successfully!\033[0m"

# Build libft library
libft:
	@echo "\033[1;93m [WAIT]\033[0m\t\033[1;35m libft is being built...\033[0m"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "\033[1;32m [OK] \033[0m\t\033[1;35m libft built successfully!\033[0m"

# Build ft_printf library
printf:
	@echo "\033[1;93m [WAIT]\033[0m\t\033[1;35m printf is being built...\033[0m"
	@$(MAKE) -s -C $(PRINTF_DIR)
	@echo "\033[1;32m [OK] \033[0m\t\033[1;35m printf built successfully!\033[0m"

mlx:
	@echo "\033[1;93m [WAIT]\033[0m\t\033[1;35m MLX is being built...\033[0m"
	@$(MAKE) -s -C $(MLX_DIR) > /dev/null 2>&1
	@echo "\033[1;32m [OK] \033[0m\t\033[1;35m MLX built successfully!\033[0m"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "\033[1;32m [OK] \033[0m\t\033[1;35m removing object files...\033[0m"
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(PRINTF_DIR) clean

# Clean everything (including compiled libraries and binaries)
fclean: clean
	@echo "\033[1;32m [OK] \033[0m\t\033[1;35m removing binary and libraries...\033[0m"
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re libft printf mlx