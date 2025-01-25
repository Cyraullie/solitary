
NAME = solitary

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I/usr/include

# MLX Library Configuration
MLX_PATH = /usr/lib/
MLX_LIB = -L$(MLX_PATH) -lmlx -lm -lz -lX11 -lXext -lXrandr -lXinerama -lXi -lXcursor
MLX_INC = -I/usr/include

SRC = main.c
OBJ = $(SRC:.c=.o)

# Colors for output
GREEN = \033[1;32m
RESET = \033[0m

all: header $(NAME)

header:
	@echo "$(GREEN)"
	@echo ".------..------..------..------..------..------..------..------."
	@echo "|S.--. ||O.--. ||L.--. ||I.--. ||T.--. ||A.--. ||R.--. ||Y.--. |"
	@echo "| :/\: || :/\: || :/\: || (\/) || :/\: || (\/) || :(): || (\/) |"
	@echo "| :\/: || :\/: || (__) || :\/: || (__) || :\/: || ()() || :\/: |"
	@echo "| '--'S|| '--'O|| '--'L|| '--'I|| '--'T|| '--'A|| '--'R|| '--'Y|"
	@echo "\`------'\`------'\`------'\`------'\`------'\`------'\`------'\`------'"
	@echo "$(RESET)"

$(NAME): $(OBJ)
	@echo "$(GREEN)Building $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	@echo "$(GREEN)Cleaning up...$(RESET)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(GREEN)Removing $(NAME)...$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
