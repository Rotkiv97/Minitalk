# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 12:09:24 by vguidoni          #+#    #+#              #
#    Updated: 2023/01/23 12:11:12 by vguidoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER = server

CLIENT = client

CC        = gcc

PRINTF = printf

FLAGS = -Wall -Wextra -Werror

all:
	@make -s -C $(PRINTF)
	@gcc $(FLAGS) server.c printf/libftprintf.a -o $(SERVER)
	@gcc $(FLAGS) client.c printf/libftprintf.a -o $(CLIENT)
clean:
			@make clean -s -C $(PRINTF)

fclean:		clean
			@make fclean -s -C $(PRINTF)
			@rm -f $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re
