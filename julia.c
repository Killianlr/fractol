/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:40:05 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/17 14:47:38 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>

void	julia(t_params *pa)
{
	int	x;
	int	y;
	int	n;
	int	i;
	double	complex z;
	double	complex	z0;
	double	complex c;
	
	y = 0;
	i = 1000;
	c = pa->cr + pa->ci * I;
	while (y < pa->resy)
	{
		y++;
		x = 0;
		while (x < pa->resx)
		{
			x++;
			z = ((x - pa->resx / 2) / pa->zoom) + ((y - pa->resy / 2) / pa->zoom) * I;
			z0 = z;
			n = 0;
			while (n < i)
			{
				n++;
				z = z * z + c;
				if (creal(z) * creal(z) + cimag(z) * cimag(z) > 4.0)
					break;
			}
			mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 255 * n / i);
		}
	}
}