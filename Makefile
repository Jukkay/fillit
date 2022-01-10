# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htahvana <htahvana@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 12:35:33 by htahvana          #+#    #+#              #
#    Updated: 2022/01/10 12:02:36 by htahvana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra

INCL = -I ./libft/includes

LIB = -L ./libft -lft

SRCS = manage_short.c read_file.c checker.c solver.c map.c \
		printsquare.c fillit.c lists.c

all: $(NAME)

$(NAME):
	make -C ./libft re
	gcc $(CFLAGS) $(INCL) $(SRCS) $(LIB) -o $(NAME)

clean:
	make -C ./libft clean
	/bin/rm -f *.o

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all

reclean:
		$(MAKE) re
		$(MAKE) clean
