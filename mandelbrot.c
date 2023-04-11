/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:47:07 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/11 11:42:49 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_params_mdblt(t_a *mdblt)
{
	mdblt->x1 = -2.1;
	mdblt->x2 = 0.6;
	mdblt->y1 = -1.2;
	mdblt->y2 = 1.2;
	mdblt->image_x = 800;
	mdblt->image_y = 600;
	mdblt->zoom_x = mdblt->image_x/(mdblt->x2 - mdblt->x1);
	mdblt->zoom_y = mdblt->image_y/(mdblt->y2 - mdblt->y1);
	mdblt->i_max = 50;
	mdblt->x = 0;
	mdblt->y = 0;
}

int	mandelbrot(void *mlx_ptr, void *win_ptr)
{
	t_a	*mdblt;
	double tmp;

	mdblt = (t_a *)malloc(sizeof(t_a));
	tmp = 0;
	set_params_mdblt(mdblt);
	while (mdblt->x < mdblt->image_x)
	{
		mdblt->y = 0;
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
				mlx_pixel_put(mlx_ptr, win_ptr, mdblt->x, mdblt->y, 65535);
			}
			else
				mlx_pixel_put(mlx_ptr, win_ptr, mdblt->x, mdblt->y, 16777215);
		}
	}
	return (0);	
}
