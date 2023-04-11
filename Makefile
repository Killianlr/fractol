# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 17:26:57 by kle-rest          #+#    #+#              #
#    Updated: 2023/04/11 11:44:37 by kle-rest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SOURCES = main.c \
		mandelbrot.c \

OBJECTS = $(SOURCES:.c=.o)

OPENGL = -lXext -lX11 -lbsd -lm
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux 

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) minilibx-linux/libmlx.a $(OPENGL)

all: $(NAME)

clean: 
				rm -f $(OBJECTS)

fclean: clean
				rm -f $(NAME)

re: clean all

