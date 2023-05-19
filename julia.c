/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavian <flavian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:40:05 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/19 17:12:50 by flavian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>

void	set_params_julia(t_params *pa)
{
	pa->mdblt->x1 = pa->xc - pa->aspect/pa->zoom;
	pa->mdblt->x2 = pa->xc + pa->aspect/pa->zoom;
	pa->mdblt->y1 = pa->yc - 1/pa->zoom;
	pa->mdblt->y2 = pa->yc + 1/pa->zoom;
	pa->mdblt->image_x = pa->resx;
	pa->mdblt->image_y = pa->resy;
	pa->mdblt->zoom_x = pa->mdblt->image_x/(pa->mdblt->x2 - pa->mdblt->x1);
	pa->mdblt->zoom_y = pa->mdblt->image_y/(pa->mdblt->y2 - pa->mdblt->y1);
	pa->mdblt->i_max = 200;
}

int	algo_julia(t_params *pa, int x, int y, int i)
{
	double	tmp;
	double	z_r;
	double	z_i;

	tmp = 0;
	z_r = (x / pa->mdblt->zoom_x) + pa->mdblt->x1;
	z_i = (y / pa->mdblt->zoom_y) + pa->mdblt->y1;
	while (z_r*z_r + z_i*z_i < 4 && i < pa->mdblt->i_max)
	{
		tmp = z_r;
		z_r = z_r*z_r - z_i*z_i + pa->cr;
		z_i = 2*z_i*tmp + pa->ci;
		i++;
	}
	return (i);
}

void	julia(t_params *pa)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	create_image(pa);
	set_params_julia(pa);
	while (y < pa->resy)
	{
		y++;
		x = 0;
		while (x < pa->resx)
		{
			x++;
			i = algo_julia(pa, x, y, 0);
			if (i == pa->mdblt->i_max)
				draw(pa, x, y, 0);
			else
				draw(pa, x, y, i);
		}
	}
	mlx_put_image_to_window(pa->mlx_ptr, pa->win_ptr, pa->data->img, 0, 0);
	mlx_destroy_image(pa->mlx_ptr, pa->data->img);
}