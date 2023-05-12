/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:29:41 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/12 16:54:33 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	endprog(t_params *pa)
{
	mlx_destroy_image(pa->mlx_ptr, pa->data->img);
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
	int g;
	int	b;

	g = 255 * x / pa->resx;
	b = 255 * y / pa->resy;
	if (e == 1)
		my_mlx_pixel_put(pa, x, y, create_trgb(255, 212, g, b));
	else if (e == 2)
		my_mlx_pixel_put(pa, x, y, 0);
}