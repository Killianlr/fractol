/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:20:23 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/14 17:51:23 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_params_mdblt(t_params *pa, t_a *mdblt)
{
	mdblt->x1 = -2.1;
	mdblt->x2 = 0.6;
	mdblt->y1 = -1.2;
	mdblt->y2 = 1.2;
	mdblt->image_x = pa->resx;
	mdblt->image_y = pa->resy;
	mdblt->zoom_x = mdblt->image_x/(mdblt->x2 - mdblt->x1);
	mdblt->zoom_y = mdblt->image_y/(mdblt->y2 - mdblt->y1);
	mdblt->i_max = 50;
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
	int	a;
	int	b;
	int	i;

	mdblt = (t_a *)malloc(sizeof(t_a));
	x = pa->x;
	a = 0;
	set_params_mdblt(pa, mdblt);
	printf("pa->x = %d pa->y = %d\n", pa->x, pa->y);
	printf("pa->resx = %d pa->resy = %d\n", pa->resx, pa->resy);
	// printf("image_x = %f image_y = %f\n", mdblt->image_x, mdblt->image_y);
	while (x < mdblt->image_x)
	{
		y = pa->y;
		b = 0;
		x++;
		a++;
		while (y < mdblt->image_y)
		{
			y++;
			b++;
			i = 0;
			i = algo_mandelbrot(mdblt, a, b, i);
			if (x >= 0 && y >= 0 && i == mdblt->i_max)
			{	
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 65535);
			}
			else
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 0);
		}
	}
	printf("x = %d, y = %d\n", x, y);
	printf("a = %d, b = %d\n", a, b);
	return (0);	
}

void	zoom(t_params *pa)
{
	pa->x = pa->x - 50;
	pa->y = pa->y - 50;
	pa->resx = pa->resx + 100;
	pa->resy = pa->resy + 100;
	mandelbrot(pa);
}
void	dezoom(t_params *pa)
{
	pa->x = pa->x + 50;
	pa->y = pa->y + 50;
	pa->resx = pa->resx - 100;
	pa->resy = pa->resy - 100;
	reset_backgrown(pa);
	mandelbrot(pa);
}