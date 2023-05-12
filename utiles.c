/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:29:41 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/12 14:39:29 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	get_color(char r, char g, char b)
// {
// 	return ((r << 24) || (g << 16) || (b << 8));
// }

void	endprog(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
	exit(0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_params *pa, int x, int y, int color)
{
	char	*dest;

	dest = pa->data->addr + (y * pa->data->line_length + x * (pa->data->bits_per_pixel / 8));
	*(unsigned int *) dest = color;
}