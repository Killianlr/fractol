/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:47:07 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/13 15:55:47 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	set_params_mdblt(t_params *pa, t_a *mdblt)
// {
// 	mdblt->x1 = -2.1;
// 	mdblt->x2 = 0.6;
// 	mdblt->y1 = -1.2;
// 	mdblt->y2 = 1.2;
// 	mdblt->image_x = pa->resx;
// 	mdblt->image_y = pa->resy;
// 	mdblt->zoom_x = mdblt->image_x/(mdblt->x2 - mdblt->x1);
// 	mdblt->zoom_y = mdblt->image_y/(mdblt->y2 - mdblt->y1);
// 	mdblt->i_max = 50;
// 	mdblt->x = 0;
// 	mdblt->y = 0;
// }

// int	mandelbrot(t_params *pa)
// {
// 	t_a	*mdblt;
// 	double tmp;

// 	mdblt = (t_a *)malloc(sizeof(t_a));
// 	tmp = 0;
// 	set_params_mdblt(pa, mdblt);
// 	while (mdblt->x < mdblt->image_x)
// 	{
// 		mdblt->y = 0;
// 		mdblt->x++;
// 		while (mdblt->y < mdblt->image_y)
// 		{
// 			mdblt->y++;
// 			double c_r = (mdblt->x / mdblt->zoom_x) + mdblt->x1;
// 			double c_i = (mdblt->y / mdblt->zoom_y) + mdblt->y1;
// 			double z_r = 0;
// 			double z_i = 0;
// 			int i = 0;
// 			while (z_r*z_r + z_i*z_i < 4 && i < mdblt->i_max)
// 			{
// 				tmp = z_r;
// 				z_r = z_r*z_r - z_i*z_i + c_r;
// 				z_i = 2*z_i*tmp + c_i;
// 				i = i + 1;
// 			}
// 			if (i == mdblt->i_max)
// 			{	
// 				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, mdblt->x, mdblt->y, 65535);
// 			}
// 			else
// 				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, mdblt->x, mdblt->y, 0);
// 		}
// 	}
// 	return (0);	
// }



// -----------------------------------------------------------------------------------------------------

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
	int	i;
	int	xzero;
	int	yzero;
	int	e;

	mdblt = (t_a *)malloc(sizeof(t_a));
	x = 0;
	xzero = 0;
	e = 0;
	set_params_mdblt(pa, mdblt);
	while (x < mdblt->image_x)
	{
		y = 0;
		yzero = 0;
		x++;
		if (e == 1)
			xzero++;
		while (y < mdblt->image_y)
		{
			y++;
			i = 0;
			i = algo_mandelbrot(mdblt, x, y, i);
			if (e == 1)
				yzero++;
			if (x > pa->x1 && y > pa->y1)
				e = 1;
			if (e == 1 && i == mdblt->i_max)
			{	
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, "pixel x", "pixel y", 65535);
			}
			else
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, "pixel x", "pixel y", 0);
		}
	}
	return (0);	
}