# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makfile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 15:21:58 by aeddaqqa          #+#    #+#              #
#    Updated: 2019/12/17 15:17:41 by aeddaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	  dda_algo.c\
	  tools1.c\
	  mouse_hook.c\
	  raycasting.c

NAME = wolf3d

CC = gcc


mlx1 = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(mlx1) $^ -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all
