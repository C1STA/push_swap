RED		=\033[0;31m
CYAN	=\033[0;36m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
WHITE	=\033[0;37m

CC		= cc
RM		= rm -rf
NAME	= push_swap
INC		= -I inc/
CFLAGS	= -Wall -Wextra -Werror

SRCPATH	= src/
SRC		= main.c \
		index.c \
		list.c \
		parse.c \
		instruction_swap.c \
		instruction_push.c \
		instruction_rotate.c \
		instruction_rev_rotate.c \
		sort.c \
		pre_sort.c \
		position.c \
		cost.c \
		exec.c

OBJDIR	= obj/
OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

DEPDIR	= dep/
DEP		= $(addprefix $(DEPDIR), $(SRC:.c=.d))

all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(CYAN)Linking $(NAME)...$(WHITE)"
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "$(GREEN)Done$(WHITE)"

$(OBJDIR)%.o: $(SRCPATH)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@ -g

$(DEPDIR)%.d: $(SRCPATH)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -MM $< -MT $(@:.d=.o) -MF $@ -MP

-include $(DEP)

clean:
		@echo "$(RED)Cleaning $(NAME)...$(WHITE)"
		@$(RM) $(OBJDIR) $(DEPDIR)
		@echo "$(GREEN)Done$(WHITE)"

fclean: clean
		@$(RM) $(NAME)

re: fclean all

norm:
	@echo "$(YELLOW)Executing norminette...$(WHITE)"
	@norminette inc/*
	@norminette src/*

.PHONY: all clean fclean re norm