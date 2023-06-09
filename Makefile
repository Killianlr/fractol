# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 17:26:57 by kle-rest          #+#    #+#              #
#    Updated: 2023/05/25 19:03:36 by kle-rest         ###   ########.fr        #
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
		supermand.c \
		display.c \

OBJECTS = $(SOURCES:.c=.o)

OPENGL = -lXext -lX11 -lbsd -lm
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux 

$(NAME): $(OBJECTS)
		make -C libft
		make -C ft_printf
		make -C minilibx-linux
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) minilibx-linux/libmlx.a $(OPENGL) $(LIB) $(FT_PRINT)


all: $(NAME) 

clean: 
				rm -f $(OBJECTS)
				make clean -C libft
				make clean -C ft_printf

fclean: clean
				rm -f $(NAME)
				make fclean -C libft
				make fclean -C ft_printf

re: clean all

mlx: 
	git clone git@github.com:42Paris/minilibx-linux.git

.PHONY: all clean fclean re mlx

