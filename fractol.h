/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:26:20 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/12 15:28:47 by kle-rest         ###   ########.fr       */
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

typedef struct params_win
{
	int		type;
	void	*mlx_ptr;
	void	*win_ptr;
	double		x;
	double		resx;
	double		y;
	double		resy;
}t_params;


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
	double	x;
	double	y;
}t_a;

int		mandelbrot(t_params *pa);
void	endprog(void *mlx_ptr, void *win_ptr);
int		type_of_fractal(t_params *pa, char *type);
int		set_resolution(t_params *pa, char *res);
int		check_resolution(t_params *pa, char *res);
void	display_params(void);

#endif