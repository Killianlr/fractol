/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:20:23 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/18 14:01:55 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_params_mdblt(t_params *pa, t_a *mdblt)
{
	mdblt->x1 = pa->x1;
	mdblt->x2 = pa->x2;
	mdblt->y1 = pa->y1;
	mdblt->y2 = pa->y2;
	mdblt->image_x = pa->resx;
	mdblt->image_y = pa->resy;
	mdblt->zoom_x = mdblt->image_x/(mdblt->x2 - mdblt->x1);
	mdblt->zoom_y = mdblt->image_y/(mdblt->y2 - mdblt->y1);
	mdblt->i_max = 100;
}

int	algo_mandelbrot(t_a *mdblt, int x, int y, int i)
{
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	tmp = 0;
	c_r = (x / mdblt->zoom_x) + mdblt->x1;
	c_i = (y / mdblt->zoom_y) + mdblt->y1;
	z_r = 0;
	z_i = 0;
	while (z_r*z_r + z_i*z_i < 4 && i < mdblt->i_max)
	{
		tmp = z_r;
		z_r = z_r*z_r - z_i*z_i + c_r;
		z_i = 2*z_i*tmp + c_i;
		i = i + 1;
	}
	return (i);
}

int	mandelbrot(t_params *pa)
{
	t_a	*mdblt;
	int	x;
	int	y;
	int	i;

	mdblt = (t_a *)malloc(sizeof(t_a));
	x = 0;
	set_params_mdblt(pa, mdblt);
	// printf("pa->resx = %d pa->resy = %d\n", pa->resx, pa->resy);
	printf("x1 = %f x2 = %f\n", mdblt->x1, mdblt->x2);
	printf("y1 = %f y2 = %f\n", mdblt->y1, mdblt->y2);
	while (x < mdblt->image_x)
	{
		y = 0;
		x++;
		while (y < mdblt->image_y)
		{
			y++;
			i = 0;
			i = algo_mandelbrot(mdblt, x, y, i);
			if (i == mdblt->i_max)
			{	
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 65535);
			}
			else
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 0);
		}
	}
	printf("x = %d, y = %d\n", x, y);
	return (0);	
}

void	zoom(t_params *pa)
{
	pa->x1 -= pa->x1 * 0.1;
	pa->x2 -= pa->x2 * 0.1;
	pa->y1 -= pa->y1 * 0.1;
	pa->y2 -= pa->y2 * 0.1;
	mandelbrot(pa);
}
void	dezoom(t_params *pa)
{
	pa->x1 += -0.12;
	pa->x2 += 0.09;
	pa->y1 += -0.12;
	pa->y2 += 0.09;
	mandelbrot(pa);
}

void	left(t_params *pa)
{
	pa->x1 -= 0.12;
	pa->x2 -= 0.12;
	mandelbrot(pa);
}

void	right(t_params *pa)
{
	pa->x1 += 0.12;
	pa->x2 += 0.12;
	mandelbrot(pa);
}

void	up(t_params *pa)
{
	pa->y1 -= 0.09;
	pa->y2 -= 0.09;
	mandelbrot(pa);
}

void	down(t_params *pa)
{
	pa->y1 += 0.09;
	pa->y2 += 0.09;
	mandelbrot(pa);
}