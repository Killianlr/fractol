/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:47:07 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/12 15:52:39 by kle-rest         ###   ########.fr       */
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
	mdblt->x = pa->x;
	mdblt->y = pa->y;
}

int	mandelbrot(t_params *pa)
{
	t_a	*mdblt;
	double tmp;

	printf("test\n");
	mdblt = (t_a *)malloc(sizeof(t_a));
	tmp = 0;
	set_params_mdblt(pa, mdblt);
	printf("x = %f, y = %f\n", mdblt->x, mdblt->y);
	while (mdblt->x < mdblt->image_x)
	{
		mdblt->y = pa->y;
		mdblt->x++;
		while (mdblt->y < mdblt->image_y)
		{
			mdblt->y++;
			double c_r = (mdblt->x / mdblt->zoom_x) + mdblt->x1;
			double c_i = (mdblt->y / mdblt->zoom_y) + mdblt->y1;
			double z_r = 0;
			double z_i = 0;
			int i = 0;
			while (z_r*z_r + z_i*z_i < 4 && i < mdblt->i_max)
			{
				tmp = z_r;
				z_r = z_r*z_r - z_i*z_i + c_r;
				z_i = 2*z_i*tmp + c_i;
				i = i + 1;
			}
			if (i == mdblt->i_max)
			{	
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, mdblt->x, mdblt->y, 65535);
			}
			else
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, mdblt->x, mdblt->y, 0);
		}
	}
	return (0);	
}
