NAME = solitary

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx_linux/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux \
            -lX11 -lXext -lXrandr -lXrender -lm -lz -Wl,--no-as-needed

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

SRC = main.c

INCLUDES = -Imlx -Ilibft

OBJ = $(SRC:.c=.o)

# Colors for output
GREEN = \033[1;32m
RESET = \033[0m

# Règles
all: subsystems header $(NAME)

header:
	@echo "$(GREEN)"
	@echo ".------..------..------..------..------..------..------..------."
	@echo "|S.--. ||O.--. ||L.--. ||I.--. ||T.--. ||A.--. ||R.--. ||Y.--. |"
	@echo "| :/\: || :/\: || :/\: || (\/) || :/\: || (\/) || :(): || (\/) |"
	@echo "| :\/: || :\/: || (__) || :\/: || (__) || :\/: || ()() || :\/: |"
	@echo "| '--'S|| '--'O|| '--'L|| '--'I|| '--'T|| '--'A|| '--'R|| '--'Y|"
	@echo "\------'\------'\------'\------'\------'\------'\------'\------'"
	@echo "$(RESET)"

re: fclean all

.PHONY: all clean fclean re

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES)  -I/usr/include -Imlx_linux -O3 -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJ)
	@echo "$(GREEN)Building $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	@echo "$(GREEN)Cleaning up...$(RESET)"
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	@echo "$(GREEN)Removing $(NAME)...$(RESET)" 
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re