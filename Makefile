NAME		= solitary

CC			= gcc
CFLAGS		= -Wextra -Wall -Werror -g 

LIBFTDIR	= libft/
LIBFT		= $(LIBFTDIR)libft.a
MLXDIR		= minilibx-linux/
MLX			= $(MLXDIR)libmlx.a

INCLUDES	= include/solitary.h
SRCDIR		= srcs/
OBJDIR		= objs/

SRCS		= $(addprefix $(SRCDIR), main.c init_img.c)
OBJS 		= $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

# Colors for output
END		:= \033[0m
WHITE	:= \033[1;37m
NC		:= \033[0m
PINK	:= \033[1;35m
GREEN	:= \033[32m
BOLD	:= \033[1m
L_PURPLE:= \033[38;5;55m
YELLOW	:= \033[33m
BLUE	:= \033[34m

# Règles
all: ${NAME} $(LIBFT) $(MLX) header

header:
	@echo "$(GREEN)"
	@echo ".------..------..------..------..------..------..------..------."
	@echo "|S.--. ||O.--. ||L.--. ||I.--. ||T.--. ||A.--. ||R.--. ||Y.--. |"
	@echo "| :/\: || :/\: || :/\: || (\/) || :/\: || (\/) || :(): || (\/) |"
	@echo "| :\/: || :\/: || (__) || :\/: || (__) || :\/: || ()() || :\/: |"
	@echo "| '--'S|| '--'O|| '--'L|| '--'I|| '--'T|| '--'A|| '--'R|| '--'Y|"
	@echo "\------'\------'\------'\------'\------'\------'\------'\------'"
	@echo "$(RESET)"

$(NAME): $(OBJS) $(INCLUDES) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLXDIR) -lmlx -L$(LIBFTDIR) -lft -lXext -lX11 -lm -lbsd -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLXDIR)


${OBJDIR}/%.o: %.c | ${OBJDIR}
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@printf "${BOLD}${L_PURPLE}⚡ [%2d/%2d] Compiling: %-20s ${END}" $(CURRENT_FILE) $(TOTAL_FILES) "$<"
	@${CC} ${CFLAGS} -I./minilibx_linux -c $< -o $@
	@echo "${BOLD}${GREEN}✓${END}"

clean:
	@echo "${BOLD}${YELLOW}🧹 Cleaning objects...${END}"
	@rm -rf ${OBJDIR}
	@${MAKE} -C ./libft/ clean
	@echo "${BOLD}${GREEN}✓ Clean complete${END}"

fclean: clean
	@echo "${BOLD}${YELLOW}🗑️  Deep cleaning...${END}"
	@rm -f ${NAME}
	@${MAKE} -C ./libft/ fclean
	@echo "${BOLD}${GREEN}✨ All clean ✨${END}"

re: fclean all

.PHONY: all clean fclean re