# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 17:06:28 by yonshin           #+#    #+#              #
#    Updated: 2022/11/01 18:19:45 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
OBJS = \
	parse_integer.o \
	rank_integer.o \
	dequeue.o \
	create_dequeue.o \
	destroy_dequeue.o \
	instruction_push.o \
	instruction_swap.o \
	instruction_rotate.o \
	instruction_rrotate.o \
	solve.o \
	create_solution.o \
	ps_sandglass.o
TARGET_OBJS = $(OBJS) push_swap.o
CHECKER_OBJS = $(OBJS) checker.o
LIB = ./lib/libft.a

all: $(NAME)

$(NAME): $(TARGET_OBJS) $(LIB)
	cc -Wall -Wextra -Werror $(TARGET_OBJS) $(LIB)

clean:
	rm -f $(TARGET_OBJS)
	rm -f $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)

re: 
	make fclean
	make all

bonus: $(CHECKER_OBJS)
	cc -Wall -Wextra -Werror $(CHECKER_OBJS) $(LIB)


#ifndef PROGRAM
	PROGRAM := $(NAME)
#endif
#ifndef SIZE
	SIZE := 10
#endif

test: all bonus
	seq $(SIZE) | sort -R | xargs ./$(PROGRAM)

.PHONY : all clean fclean re bonus test
