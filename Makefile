NAME = libftprintf.a

SRC = ft_printf.c ft_functions.c ft_itoa.c ft_hex.c ft_ptr.c ft_unsigned_int.c \

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) -r $@ $?

.o: .c
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re libft