/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/11 15:40:23 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	test(void *mlx_ptr, void *win_ptr)
// {
// 	int	i;
// 	int x;
// 	int y;
// 	int rgb;

// 	i = 0;
// 	x = 0;
// 	y = 450;
// 	rgb = mlx_get_color_value(mlx_ptr, 65535);
// 	while (i < 900)
// 	{
// 		x = x + 1;
// 		mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb);
// 		i++;
// 	}
// 	x = 450;
// 	y = 0;
// 	i = 0;
// 	while (i < 900)
// 	{
// 		y = y + 1;
// 		mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb);
// 		i++;
// 	}
// 	return (0);
// }

int	deal_mouse(int key, t_params pa)
{
	printf("mousekey = %d\n", key);
	if (key == 4)
	{
		printf("zoooooooooooom\n");
		mlx_mouse_get_pos(pa.mlx_ptr, pa.win_ptr, &pa.x, &pa.y);
		// printf("x = %p, y = %p\n", x, y);
	}
	return (0);
}

int	deal_key(int key, t_params *pa)
{
	printf("keyboard = %d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(pa->mlx_ptr, pa->win_ptr);
		return (1);
	}
	return (0);
}

int	main()
{
	t_params *pa;

	pa = (t_params *)malloc(sizeof(t_params));
	if (!pa)
		return (1);
	pa->x = 800;
	pa->y = 600;
	pa->mlx_ptr = mlx_init();
	// if (mlx_ptr == NULL)
	pa->win_ptr = mlx_new_window(pa->mlx_ptr, pa->x, pa->y, "FRACTOL");
	// test(mlx_ptr, win_ptr);
	mandelbrot(pa->mlx_ptr, pa->win_ptr);
	mlx_key_hook(pa->win_ptr, deal_key, pa);
	mlx_mouse_show(pa->mlx_ptr, pa->win_ptr);
	mlx_mouse_hook(pa->win_ptr, deal_mouse, pa);
	mlx_loop(pa->mlx_ptr);
}