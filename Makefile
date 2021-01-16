# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/25 08:35:14 by abenouda          #+#    #+#              #
#    Updated: 2021/01/15 18:18:57 by abenouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SRC = 	*.c

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