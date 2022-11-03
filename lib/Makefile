# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:29:59 by yonshin           #+#    #+#              #
#    Updated: 2022/11/04 02:18:56 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARFLAGS = rc
NAME = liball.a
CFLAGS = -Wall -Wextra -Werror
LIBFT = \
	./libft/ft_atoi.o \
	./libft/ft_bzero.o \
	./libft/ft_calloc.o \
	./libft/ft_isalnum.o \
	./libft/ft_isalpha.o \
	./libft/ft_isascii.o \
	./libft/ft_isdigit.o \
	./libft/ft_isprint.o \
	./libft/ft_itoa.o \
	./libft/ft_lstadd_back.o \
	./libft/ft_lstadd_front.o \
	./libft/ft_lstclear.o \
	./libft/ft_lstdelone.o \
	./libft/ft_lstiter.o \
	./libft/ft_lstlast.o \
	./libft/ft_lstmap.o \
	./libft/ft_lstnew.o \
	./libft/ft_lstsize.o \
	./libft/ft_memchr.o \
	./libft/ft_memcmp.o \
	./libft/ft_memcpy.o \
	./libft/ft_memmove.o \
	./libft/ft_memset.o \
	./libft/ft_putchar_fd.o \
	./libft/ft_putendl_fd.o \
	./libft/ft_putnbr_fd.o \
	./libft/ft_putstr_fd.o \
	./libft/ft_split.o \
	./libft/ft_strchr.o \
	./libft/ft_strdup.o \
	./libft/ft_striteri.o \
	./libft/ft_strjoin.o \
	./libft/ft_strlcat.o \
	./libft/ft_strlcpy.o \
	./libft/ft_strlen.o \
	./libft/ft_strlower.o \
	./libft/ft_strmapi.o \
	./libft/ft_strncmp.o \
	./libft/ft_strnstr.o \
	./libft/ft_strrchr.o \
	./libft/ft_strtrim.o \
	./libft/ft_strupper.o \
	./libft/ft_substr.o \
	./libft/ft_tolower.o \
	./libft/ft_toupper.o \

GNL = \
	./get_next_line/get_next_line_utils.o \
	./get_next_line/get_next_line.o \

EXIT = \
	./exit/error.o \
	./exit/lstnew_guard.o \
	./exit/malloc_guard.o \

ADVLST = \
	./advlst/lst_reduce.o \
	./advlst/lstb_add.o \
	./advlst/lstb_clear.o \
	./advlst/lstb_init.o \

HEADER = \
	-I./libft/ \
	-I./get_next_line/ \
	-I./advlst/ \
	-I./error/ \

OBJECTS = $(LIBFT) $(GNL) $(EXIT) $(ADVLST)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(HEADER) -c $*.c

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re