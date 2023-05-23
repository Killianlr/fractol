/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:01:34 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/23 15:01:50 by kle-rest         ###   ########.fr       */
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