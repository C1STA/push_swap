NAME = push_swap
NAME_BONUS = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c\
		swap.c\
		push.c\
		rotate.c\
		reverse_rotate.c\
		index.c\
		ft_atoi.c\
		list.c\
		checks.c\
		algo_sort.c\
		algo_presort.c\
		calcul.c\
		position.c\
		sort_moves.c\


SRCS_BONUS = checker.c\
			ft_atoi.c\
			list.c\
			index.c\
			checks.c\
			get_next_line.c\
			get_next_line_utils.c\
			swap.c\
			push.c\
			rotate.c\
			reverse_rotate.c\

OBJS = $(SRCS:%.c=build/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=build/%.o)

build/%.o: %.c
	@mkdir -p build
	${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)

clean:
	@rm -rf  build
	@echo "Build folder erased, cya .."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "Mr Propre ;)"

re: fclean all
