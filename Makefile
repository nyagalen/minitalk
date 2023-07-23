# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svydrina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 19:44:44 by svydrina          #+#    #+#              #
#    Updated: 2023/07/21 18:54:38 by svydrina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c client.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: server client libft

bonus: server client libft

server: server.o libft
	cc -o $@ $< -Llibft -lft

client: client.o libft
	cc -o $@ $< -Llibft -lft

%.o: %.c
	cc -c $(CFLAGS) $?

libft: 
	make -C libft

clean: 
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus clean fclean re libft
