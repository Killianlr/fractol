/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:59:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/24 19:52:54 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	type_of_fractal(t_params *pa, char *type)
{
	if (ft_strncmp(type, "Mandelbrot", 11) == 0)
		pa->type = 1;
	else if (ft_strncmp(type, "Julia", 6) == 0)
		pa->type = 2;
	else if (ft_strncmp(type, "Supermand", 10) == 0)
		pa->type = 3;
	else
	{
		ft_printf("choose your fractal : Mandelbrot Julia Supermand\n");
		free(pa);
		return (1);
	}
	return (0);
}

int	set_resolution(t_params *pa, char *res)
{
	if (!res)
	{
		ft_printf("choose your resolution : 600x450 900x675");
		ft_printf(" 1200x900 fullscreen\n");
		free(pa);
		return (1);
	}
	if (check_resolution(pa, res))
	{
		ft_printf("choose your resolution : 600x450 900x675");
		ft_printf(" 1200x900 fullscreen\n");
		free(pa);
		return (1);
	}
	return (0);
}

int	check_resolution(t_params *pa, char *res)
{
	if (ft_strncmp(res, "600x450", 9) == 0)
	{
		pa->rx = 600;
		pa->ry = 450;
		return (0);
	}
	else if (ft_strncmp(res, "900x675", 9) == 0)
	{
		pa->rx = 900;
		pa->ry = 675;
		return (0);
	}
	else if (ft_strncmp(res, "1200x900", 10) == 0)
	{
		pa->rx = 1200;
		pa->ry = 900;
		return (0);
	}
	else if (ft_strncmp(res, "fullscreen", 10) == 0)
	{
		pa->rx = 2560;
		pa->ry = 1440;
		return (0);
	}
	return (1);
}
