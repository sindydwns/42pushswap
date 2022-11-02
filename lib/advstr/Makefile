# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:29:59 by yonshin           #+#    #+#              #
#    Updated: 2022/11/02 17:06:02 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARFLAGS = rc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
LIB = \
	./get_next_line/libft.a \
	./libft/libft.a \
	./advlst/libft.a \
	./advstr/libft.a \
	./ft_printf/libft.a \

all: $(NAME)

$(NAME): $(LIB)

$(LIB):
	make -C $(@D)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	make -C $(dir $(LIB)) fclean

re: fclean
	make all

.PHONY: all bonus clean fclean re