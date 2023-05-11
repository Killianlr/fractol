/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:20:23 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/18 14:01:55 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_params_mdblt(t_params *pa, t_a *mdblt)
{
	mdblt->x1 = pa->xc - pa->aspect/pa->zoom;
	mdblt->x2 = pa->xc + pa->aspect/pa->zoom;
	mdblt->y1 = pa->yc - 1/pa->zoom;
	mdblt->y2 = pa->yc + 1/pa->zoom;
	mdblt->image_x = pa->resx;
	mdblt->image_y = pa->resy;
	mdblt->zoom_x = mdblt->image_x/(mdblt->x2 - mdblt->x1);
	mdblt->zoom_y = mdblt->image_y/(mdblt->y2 - mdblt->y1);
	mdblt->i_max = 100;
}

int	algo_mandelbrot(t_a *mdblt, int x, int y, int i)
{
	double	tmp;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;

	tmp = 0;
	c_r = (x / mdblt->zoom_x) + mdblt->x1;
	c_i = (y / mdblt->zoom_y) + mdblt->y1;
	z_r = 0;
	z_i = 0;
	while (z_r*z_r + z_i*z_i < 4 && i < mdblt->i_max)
	{
		tmp = z_r;
		z_r = z_r*z_r - z_i*z_i + c_r;
		z_i = 2*z_i*tmp + c_i;
		i = i + 1;
	}
	return (i);
}

int	mandelbrot(t_params *pa)
{
	t_a	*mdblt;
	int	x;
	int	y;
	int	i;

	mdblt = (t_a *)malloc(sizeof(t_a));
	x = 0;
	pa->data->img = mlx_new_image(pa->mlx_ptr, pa->resx, pa->resy);
	set_params_mdblt(pa, mdblt);
	while (x < mdblt->image_x)
	{
		y = 0;
		x++;
		while (y < mdblt->image_y)
		{
			y++;
			i = 0;
			i = algo_mandelbrot(mdblt, x, y, i);
			if (i == mdblt->i_max)
			{	
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 78090);
			}
			else
				mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 0);
		}
	}
	// mlx_put_image_to_window(pa->mlx_ptr, pa->win_ptr, pa->data->img, 0, 0);
	printf("x = %d, y = %d\n", x, y);
	return (0);	
}

void	mouse_zoom(t_params *pa, int x, int y)
{
	(void)x;
	(void)y;
	pa->zoom *= 1.2;
	// resx = 1200
	// resy = 900
	// xc = -1
	// yc = 0
	// x = 300
	// y = 200
	printf("ZOOOOOOM\n");
	 pa->xc -= (pa->resx/2 - x) * 0.9 / pa->resx  / pa->zoom;
	 pa->yc -= (pa->resy/2 - y) * 0.9 / pa->resy  / pa->zoom;
	mandelbrot(pa);
}

void	zoom(t_params *pa)
{
	pa->zoom *= 1.2;
	mandelbrot(pa);
}
void	dezoom(t_params *pa)
{
	pa->zoom /= 1.2;
	mandelbrot(pa);
}

void	left(t_params *pa)
{
	pa->xc -= 0.2/pa->zoom;
	mandelbrot(pa);
}

void	right(t_params *pa)
{
	pa->xc += 0.2/pa->zoom;
	mandelbrot(pa);
}

void	up(t_params *pa)
{
	pa->yc -= 0.2/pa->zoom;
	mandelbrot(pa);
}

void	down(t_params *pa)
{
	pa->yc += 0.2/pa->zoom;
	mandelbrot(pa);
}