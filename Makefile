# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adraji <adraji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 15:47:54 by adraji            #+#    #+#              #
#    Updated: 2025/11/01 13:08:37 by adraji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
HEADER		= ft_printf.h

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

BONUS		= bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I $(LIBFT_DIR) -I .

SRC_LIBFT	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			  ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
			  ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			  ft_strmapi.c ft_striteri.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c ft_putchar_fd.c \
			  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c ft_lstnew_bonus.c \
			  ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			  ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRC_BONUS	= ft_dashflag_bonus.c   ft_doteflag_bonus.c  ft_plusflag_bonus.c  ft_spaceflag_bonus.c \
			  ft_digitflag_bonus.c  ft_hashflag_bonus.c  ft_printf_bonus.c    ft_zeroflag_bonus.c

SRC			= $(addprefix $(LIBFT_DIR)/, $(SRC_LIBFT)) \
			  $(addprefix $(BONUS)/, $(SRC_BONUS)) \
			  ft_printf.c ft_putchar.c ft_putstr.c ft_utoa.c \
			  ft_hexa.c ft_address.c

OBJ			= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
