/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:20:23 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/24 20:08:41 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	dezoom(t_params *pa)
{
	pa->zoom /= 1.2;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
	if (pa->type == 3)
		supermand(pa);
}

void	left(t_params *pa)
{
	pa->xc -= 0.2 / pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
	if (pa->type == 3)
		supermand(pa);
}

void	right(t_params *pa)
{
	pa->xc += 0.2 / pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
	if (pa->type == 3)
		supermand(pa);
}

void	up(t_params *pa)
{
	pa->yc -= 0.2 / pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
	if (pa->type == 3)
		supermand(pa);
}

void	down(t_params *pa)
{
	pa->yc += 0.2 / pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
	if (pa->type == 3)
		supermand(pa);
}
