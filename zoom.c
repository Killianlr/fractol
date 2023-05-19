/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavian <flavian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:20:23 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/19 17:07:52 by flavian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom(t_params *pa, int x, int y)
{
	pa->zoom *= 1.2;
	pa->xc -= (pa->resx/2 - x) * 0.9 / pa->resx  / pa->zoom;
	pa->yc -= (pa->resy/2 - y) * 0.9 / pa->resy  / pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
}

void	zoom(t_params *pa)
{
	pa->zoom *= 1.2;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
}
void	dezoom(t_params *pa)
{
	pa->zoom /= 1.2;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
}

void	left(t_params *pa)
{
	pa->xc -= 0.2/pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
}

void	right(t_params *pa)
{
	pa->xc += 0.2/pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
}

void	up(t_params *pa)
{
	pa->yc -= 0.2/pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
}

void	down(t_params *pa)
{
	pa->yc += 0.2/pa->zoom;
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
		julia(pa);
}