# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 12:35:33 by htahvana          #+#    #+#              #
#    Updated: 2021/12/13 12:40:28 by htahvana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra

INCL = -I ./libft/includes

LIB = -L ./libft

SRCS = savetoshort.c


all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(INCL) $(SRCS) $(LIB)

clean:


fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

reclean:
		$(MAKE) re
		$(MAKE) clean
