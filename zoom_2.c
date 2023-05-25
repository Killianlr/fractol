/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:01:34 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/24 21:32:32 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom(t_params *pa, int x, int y)
{
	pa->zoom *= 1.2;
	pa->xc -= (pa->rx / 2 - x) * 0.9 / pa->rx / pa->zoom;
	pa->yc -= (pa->ry / 2 - y) * 0.9 / pa->ry / pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
	if (pa->type == 3)
		supermand(pa);
}

void	zoom(t_params *pa)
{
	pa->zoom *= 1.2;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
	if (pa->type == 3)
		supermand(pa);
}

void	draw(t_params *pa, int x, int y, int e)
{
	my_mlx_pixel_put(pa, x, y, create_trgb(255, e * pa->data->r,
			e * pa->data->g, e * pa->data->b));
}
