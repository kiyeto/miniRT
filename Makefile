# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/25 08:35:14 by abenouda          #+#    #+#              #
#    Updated: 2021/01/17 12:58:23 by abenouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRC = 	bmp.c camera.c constructors.c ft_split.c get_next_line.c get_next_line_utils.c\
inter_shapes.c inter_shapes2.c intersect.c intersect_shadows.c keys.c main.c operators.c\
operators2.c  parse_params.c parse_shapes.c parsing.c raytracer.c tools.c tools2.c\
utils_parsing1.c utils_parsing2.c utils_parsing3.c 

OBJ = $(SRC:.c=.o)

MLX = -I minilibx -lmlx -framework OpenGL -framework AppKit

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	gcc $(SRC) $(MLX) $(FLAGS) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJ_BONUS)
	
fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
