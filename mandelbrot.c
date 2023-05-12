/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:47:07 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/12 16:57:18 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_params_mdblt(t_params *pa)
{
	pa->mdblt->x1 = pa->xc - pa->aspect/pa->zoom;
	pa->mdblt->x2 = pa->xc + pa->aspect/pa->zoom;
	pa->mdblt->y1 = pa->yc - 1/pa->zoom;
	pa->mdblt->y2 = pa->yc + 1/pa->zoom;
	pa->mdblt->image_x = pa->resx;
	pa->mdblt->image_y = pa->resy;
	pa->mdblt->zoom_x = pa->mdblt->image_x/(pa->mdblt->x2 - pa->mdblt->x1);
	pa->mdblt->zoom_y = pa->mdblt->image_y/(pa->mdblt->y2 - pa->mdblt->y1);
	pa->mdblt->i_max = 50;
}

int	algo_mandelbrot(t_params *pa, int x, int y, int i)
{
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	tmp = 0;
	c_r = (x / pa->mdblt->zoom_x) + pa->mdblt->x1;
	c_i = (y / pa->mdblt->zoom_y) + pa->mdblt->y1;
	z_r = 0;
	z_i = 0;
	while (z_r*z_r + z_i*z_i < 4 && i < pa->mdblt->i_max)
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
	int	x;
	int	y;
	int	i;

	x = 0;
	create_image(pa);
	set_params_mdblt(pa);
	while (x < pa->mdblt->image_x)
	{
		y = 0;
		x++;
		while (y < pa->mdblt->image_y)
		{
			y++;
			i = 0;
			i = algo_mandelbrot(pa, x, y, i);
			if (i == pa->mdblt->i_max)
				draw(pa, x, y, 1);
			else
				draw(pa, x, y, 2);
		}
	}
	// mlx_clear_window(pa->mlx_ptr, pa->win_ptr);
	mlx_put_image_to_window(pa->mlx_ptr, pa->win_ptr, pa->data->img, -1, 0);
	mlx_destroy_image(pa->mlx_ptr, pa->data->img);
	return (0);	
}