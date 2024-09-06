RED		=\033[0;31m
CYAN	=\033[0;36m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
WHITE	=\033[0;37m

CC		= cc
RM		= rm -rf
NAME	= push_swap
NAME_B	= checker
INC		= -I inc/
CFLAGS	= -Wall -Wextra -Werror

SRCPATH	= src/
SRC	=	main.c \
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

SRCP_B	= src/
SRC_B	=	bonus_checker.c \
		list.c \
		index.c \
		parse.c \
		get_next_line.c \
		get_next_line_utils.c \
		instruction_swap.c \
		instruction_push.c \
		instruction_rotate.c \
		instruction_rev_rotate.c \

OBJDIR	= obj/
OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJ_B	= $(addprefix $(OBJDIR), $(SRC_B:.c=.o))

DEPDIR	= dep/
DEP		= $(addprefix $(DEPDIR), $(SRC:.c=.d))
DEP_B	= $(addprefix $(DEPDIR), $(SRC_B:.c=.d))

all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(CYAN)Linking $(NAME)...$(WHITE)"
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "$(GREEN)Done$(WHITE)"

$(OBJDIR)%.o: $(SRCPATH)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DEPDIR)%.d: $(SRCPATH)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -MM $< -MT $(@:.d=.o) -MF $@ -MP

-include $(DEP)

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B)
		@echo "$(CYAN)Linking $(NAME_B)...$(WHITE)"
		@$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)
		@echo "$(GREEN)Done$(WHITE)"

$(OBJDIR)%.o: $(SRCP_B)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DEPDIR)%.d: $(SRCP_B)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -MM $< -MT $(@:.d=.o) -MF $@ -MP

-include $(DEP_B)

clean:
		@echo "$(RED)Cleaning $(NAME)...$(WHITE)"
		@$(RM) $(OBJDIR) $(DEPDIR)
		@echo "$(GREEN)Done$(WHITE)"

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(NAME_B)

re: fclean all

norm:
	@echo "$(YELLOW)Executing norminette...$(WHITE)"
	@norminette inc/*
	@norminette src/*

.PHONY: all clean fclean re norm