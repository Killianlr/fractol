/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/11 11:36:24 by kle-rest         ###   ########.fr       */
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

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	// if (mlx_ptr == NULL)
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "FRACTOL");
	// test(mlx_ptr, win_ptr);
	mandelbrot(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
}