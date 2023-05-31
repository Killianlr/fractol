/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supermand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:35:52 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/24 20:22:17 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_params_supermand(t_params *pa)
{
	pa->algo->x1 = pa->xc - pa->aspect / pa->zoom;
	pa->algo->x2 = pa->xc + pa->aspect / pa->zoom;
	pa->algo->y1 = pa->yc - 1 / pa->zoom;
	pa->algo->y2 = pa->yc + 1 / pa->zoom;
	pa->algo->image_x = pa->rx;
	pa->algo->image_y = pa->ry;
	pa->algo->zoom_x = pa->algo->image_x / (pa->algo->x2 - pa->algo->x1);
	pa->algo->zoom_y = pa->algo->image_y / (pa->algo->y2 - pa->algo->y1);
	pa->algo->i_max = 100;
}

void	powcomp(double *add_r, double *add_i, int n)
{
	double	tmp;
	double	c;
	double	d;
	double	a;
	double	b;

	c = *add_r;
	d = *add_i;
	a = c;
	b = d;
	while (n > 1)
	{
		tmp = a;
		a = a * c - d * b;
		b = d * tmp + b * c;
		n--;
	}
	*add_r = a;
	*add_i = b;
}

int	algo_supermand(t_params *pa, int x, int y, int i)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	c_r = (x / pa->algo->zoom_x) + pa->algo->x1;
	c_i = (y / pa->algo->zoom_y) + pa->algo->y1;
	z_r = 0;
	z_i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < pa->algo->i_max)
	{
		powcomp(&z_r, &z_i, 5);
		z_r += c_r;
		z_i += c_i;
		i++;
	}
	return (i);
}

void	supermand(t_params *pa)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	create_image(pa);
	set_params_supermand(pa);
	i = 0;
	while (x < pa->algo->image_x)
	{
		y = 0;
		x++;
		while (y < pa->algo->image_y)
		{
			y++;
			i = algo_supermand(pa, x, y, 0);
			if (i == pa->algo->i_max)
				draw(pa, x, y, 0);
			else
				draw(pa, x, y, i);
		}
	}
	mlx_put_image_to_window(pa->mlx_ptr, pa->win_ptr, pa->data->img, -1, 0);
	mlx_destroy_image(pa->mlx_ptr, pa->data->img);
}
