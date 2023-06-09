/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:40:05 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/24 21:32:20 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>

int	set_julia_shape(t_params *pa, char *cr, char *ci)
{
	if (!cr || !ci)
	{
		pa->c = 2;
		return (0);
	}
	pa->cr = ft_atoi_f(cr);
	pa->ci = ft_atoi_f(ci);
	pa->c = 1;
	return (0);
}

void	set_params_julia(t_params *pa)
{
	pa->algo->x1 = pa->xc - pa->aspect / pa->zoom;
	pa->algo->x2 = pa->xc + pa->aspect / pa->zoom;
	pa->algo->y1 = pa->yc - 1 / pa->zoom;
	pa->algo->y2 = pa->yc + 1 / pa->zoom;
	pa->algo->image_x = pa->rx;
	pa->algo->image_y = pa->ry;
	pa->algo->zoom_x = pa->algo->image_x / (pa->algo->x2 - pa->algo->x1);
	pa->algo->zoom_y = pa->algo->image_y / (pa->algo->y2 - pa->algo->y1);
	pa->algo->i_max = 200;
}

int	algo_julia(t_params *pa, int x, int y, int i)
{
	double	tmp;
	double	z_r;
	double	z_i;

	tmp = 0;
	z_r = (x / pa->algo->zoom_x) + pa->algo->x1;
	z_i = (y / pa->algo->zoom_y) + pa->algo->y1;
	while (z_r * z_r + z_i * z_i < 4 && i < pa->algo->i_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + pa->cr;
		z_i = 2 * z_i * tmp + pa->ci;
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
	while (y < pa->ry)
	{
		y++;
		x = 0;
		while (x < pa->rx)
		{
			x++;
			i = algo_julia(pa, x, y, 0);
			if (i == pa->algo->i_max)
				draw(pa, x, y, 0);
			else
				draw(pa, x, y, i);
		}
	}
	mlx_put_image_to_window(pa->mlx_ptr, pa->win_ptr, pa->data->img, -1, 0);
	mlx_destroy_image(pa->mlx_ptr, pa->data->img);
}
