# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 17:06:28 by yonshin           #+#    #+#              #
#    Updated: 2022/11/02 14:46:18 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
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
TARGET_OBJS = $(OBJS) push_swap.o
CHECKER_OBJS = $(OBJS) checker.o
LIB = ./libft/libft.a \
	./lib/

all: $(NAME)

$(NAME): $(TARGET_OBJS) $(LIB)
	cc $(CFLAGS) $(TARGET_OBJS) $(LIB) -I$(dir $(LIB)) $(OUTPUT_OPTION)

$(LIB):
	make -C $(@D)

%.o: %.c
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) -I$(dir $(LIB)) -c $*.c

clean:
	rm -f $(TARGET_OBJS)
	rm -f $(CHECKER_OBJS)

fclean: clean
	make -C $(dir $(LIB)) fclean
	rm -f $(NAME)
	rm -f $(CHECKER)

re: 
	make fclean
	make all

bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJS) $(LIB)
	cc -Wall -Wextra -Werror $(CHECKER_OBJS) $(LIB) -o $(CHECKER)

test: all bonus
	seq 500 | sort -R | xargs ./$(NAME)

.PHONY : all clean fclean re bonus test
