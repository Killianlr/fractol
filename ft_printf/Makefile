NAME = libftprintf.a

SOURCES = ft_printf_c.c \
	ft_printf_s.c \
	ft_printf_p.c \
	ft_printf_d.c \
	ft_printf_i.c \
	ft_printf_u.c \
	ft_printf_x.c \
	ft_printf_X.c \
	ft_printf.c \
	ft_strlen_p.c \
	ft_putnbr_base.c \
	ft_putnbr_base_p.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME) : $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re