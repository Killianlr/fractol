/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/12 16:49:37 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	setup(t_params *pa)
{
	pa->xc = -1;
	pa->yc = 0;
	pa->zoom = 2.0/3;
	pa->aspect = (float)pa->resx / pa->resy;
	pa->data = (t_data *)malloc(sizeof(t_data));
	if (pa->type == 1)
	{
		pa->mdblt = (t_a *)malloc(sizeof(t_a));
		mandelbrot(pa);
	}
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