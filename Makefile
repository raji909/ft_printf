NAME		= libftprintf.a
HEADER		= ft_printf.h

CC			= cc
CFLAG		= -Wall -Wextra -Werror

SRC			= ft_printf.c ft_putaddress.c ft_putchar.c ft_puthexa.c \
			  ft_putnbr.c ft_putstr.c ft_putunbr.c ft_strcpy.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
