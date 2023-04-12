/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/12 15:55:54 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_mouse(int key, int x, int y, t_params *pa)
{
	int rapport;
	int rapport_for_x;

	rapport = pa->resx/pa->resy;
	rapport_for_x = 100/rapport;
	printf("mousekey = %d ; x = %d ; y = %d\n", key, x, y);
	if (key == 4)
	{
		pa->resx = pa->resx + rapport_for_x;
		pa->resy = pa->resy + (100 - rapport_for_x);
		pa->x = pa->x + rapport_for_x;
		pa->y = pa->y + (100 - rapport_for_x);
		mandelbrot(pa);
	}
	return (0);
}

int	deal_key(int key, t_params *pa)
{
	printf("keyboard = %d\n", key);
	if (key == 65307)
		endprog(pa->mlx_ptr, pa->win_ptr);
	return (0);
}

void	setup(t_params *pa)
{
	pa->x = 0;
	pa->y = 0;
	printf("x = %f, y = %f\n", pa->x, pa->y);
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