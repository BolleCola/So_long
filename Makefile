# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaquier <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 09:39:45 by tpaquier          #+#    #+#              #
#    Updated: 2021/10/26 09:39:48 by tpaquier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game.a

CFLAGS = -Wall -Werror -Wextra

ARFLAGS = -crs

CC = gcc

RM = rm -f

PNTC = test.c

PNTO = $(PNTC:.c=.o)

all : $(NAME)

$(NAME) : $(PNTC)
	@$(MAKE) -C ./mlx
	@cp ./mlx/libmlx.a $(NAME)
	@$(CC) $(CFLAG) -c $(PNTC)
	@ar $(ARFLAGS) $(NAME) $(PNTO)

clean :
	@$(MAKE) -C ./mlx clean
	@/bin/$(RM) $(PNTO)

fclean : 
	@$(MAKE) -C ./mlx clean
	@/bin/$(RM) $(PNTO) $(NAME)

re : fclean all

.PHONY : all clean fclean re