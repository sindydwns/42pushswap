# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:29:59 by yonshin           #+#    #+#              #
#    Updated: 2022/11/02 17:05:20 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARFLAGS = rc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I
OBJECTS = \
	get_next_line_utils.o \
	get_next_line.o \

LIB = \
	../libft/libft.a \

all: $(NAME)

$(NAME): $(OBJECTS)
	ar $(ARFLAGS) $@ $^

$(LIB):
	make -C $(@D)

%.o: %.c
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(addprefix -I, $(dir $(LIB))) -c $*.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	make -C $(dir $(LIB)) fclean

re: fclean
	make all

.PHONY: all bonus clean fclean re
