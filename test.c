/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:11:27 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/15 17:40:18 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

int	deal_mouse(int key, int x, int y, t_params *pa)
{
	(void)key;
	(void)x;
	(void)y;
	(void)pa;
	if (key == 1)
		printf("x = %d, y = %d\n", x, y);
	if (key == 4)
		mouse_zoom(pa, x, y);
	if (key == 5)
		dezoom(pa);
	return (0);
}

int	deal_key(int key, t_params *pa)
{
	if (key == 65307)
		endprog(pa);
	if (key == 122)
		zoom(pa);
	if (key == 100)
		dezoom(pa);
	if (key == 65362)
		up(pa);
	if (key == 65364)
		down(pa);
	if (key == 65363)
		right(pa);
	if (key == 65361)
		left(pa);
	return (0);
}

void	testdrawing(t_params *pa, int x, int y)
{
	int	t;
	int	r;
	int	g;
	int	b;
	double	midx;
	double	midy;
	double	range;

	midx = pa->resx / 2;
	midy = pa->resy / 2;
	range = sqrt(pow(x - midx, 6) + pow(y - midy, 6));
	t = 255;
	r = 255 - ((range / sqrt(pow(midx, 2) + pow(midy, 2))) * 255);
	g = 255 - ((range / sqrt(pow(midx, 2) + pow(midy, 2))) * 255);
	b = 255 - ((range / sqrt(pow(midx, 2) + pow(midy, 2))) * 255);
	my_mlx_pixel_put(pa, x, y, create_trgb(t, r, g, b));




















	// if (x < resx)
	// {
	// 	if (y < resy)
	// 	{
	// 		t = 255 * x / resx * y / resy;
	// 		r = 255 * x / resx * y / resy;
	// 		g = 255 * x / resx * y / resy;
	// 		b = 255 * x / resx * y / resy;	
	// 	}
	// 	else
	// 	{
	// 		t = 255 - (255 * x / resx * y / pa->resy);
	// 		r = 255 - (255 * x / resx * y / pa->resy);
	// 		g = 255 - (255 * x / resx * y / pa->resy);
	// 		b = 255 - (255 * x / resx * y / pa->resy);
	// 	}
	// 	my_mlx_pixel_put(pa, x, y, create_trgb(t, r, g, b));
	// }
	// else if (x > resx)
	// {
	// 	if (y < resy)
	// 	{
	// 		t = 255 - (255 * x / resx * y / pa->resy);
	// 		r = 255 - (255 * x / resx * y / pa->resy);
	// 		g = 255 - (255 * x / resx * y / pa->resy);
	// 		b = 255 - (255 * x / resx * y / pa->resy);
	// 	}
	// 	else
	// 	{
	// 		t = 255 - (255 * x / pa->resx * y / pa->resy);
	// 		r = 255 - (255 * x / pa->resx * y / pa->resy);
	// 		g = 255 - (255 * x / pa->resx * y / pa->resy);
	// 		b = 255 - (255 * x / pa->resx * y / pa->resy);
	// 	}
	// 	my_mlx_pixel_put(pa, x, y, create_trgb(t, r, g, b));
	// }
}

void	testdraw(t_params *pa)
{
	int	x;
	int	y;

	x = 0;
	while (x < pa->resx)
	{
		y = 0;
		x++;
		while (y < pa->resy)
		{
			y++;
			testdrawing(pa, x, y);
		}
	}
}

int	main()
{
	t_params *pa;
	
	pa = (t_params *)malloc(sizeof(t_params));
	pa->mlx_ptr = mlx_init();
	pa->resx = 1200;
	pa->resy = 900;
	pa->data = (t_data *)malloc(sizeof(t_data));
	pa->xc = -1;
	pa->yc = 0;
	pa->win_ptr = mlx_new_window(pa->mlx_ptr, pa->resx, pa->resy, "TEST");
	mlx_key_hook(pa->win_ptr, deal_key, pa);
	mlx_mouse_hook(pa->win_ptr, deal_mouse, pa);
	mlx_hook(pa->win_ptr, 17, 1L<<17, endprog, pa);
	create_image(pa);
	testdraw(pa);
	mlx_put_image_to_window(pa->mlx_ptr, pa->win_ptr, pa->data->img, -1, 0);
	mlx_destroy_image(pa->mlx_ptr, pa->data->img);
	mlx_loop(pa->mlx_ptr);
}