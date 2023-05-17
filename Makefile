# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 17:26:57 by kle-rest          #+#    #+#              #
#    Updated: 2023/05/17 13:54:18 by kle-rest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft.a

LIBFT_DIR = libft

LIB = $(addprefix $(LIBFT_DIR)/, $(LIBFT))

SOURCES = main.c \
		mandelbrot.c \
		utiles.c \
		parsing.c \
		zoom.c \
		julia.c \

TESTSRC = test.c \
		utiles.c \
		zoom.c \
		mandelbrot.c \

OBJECTS = $(SOURCES:.c=.o)

OBJTEST = $(TESTSRC:.c=.o)

OPENGL = -lXext -lX11 -lbsd -lm
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux 

$(NAME): $(OBJECTS)
		make -C libft
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) minilibx-linux/libmlx.a $(OPENGL) $(LIB)

$(TEST): $(OBJTEST)
		make -C libft
		$(CC) $(CFLAGS) -o test $(OBJTEST) minilibx-linux/libmlx.a $(OPENGL) $(LIB)

all: $(NAME) 

clean: 
				rm -f $(OBJECTS)
				make clean -C libft

fclean: clean
				rm -f $(NAME)
				make fclean -C libft

test:  $(OBJTEST)
		make -C libft
	$(CC) $(CFLAGS) -o test $(OBJTEST) minilibx-linux/libmlx.a $(OPENGL) $(LIB)

re: clean all

