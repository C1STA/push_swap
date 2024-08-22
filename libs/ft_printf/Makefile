NAME = libftprintf.a

CC = cc -Wall -Wextra -Werror

SRCS=	ft_printf.c \
		ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

AR = ar rcs
RM = rm -f

all:	$(NAME)

%.o: %.c
		@$(CC) -c $< -o $@

$(NAME): $(OBJS)
		@$(AR) $(NAME) $^

clean:
	@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re