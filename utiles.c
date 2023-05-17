/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:29:41 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/17 14:45:32 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	endprog(t_params *pa)
{
	mlx_clear_window(pa->mlx_ptr, pa->win_ptr);
	mlx_destroy_window(pa->mlx_ptr, pa->win_ptr);
	free(pa->data);
	free(pa->mdblt);
	free(pa);
	exit(0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_params *pa, int x, int y, int color)
{
	char	*dest;

	dest = pa->data->addr + (y * pa->data->line_length + x * (pa->data->bits_per_pixel / 8));
	*(unsigned int *) dest = color;
}

void	create_image(t_params *pa)
{
	pa->data->img = mlx_new_image(pa->mlx_ptr, pa->resx, pa->resy);
	pa->data->addr = NULL;
	if (pa->data->img)
		pa->data->addr = mlx_get_data_addr(pa->data->img, &pa->data->bits_per_pixel, 
			&pa->data->line_length, &pa->data->endian);
}

void	draw(t_params *pa, int x, int y, int e)
{
	int	t;
	int	r;
	int	g;
	int	b;
	double	midx;
	double	midy;
	double	range;

	midx = pa->resx /2;
	midy = pa->resy /2;
	if (midx < 0)
		midx *= -1;
	if (midy < 0)
		midy *=-1;
	range = sqrt(pow(x - midx, 2) + pow(y - midy, 2));
	t = 255;
	if (e == 1)
	{
		r = 255 - ((range / sqrt(pow(midx, 2) + pow(midy, 2))) * 255);
		g = 255 - ((range / sqrt(pow(midx, 2) + pow(midy, 2))) * 255);
		b = 255 - ((range / sqrt(pow(midx, 2) + pow(midy, 2))) * 255);
		my_mlx_pixel_put(pa, x, y, create_trgb(t, r, g, b));
	}
	if (e == 2)
	{
		r = 255 - ((range / sqrt(pow(midx, 2) + pow(midy, 2))) * 255);
		g = 255 - ((range / sqrt(pow(midx, 2) + pow(midy, 2))) * 255);
		b = 255 - ((range / sqrt(pow(midx, 2) + pow(midy, 2))) * 255);
		my_mlx_pixel_put(pa, x, y, create_trgb(t, r, g, b));
	}
	if (e == 3)
	{
		my_mlx_pixel_put(pa, x, y, create_trgb(t, 0, 0, 0));
	}
}