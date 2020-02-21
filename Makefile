# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/19 10:58:36 by yoouali           #+#    #+#              #
#    Updated: 2020/02/19 09:13:09 by yoouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d

CC = gcc

SRC = CODE/SRC/main.c\
	  CODE/SRC/zero.c\
	  CODE/SRC/install.c\
	  CODE/SRC/destroy.c\
	  CODE/SRC/object.c\
	  CODE/SRC/loading.c\
	  CODE/SRC/map.c\
	  CODE/SRC/map2.c\
	  CODE/SRC/boy.c\
	  CODE/SRC/tex.c\
	  CODE/SRC/gen.c\
	  CODE/SRC/sta.c\
	  CODE/SRC/mmap.c\
	  CODE/SRC/mus.c\
	  CODE/SRC/player.c\
	  CODE/SRC/start.c\
	  CODE/SRC/gen_map.c\
	  CODE/SRC/ray.c\
	  CODE/SRC/raycasting.c\
	  CODE/SRC/raycasting1.c\
	  CODE/SRC/raycasting2.c\
	  CODE/SRC/event.c\
	  CODE/SRC/update.c\
	  CODE/SRC/wop.c\
	  CODE/SRC/box.c\
	  CODE/SRC/mos.c\
	  CODE/SRC/minimap.c\
	  CODE/SRC/check.c\
	  CODE/SRC/ray1.c

OBJ = $(SRC:.c=.o)

INC = -I SDL/SDL2.framework/Headers -I SDL/SDL2_mixer.framework/Headers -I MLX/

LIB = -rpath @loader_path/SDL MLX/libmlx.a -lz

FRM = -framework SDL2 -F ./SDL/ -framework SDL2_mixer -F ./SDL -framework OpenGl -framework Appkit

CFLAGS = -Wall -Werror -Wextra $(INC)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C mlx
	$(CC) $(CFLAGS) $(LIB) $(FRM) $(OBJ) -o $(NAME)

clean :
	make -C mlx clean
	rm -f $(OBJ)

fclean : clean
	make -C mlx fclean
	rm -f $(NAME)

re : fclean all
