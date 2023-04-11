/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:26:20 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/11 11:37:07 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct mdlbt
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom_x;
	double	zoom_y;
	int	i_max;
	double	image_x;
	double	image_y;
	double	x;
	double	y;
}t_a;

int	mandelbrot(void *mlx_ptr, void *win_ptr);

#endif