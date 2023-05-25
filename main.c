/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/24 21:29:55 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	run_fractal(t_params *pa)
{
	if (pa->type == 1)
		mandelbrot(pa);
	if (pa->type == 2)
	{
		pa->xc = 0;
		if (pa->c == 2)
		{
			pa->cr = -0.8;
			pa->ci = 0.156;
		}
		julia(pa);
	}
	if (pa->type == 3)
	{
		pa->xc = 0;
		supermand(pa);
	}
	mlx_key_hook(pa->win_ptr, deal_key, pa);
	mlx_mouse_hook(pa->win_ptr, deal_mouse, pa);
	mlx_hook(pa->win_ptr, 17, 1L << 17, endprog, pa);
	mlx_loop(pa->mlx_ptr);
}

int	setup(t_params *pa)
{
	pa->xc = -1;
	pa->yc = 0;
	pa->zoom = 2.0 / 3;
	pa->aspect = (float)pa->rx / pa->ry;
	pa->data->c = 1;
	pa->data->img = NULL;
	pa->data->addr = NULL;
	if (pa->data->c == 1)
	{
		pa->data->r = 1.0;
		pa->data->g = 1.0;
		pa->data->b = 1.0;
		pa->data->c = 2;
	}
	run_fractal(pa);
	return (0);
}

int	create_windows(t_params *pa)
{
	if (pa->type == 1)
	{
		pa->win_ptr = mlx_new_window(pa->mlx_ptr, pa->rx, pa->ry, "Mandelbrot");
		if (setup(pa) == 1)
			return (1);
	}
	if (pa->type == 2)
	{
		pa->win_ptr = mlx_new_window(pa->mlx_ptr, pa->rx, pa->ry, "Julia");
		if (setup(pa) == 1)
			return (1);
	}
	if (pa->type == 3)
	{
		pa->win_ptr = mlx_new_window(pa->mlx_ptr, pa->rx, pa->ry, "Supermand");
		if (setup(pa) == 1)
			return (1);
	}
	return (0);
}

int	next_main(t_params *pa)
{
	pa->mlx_ptr = mlx_init();
	if (!pa->mlx_ptr)
	{
		free(pa);
		return (1);
	}
	pa->data = (t_data *)malloc(sizeof(t_data));
	if (!pa->data)
		return (1);
	pa->algo = (t_a *)malloc(sizeof(t_a));
	if (!pa->algo)
		return (1);
	create_windows(pa);
	endprog(pa);
	return (0);
}

int	main(int ac, char **av)
{
	t_params	*pa;

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
	if (pa->type == 2 && av[3] && ft_strncmp(av[3], "values", 7) == 0)
	{
		display_julia_values(pa);
		return (1);
	}
	if (pa->type == 2)
		set_julia_shape(pa, av[3], av[4]);
	if (next_main(pa) == 1)
		endprog(pa);
	return (0);
}
