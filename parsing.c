/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:59:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/23 15:15:52 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_julia_shape(t_params *pa, char *cr, char *ci)
{
	if (!cr)
	{
		ft_printf("cr = -0.8 ; ci = 0.156\n");
		return (0);
	}
	pa->cr = ft_atoi_f(cr);
	if (cr && !ci)
	{
		ft_printf("cr = %f ; ci = 0.156\n", pa->cr);
		return (0);
	}
	pa->ci = ft_atoi_f(ci);
	if (cr && ci)
		ft_printf("cr = %f ; ci = %f\n", pa->cr, pa->ci);
	return (0);
}

int	type_of_fractal(t_params *pa, char *type)
{
	if (ft_strncmp(type, "Mandelbrot", 11) == 0)
		pa->type = 1;
	else if (ft_strncmp(type, "Julia", 6) == 0)
		pa->type = 2;
	else if (ft_strncmp(type, "Other", 6) == 0)
		pa->type = 3;
	else
	{
		ft_printf("choose your fractal : Mandelbrot Julia Other\n");
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
		pa->resx = 600;
		pa->resy = 450;
		return (0);
	}
	else if (ft_strncmp(res, "900x675", 9) == 0)
	{
		pa->resx = 900;
		pa->resy = 675;
		return (0);
	}
	else if (ft_strncmp(res, "1200x900", 10) == 0)
	{
		pa->resx = 1200;
		pa->resy = 900;
		return (0);
	}
	else if (ft_strncmp(res, "fullscreen", 10) == 0)
	{
		pa->resx = 2560;
		pa->resy = 1440;
		return (0);
	}
	return (1);
}

void	display_params(void)
{
	ft_printf("/------------------------------\\\n");
	ft_printf("|[Type of fractal] [Resolution] |\n");
	ft_printf("|-------------------------------|\n");
	ft_printf("|  [Mandelbrot]     [600x450]   |\n");
	ft_printf("|  [Julia]          [900x675]   |\n");
	ft_printf("|  [Other]          [1200x900]  |\n");
	ft_printf("|                   [fullscreen]|\n");
	ft_printf("\\------------------------------/\n");
}
