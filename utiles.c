/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:29:41 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/23 14:55:24 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	endprog(t_params *pa)
{
	mlx_clear_window(pa->mlx_ptr, pa->win_ptr);
	mlx_destroy_window(pa->mlx_ptr, pa->win_ptr);
	mlx_destroy_display(pa->mlx_ptr);
	free(pa->mlx_ptr);
	free(pa->data);
	free(pa->algo);
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

void	color(t_params *pa, int i)
{
	if (i == 1)
		pa->data->r += 0.1;
	if (i == 2)
		pa->data->g += 0.1;
	if (i == 3)
		pa->data->b += 0.1;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
}

void	draw(t_params *pa, int x, int y, int e)
{
	int	t;

	t = 50;
	my_mlx_pixel_put(pa, x, y, create_trgb(t, e*pa->data->r, 
						e*pa->data->g, e*pa->data->b));
}