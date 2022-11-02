# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:29:59 by yonshin           #+#    #+#              #
#    Updated: 2022/11/02 14:29:48 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARFLAGS = rc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
OBJECTS = \
	ft_atoi.o \
	ft_bzero.o \
	ft_calloc.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_itoa.o \
	ft_lstadd_back.o \
	ft_lstadd_front.o \
	ft_lstclear.o \
	ft_lstdelone.o \
	ft_lstiter.o \
	ft_lstlast.o \
	ft_lstmap.o \
	ft_lstnew.o \
	ft_lstsize.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	ft_split.o \
	ft_strchr.o \
	ft_strdup.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlcpy.o \
	ft_strlen.o \
	ft_strlower.o \
	ft_strmapi.o \
	ft_strncmp.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_strtrim.o \
	ft_strupper.o \
	ft_substr.o \
	ft_tolower.o \
	ft_toupper.o \

$(NAME): $(OBJECTS)
	ar $(ARFLAGS) $@ $^

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
