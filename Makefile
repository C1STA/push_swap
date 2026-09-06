NAME = push_swap
BONUS_NAME = checker

CC = cc
CPPFLAGS = -I inc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

COMMON_SRC = index.c list.c parse.c instruction_swap.c instruction_push.c \
		instruction_rotate.c instruction_rev_rotate.c
PUSH_SWAP_SRC = main.c sort.c pre_sort.c position.c cost.c exec.c
CHECKER_SRC = bonus_checker.c get_next_line.c get_next_line_utils.c

COMMON_OBJ = $(addprefix $(OBJ_DIR)/,$(COMMON_SRC:.c=.o))
PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR)/,$(PUSH_SWAP_SRC:.c=.o))
CHECKER_OBJ = $(addprefix $(OBJ_DIR)/,$(CHECKER_SRC:.c=.o))
DEP = $(COMMON_OBJ:.o=.d) $(PUSH_SWAP_OBJ:.o=.d) $(CHECKER_OBJ:.o=.d)

all: $(NAME)

$(NAME): $(COMMON_OBJ) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(COMMON_OBJ) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

-include $(DEP)

.PHONY: all bonus clean fclean re
