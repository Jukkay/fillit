# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 10:15:03 by htahvana          #+#    #+#              #
#    Updated: 2022/01/03 12:16:05 by htahvana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

INCL = -I ./includes

FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
	ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_strcat.c \
	ft_strlcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strclr.c \
	ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strdel.c \
	ft_strdup.c ft_strequ.c ft_strnequ.c ft_striter.c ft_striteri.c \
	ft_strjoin.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strnew.c \
	ft_strstr.c ft_strnstr.c ft_strsplit.c ft_strsub.c ft_strtrim.c \
	ft_tolower.c ft_toupper.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
	ft_lstiter.c ft_lstnew.c ft_lstmap.c ft_abs.c ft_intdigits.c \
	ft_islower.c ft_isupper.c ft_iswhitespace.c ft_strnlen.c \
	ft_lstput.c ft_lstsplit.c ft_freeclr.c ft_lstdelto.c ft_lstpopi.c \
	ft_strclen.c ft_math_sign.c ft_lstsize.c ft_memtrim.c \
	ft_lstlen.c ft_lstjoin.c ft_strjoinfree.c ft_get_next_line.c ft_strchri.c \
	ft_strsubfree.c ft_newpoint.c ft_setpoint.c



OBJS = $(FILES:.c=.o)
SRCS = $(FILES:%.c=srcs/%.c)

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(INCL) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

reclean:
		$(MAKE) re
		$(MAKE) clean

