NAME = solitary

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx_linux/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS =  -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

SRC = main.c

OBJ = $(SRC:.c=.o)

GREEN = \033[1;32m
CYAN = \033[1;36m
YELLOW = \033[1;33m
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
	@echo "\`------'\`------'\`------'\`------'\`------'\`------'\`------'\`------'"
	@echo "$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(MLX_PATH) fclean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re