# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 17:06:28 by yonshin           #+#    #+#              #
#    Updated: 2022/11/04 17:23:47 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP = push_swap
CHECKER = checker
CFLAGS = -Wall -Wextra -Werror
OBJS = \
	dequeue.o \
	create_dequeue.o \
	destroy_dequeue.o \
	parse_integer.o \
	ranking.o \
	instruction_push.o \
	instruction_swap.o \
	instruction_rotate.o \
	instruction_rrotate.o \
	solve.o \
	solve_sandglass.o \
	solve_hardcode2.o \
	solve_hardcode3.o \
	solve_hardcode4.o \
	solve_hardcode5.o \
	create_solution.o \
	destroy_solution.o \
	is_sorted.o \
	
PUSHSWAP_OBJS = $(OBJS) push_swap.o
CHECKER_OBJS = $(OBJS) checker.o
LIB = ./lib/liball.a

INCLUDE = \
	-I./lib/libft/ \
	-I./lib/get_next_line/ \
	-I./lib/advlst/ \
	-I./lib/exit/ \

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
	make -C $(dir $(LIB)) clean
	rm -f $(PUSHSWAP_OBJS)
	rm -f $(CHECKER_OBJS)

fclean: clean
	make -C $(dir $(LIB)) fclean
	rm -f $(PUSHSWAP)
	rm -f $(CHECKER)

re: 
	make fclean
	make all

debug:
	make DEBUG='-g' re

test: all bonus
	@echo $(shell ARG=$$(seq $(SIZE) | sort -R | tr "\n" " "); ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG;)

.PHONY : all clean fclean re bonus test debug
