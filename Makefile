RED		=\033[0;31m
CYAN	=\033[0;36m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
WHITE	=\033[0;37m

CC		= cc
RM		= rm -rf
NAME	= push_swap
INC		= -I inc/ -I libs/ft_printf
CFLAGS	= -Wall -Wextra -Werror -g

SRCPATH	= src/
SRC		= main.c \
		ft_atoi.c \
		index.c \
		list.c \
		parse.c \
		swap.c

OBJDIR	= obj/
OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

DEPDIR	= dep/
DEP		= $(addprefix $(DEPDIR), $(SRC:.c=.d))

PRINTF_DIR	= libs/ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

all: $(PRINTF) $(NAME)

$(PRINTF):
		@echo "$(YELLOW)Building ft_printf...$(WHITE)"
		@$(MAKE) --no-print-directory -C $(PRINTF_DIR)

$(NAME): $(OBJ)
		@echo "$(CYAN)Linking $(NAME)...$(WHITE)"
		@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)
		@echo "$(GREEN)Done$(WHITE)"

$(OBJDIR)%.o: $(SRCPATH)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@ -g

$(DEPDIR)%.d: $(SRCPATH)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -MM $< -MT $(@:.d=.o) -MF $@ -MP

-include $(DEP)

clean:
		@echo "$(RED)Cleaning $(NAME) build artifacts...$(WHITE)"
		@$(RM) $(OBJDIR) $(DEPDIR)
		@$(MAKE) --no-print-directory -C $(PRINTF_DIR) clean
		@echo "$(GREEN)Done$(WHITE)"

fclean:
		@echo "$(RED)Cleaning $(NAME) binary and build artifacts...$(WHITE)"
		@$(RM) $(OBJDIR) $(DEPDIR)
		@$(RM) $(NAME)
		@$(MAKE) --no-print-directory -C $(PRINTF_DIR) fclean
		@echo "$(GREEN)Done$(WHITE)"

re: fclean all

norm:
	@echo "$(YELLOW)Executing norminette...$(WHITE)"
	@norminette $(addprefix $(SRCPATH), $(SRC))

.PHONY: all clean fclean re norm