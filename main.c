/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/13 15:46:35 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_backgrown(t_params *pa)
{
	int	x;
	int	y;
	x = 0;
	while (x < 1600)
	{
		y = 0;
		while (y < 900)
		{
			mlx_pixel_put(pa->mlx_ptr, pa->win_ptr, x, y, 0);
			y++;
		}
		x++;
	}
}

void	thefuckingzoom(t_params *pa, int posx, int posy)
{
	printf("resx = %d, resu = %d, posx = %d, posy = %d\n", pa->resx, pa->resy, posx, posy);
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x2 = (pa->resx + posx) - pa->resx;
	x1 = pa->resx - posx;
	y2 = (pa->resy + posy) - pa->resy;
	y1 = pa->resy - posy;
	x1 = x1 *0.1;
	x2 = x2 *0.1;
	y1 = y1 *0.1;
	y2 = y2 *0.1;
	pa->x1 = x1;
	pa->y1 = y1;
	pa->x1 = x2;
	pa->y1 = y2;
	printf("x1 = %d, x2 = %d\n", x1, x2);
	printf("y1 = %d, y2 = %d\n", y1, y2);
}

int	deal_mouse(int key, int x, int y, t_params *pa)
{
	if (key == 4)
	{
		reset_backgrown(pa);
		pa->resx = pa->resx - (pa->resx * 0.1);
		pa->resy = pa->resy - (pa->resy * 0.1);
		thefuckingzoom(pa, x, y);
		printf("x = %d y = %d\n", pa->x, pa->y);
		// pa->x = pa->x - (pa->resx * 0.05);
		// pa->y = pa->y - (pa->resy * 0.05);
		mandelbrot(pa);
	}
	if (key == 5)
	{
		reset_backgrown(pa);
		printf("x = %d y = %d\n", pa->x, pa->y);
		// pa->resx = pa->resx + (pa->resx * 0.1);
		// pa->resy = pa->resy + (pa->resy * 0.1);
		// pa->x = pa->x - (pa->resx * 0.05);
		// pa->y = pa->y - (pa->resy * 0.05);
		mandelbrot(pa);
	}
	return (0);
}

int	deal_key(int key, t_params *pa)
{
	// printf("keyboard = %d\n", key);
	if (key == 65307)
		endprog(pa->mlx_ptr, pa->win_ptr);
	return (0);
}

void	setup(t_params *pa)
{
	pa->x2 = 0;
	pa->y2 = 0;
	printf("x = %d, y = %d\n", pa->x, pa->y);
	if (pa->type == 1)
		mandelbrot(pa);
	mlx_key_hook(pa->win_ptr, deal_key, pa);
	mlx_mouse_hook(pa->win_ptr, deal_mouse, pa);
	mlx_loop(pa->mlx_ptr);
}

void	create_windows(t_params *pa)
{
	if (pa->type == 1)
	{
		pa->win_ptr = mlx_new_window(pa->mlx_ptr, pa->resx, pa->resy, "Mandelbrot");
		setup(pa);
	}
	if (pa->type == 2)
	{
		pa->win_ptr = mlx_new_window(pa->mlx_ptr, pa->resx, pa->resy, "Julia");
		setup(pa);
	}
	if (pa->type == 3)
	{
		pa->win_ptr = mlx_new_window(pa->mlx_ptr, pa->resx, pa->resy, "Other");
		setup(pa);
	}
}

int	main(int ac, char **av)
{
	t_params *pa;

	if (ac < 2)
	{
		display_params();
		return (1);
	}
	pa = (t_params *)malloc(sizeof(t_params));
	if (!pa)
		return (1);
	if (type_of_fractal(pa, av[1]))
		return (1);
	if (set_resolution(pa, av[2]))
		return (1);
	pa->mlx_ptr = mlx_init();
	create_windows(pa);
	return (0);
}