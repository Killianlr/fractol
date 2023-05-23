/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:47:07 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/23 14:55:14 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_params_mdblt(t_params *pa)
{
	pa->algo->x1 = pa->xc - pa->aspect/pa->zoom;
	pa->algo->x2 = pa->xc + pa->aspect/pa->zoom;
	pa->algo->y1 = pa->yc - 1/pa->zoom;
	pa->algo->y2 = pa->yc + 1/pa->zoom;
	pa->algo->image_x = pa->resx;
	pa->algo->image_y = pa->resy;
	pa->algo->zoom_x = pa->algo->image_x/(pa->algo->x2 - pa->algo->x1);
	pa->algo->zoom_y = pa->algo->image_y/(pa->algo->y2 - pa->algo->y1);
	pa->algo->i_max = 200;
}



void powComp(double *add_r, double *add_i, int n, double c_r, double c_i)
{
	double tmp;
	double c = *add_r;
	double d = *add_i;
	double a = c;
	double b = d;
	while (n > 1)
	{
		tmp = a;
		a = a*c - d*b;
		b = d*tmp + b*c;
		n--;
	}
	*add_r = a;
	*add_i = b;
}

int	algo_mandelbrot(t_params *pa, int x, int y, int i)
{
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	tmp = 0;
	c_r = (x / pa->algo->zoom_x) + pa->algo->x1;
	c_i = (y / pa->algo->zoom_y) + pa->algo->y1;
	z_r = 0;
	z_i = 0;
	while (z_r*z_r + z_i*z_i < 4 && i < pa->algo->i_max)
	{
		powComp(&z_r, &z_i, 12, c_r, c_i);
		z_r += c_r;
		z_i += c_i;
		// tmp = z_r;
		// // z_r = z_r*z_r - z_i*z_i + c_r;
		// // z_i = 2*z_i*tmp + c_i;
		// z_r = (z_r*z_r*z_r - 3*z_r*z_i*z_i) + c_r;
		// z_i =  (3*tmp*tmp*z_i - z_i*z_i*z_i) + c_i;
		i++;
	}
	return (i);
}

int	mandelbrot(t_params *pa)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	create_image(pa);
	set_params_mdblt(pa);
	i = 0;
	while (x < pa->algo->image_x)
	{
		y = 0;
		x++;;
		while (y < pa->algo->image_y)
		{
			y++;
			i = algo_mandelbrot(pa, x, y, 0);
			if (i == pa->algo->i_max)
				draw(pa, x, y, 0);
			else
				draw(pa, x, y, i);
		}
	}
	mlx_put_image_to_window(pa->mlx_ptr, pa->win_ptr, pa->data->img, -1, 0);
	mlx_destroy_image(pa->mlx_ptr, pa->data->img);
	return (0);	
}