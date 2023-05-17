/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:26:20 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/17 15:00:29 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"


typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}t_data;

typedef struct mdlbt
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom_x;
	double	zoom_y;
	int		i_max;
	double	image_x;
	double	image_y;
}t_a;

typedef struct params_win
{
	int		type;
	void	*mlx_ptr;
	void	*win_ptr;
	int		resx;
	int		resy;
	double		fract_x;
	double		fract_y;
	double		xc;
	double		yc;
	double		zoom;
	double		aspect;
	double		ci;
	double		cr;
	t_data		*data;
	t_a			*mdblt;
}t_params;


int		mandelbrot(t_params *pa);
int		endprog(t_params *pa);
int		type_of_fractal(t_params *pa, char *type);
int		set_resolution(t_params *pa, char *res);
int		check_resolution(t_params *pa, char *res);
void	display_params(void);
void	zoom(t_params *pa);
void	dezoom(t_params *pa);
void	left(t_params *pa);
void	right(t_params *pa);
void	up(t_params *pa);
void	down(t_params *pa);
void	mouse_zoom(t_params *pa, int x, int y);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_params *pa, int x, int y, int color);
void	create_image(t_params *pa);
void	draw(t_params *pa, int x, int y, int e);
void	julia(t_params *pa);
int		deal_key_j(int key, t_params *pa);
void	setup_julia(t_params *pa);

#endif