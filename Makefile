# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:48:48 by eburnet           #+#    #+#              #
#    Updated: 2023/11/13 14:39:57 by eburnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_put_count.c
OBJS = $(SRCS:.c=.o)
HEADERS = libftprintf.h

.c.o : 
	gcc $(CFLAGS) $(HEADERS) -c $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all : 
	make -C include r./libft/Makefile
	$(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all