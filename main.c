/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/23 14:53:22 by kle-rest         ###   ########.fr       */
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
		if (!pa->cr)
		{
			pa->cr = -0.8;
			pa->ci = 0.156;
		}
		julia(pa);
	}
	mlx_key_hook(pa->win_ptr, deal_key, pa);
	mlx_mouse_hook(pa->win_ptr, deal_mouse, pa);
	mlx_hook(pa->win_ptr, 17, 1L<<17, endprog, pa);
	mlx_loop(pa->mlx_ptr);
}

void	setup(t_params *pa)
{
	pa->xc = -1;
	pa->yc = 0;
	pa->zoom = 2.0/3;
	pa->aspect = (float)pa->resx / pa->resy;
	pa->data = (t_data *)malloc(sizeof(t_data));
	pa->data->img = NULL;
	pa->data->addr = NULL;
	pa->data->r = 1.0;
	pa->data->g = 1.0;
	pa->data->b = 1.0;
	pa->algo = (t_a *)malloc(sizeof(t_a));
	run_fractal(pa);
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
	if (pa->type == 2)
		set_julia_shape(pa, av[3], av[4]);
	pa->mlx_ptr = mlx_init();
	create_windows(pa);
	endprog(pa);
	return (0);
}


// int main(int ac, char **av)
// {
// 	void *mlx_ptr;
// 	void *win_ptr;
// 	void *img_ptr;
// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	
// 	img_ptr = mlx_new_image(mlx_ptr, 500, 500);
// 	mlx_destroy_image(mlx_ptr, img_ptr);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	

// 	return (0);
// }

