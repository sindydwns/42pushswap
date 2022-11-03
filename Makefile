# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 17:06:28 by yonshin           #+#    #+#              #
#    Updated: 2022/11/03 23:10:46 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP = push_swap
CHECKER = checker
CFLAGS = -Wall -Wextra -Werror
OBJS = \
	parse_integer.o \
	ranking.o \
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
PUSHSWAP_OBJS = $(OBJS) push_swap.o
CHECKER_OBJS = $(OBJS) checker.o
LIB = ./lib/libft.a

INCLUDE = \
	-I./lib/libft/ \
	-I./lib/get_next_line/ \

all: $(PUSHSWAP)

bonus: $(CHECKER)

$(PUSHSWAP): $(PUSHSWAP_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(PUSHSWAP_OBJS) $(LIB) $(OUTPUT_OPTION)

$(CHECKER): $(CHECKER_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIB) $(OUTPUT_OPTION)

$(LIB):
	make -C $(@D)

%.o: %.c
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(INCLUDE) -c $*.c

clean:
	rm -f $(PUSHSWAP_OBJS)
	rm -f $(CHECKER_OBJS)

fclean: clean
	make -C $(dir $(LIB)) fclean
	rm -f $(PUSHSWAP)
	rm -f $(CHECKER)

re: 
	make fclean
	make all

test: all bonus
	seq 500 | sort -R | xargs ./$(PUSHSWAP)

.PHONY : all clean fclean re bonus test
