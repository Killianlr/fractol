# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 17:26:57 by kle-rest          #+#    #+#              #
#    Updated: 2023/05/23 15:16:53 by kle-rest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft.a

LIBFT_DIR = libft

LIB = $(addprefix $(LIBFT_DIR)/, $(LIBFT))

FT_PRINTF = ft_printf.a

FT_PRINTF_DIR = ft_printf

FT_PRINT = $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF))

SOURCES = main.c \
		mandelbrot.c \
		utiles.c \
		parsing.c \
		zoom_1.c \
		zoom_2.c \
		julia.c \
		ft_atoi_f.c \
		animation.c \
		event.c \

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
		make -C ft_printf
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) minilibx-linux/libmlx.a $(OPENGL) $(LIB) $(FT_PRINT)

$(TEST): $(OBJTEST)
		make -C libft
		$(CC) $(CFLAGS) -o test $(OBJTEST) minilibx-linux/libmlx.a $(OPENGL) $(LIB)

all: $(NAME) 

clean: 
				rm -f $(OBJECTS)
				make clean -C libft
				make clean -C ft_printf

fclean: clean
				rm -f $(NAME)
				make fclean -C libft
				make fclean -C ft_printf

test:  $(OBJTEST)
		make -C libft
	$(CC) $(CFLAGS) -o test $(OBJTEST) minilibx-linux/libmlx.a $(OPENGL) $(LIB)

re: clean all

