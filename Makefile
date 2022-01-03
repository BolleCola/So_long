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

PNTC = main.c main_utilitis.c map.c map_two.c map_utils.c get_line_map.c get_line_utils.c exit.c chest.c perso.c

PNTO = $(PNTC:.c=.o)

all : $(NAME)

$(NAME) : $(PNTC)
	@$(MAKE) -C ./mlx
	@cp ./mlx/libmlx.a $(NAME)
	@$(CC) $(CFLAG) -c $(PNTC)
	@ar $(ARFLAGS) $(NAME) $(PNTO)
	@$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(NAME)

clean :
	@$(MAKE) -C ./mlx clean
	@/bin/$(RM) $(PNTO)

fclean : 
	@$(MAKE) -C ./mlx clean
	@/bin/$(RM) $(PNTO) $(NAME) ./a.out

make bonus :
	@make
	@$(MAKE) -C ./Bonus
	@cp ./Bonus/bonus.a bonus.a
	@$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(NAME)

clean bonus :
	@$(MAKE) -C ./mlx clean
	@./Bonus make clean

fclean bonus :
	@$(MAKE) -C ./mlx clean
	@./Bonus make fclean

re : fclean all

.PHONY : all clean fclean re valgrind