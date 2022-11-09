# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 17:06:28 by yonshin           #+#    #+#              #
#    Updated: 2022/11/09 15:47:23 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP = push_swap
CHECKER = checker
CFLAGS = -Wall -Wextra -Werror
PUSHSWAP_OBJS = \
	push_swap.o \
	instruction_push.o \
	instruction_swap.o \
	instruction_rotate.o \
	instruction_rrotate.o \
	is_sorted.o \
	dequeue.o \
	create_dequeue.o \
	create_solution.o \
	parse_integer.o \
	solve.o \
	solve_sandglass.o \
	solve_greedy.o \
	solve_hardcode2.o \
	solve_hardcode3.o \
	solve_hardcode4.o \
	solve_hardcode5.o \
	data_utils1.o \
	data_utils2.o \
	copy_dequeue.o \
	ranking.o \
	destroy_solution.o \
	destroy_dequeue.o \

CHECKER_OBJS = \
	checker_bonus.o \
	instruction_push_bonus.o \
	instruction_swap_bonus.o \
	instruction_rotate_bonus.o \
	instruction_rrotate_bonus.o \
	is_sorted_bonus.o \
	dequeue_bonus.o \
	create_dequeue_bonus.o \
	create_solution_bonus.o \
	parse_integer_bonus.o \
	
LIB = ./lib/liball.a

INCLUDE = \
	-I./lib/libft/ \
	-I./lib/get_next_line/ \
	-I./lib/advlst/ \
	-I./lib/exit/ \
	-I./lib/math/ \

all: $(PUSHSWAP)

bonus: $(CHECKER)

$(PUSHSWAP): $(PUSHSWAP_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(PUSHSWAP_OBJS) $(LIB) $(DEBUG) $(OUTPUT_OPTION)

$(CHECKER): $(CHECKER_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIB) $(DEBUG) $(OUTPUT_OPTION)

$(LIB):
	make -C $(@D)

%.o: %.c
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(INCLUDE) $(DEBUG) -c $*.c

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
	make DEBUG='-g3 -fsanitize=address' re
	make DEBUG='-g3 -fsanitize=address' $(CHECKER)

test: all bonus
	@echo $(shell ARG=$$(seq $(SIZE) | sort -R | tr "\n" " "); ./push_swap $$ARG | wc -l; ./push_swap $$ARG | ./checker $$ARG; echo $$ARG;)

benchmark: all bonus
	@rm -f testfile
	@touch testfile
	@for i in $(shell seq $(REPEAT)); do \
		make test >> testfile; \
	done
	@echo $$(awk '$$2=="KO" {ko+=1} END {if (ko > 0) printf("----- KO: %d -----"), ko}' testfile)
	@echo $$(awk '{total += $$1} END {printf("avg: %.2f"), total/NR}' testfile)
	@echo $$(awk '{if (min=="") min=$$1} {if (min > $$1) min=$$1} END {printf("min: %d"), min}' testfile)
	@echo $$(awk '{if (max=="") max=$$1} {if (max < $$1) max=$$1} END {printf("max: %d"), max}' testfile)
	@echo $$(awk '$$2=="KO" {ko+=1} END {if (ko > 0) printf("----- KO: %d -----"), ko}' testfile)

.PHONY : all clean fclean re bonus test debug benchmark
