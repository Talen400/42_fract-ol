NAME = fractol

CC = cc
FLAGS = -g -Wall -Werror -Wextra

MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lbsd -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

SRC = main.c

OBJ_F = objs
OBJ = $(addprefix $(OBJ_F)/,$(SRC:.c=.o))

LIBFT_DIR = libft
LIBFT = libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(OBJ_F) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "\n$(GREEN)> Compilating fractol...$(RESET)\n"
	$(CC) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJ_F)/%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

$(OBJ_F):
	@echo "\n$(GREEN)> Compilating fractol...$(RESET)\n"
	mkdir $@

$(MLX):
	@echo "\n$(YELLOW)> Compilation MinilibX...$(RESET)"
	make -C $(MLX_DIR)

$(LIBFT):
	@echo "\n$(YELLOW)> Compilation libft...$(YELLOW)"
	make -C $(LIBFT_DIR) bonus

clean:
	@echo "\n$(RED)> Cleaning objs...$(RESET)\n"
	rm -rf $(OBJ_F)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	@echo "\n$(RED)> Cleaning binaries and objs...$(RESET)\n"
	rm -f $(NAME) $(NAME_TEST)
	make -C $(LIBFT_DIR) fclean
	rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re
