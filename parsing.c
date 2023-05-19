/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavian <flavian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:59:11 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/19 17:08:32 by flavian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		printf("choose your fractal : Mandelbrot Julia Other\n");
		free(pa);
		return (1);
	}
	return (0);
}

int	set_resolution(t_params *pa, char *res)
{
	if (!res)
	{
		printf("choose your resolution : 1366x768 1600x900");
		printf(" 1920x1080 2560x1440\n");
		free(pa);
		return (1);
	}
	if (check_resolution(pa, res))
	{
		printf("choose your resolution : 1366x768 1600x900");
		printf(" 1920x1080 2560x1440\n");
		free(pa);
		return (1);
	}
	return (0);
}

int	check_resolution(t_params *pa, char *res)
{
	if (ft_strncmp(res, "1200x900", 9) == 0)
	{
		pa->resx = 600;
		pa->resy = 450;
		return (0);
	}
	else if (ft_strncmp(res, "1600x900", 9) == 0)
	{
		pa->resx = 1600;
		pa->resy = 900;
		return (0);
	}
	else if (ft_strncmp(res, "1920x1080", 10) == 0)
	{
		pa->resx = 1920;
		pa->resy = 1080;
		return (0);
	}
	else if (ft_strncmp(res, "2560x1440", 10) == 0)
	{
		pa->resx = 2560;
		pa->resy = 1440;
		return (0);
	}
	return (1);
}

void	display_params(void)
{
	printf("/------------------------------\\\n");
	printf("|[Type of fractal] [Resolution]|\n");
	printf("|------------------------------|\n");
	printf("|  [Mandelbrot]     [1366x768] |\n");
	printf("|  [Julia]          [1600x900] |\n");
	printf("|  [Other]          [1920x1080]|\n");
	printf("|                   [2560x1440]|\n");
	printf("\\------------------------------/\n");
}
