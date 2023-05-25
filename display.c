/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:23:39 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/24 20:59:47 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_commandes(void)
{
	ft_printf("\n");
	ft_printf("   /-----------------------\\\n");
	ft_printf("   |      [COMMANDES]      |\n");
	ft_printf("   |      Z = Zoom         |\n");
	ft_printf("   |      D = Dezoom       |\n");
	ft_printf("   |      → = Move right   |\n");
	ft_printf("   |      ← = Move left    |\n");
	ft_printf("   |      ↑ = Move up      |\n");
	ft_printf("   |      ↓ = Move down    |\n");
	ft_printf("   |      S = Restart      |\n");
	ft_printf("   |  SPACE = Max dezoom   |\n");
	ft_printf("   |      R = Red          |\n");
	ft_printf("   |      G = Green        |\n");
	ft_printf("   |      B = Blue         |\n");
	ft_printf("   |      1 = Animation_1  |\n");
	ft_printf("   |      2 = Animation_2  |\n");
	ft_printf("   |      3 = Animation_3  |\n");
	ft_printf("   |      4 = Animation_4  |\n");
	ft_printf("   |      5 = Animation_5  |\n");
	ft_printf("   \\-----------------------/\n");
}

void	display_params(void)
{
	ft_printf("/-------------------------------\\\n");
	ft_printf("|[Type of fractal] [Resolution] |\n");
	ft_printf("|-------------------------------|\n");
	ft_printf("|  [Mandelbrot]     [600x450]   |\n");
	ft_printf("|  [Julia]          [900x675]   |\n");
	ft_printf("|  [Supermand]      [1200x900]  |\n");
	ft_printf("|                   [fullscreen]|\n");
	ft_printf("\\-------------------------------/\n");
	display_commandes();
}

void	display_julia_values(t_params *pa)
{
	ft_printf("/-------------------------------------------\\\n");
	ft_printf("| cr = -0.6              | ci = 0.6         |\n");
	ft_printf("| cr = -0.8              | ci = 0.2         |\n");
	ft_printf("| cr = 0.3               | ci = 0.5         |\n");
	ft_printf("| cr = 0.285             | ci = 0.01        |\n");
	ft_printf("| cr = -1.0              | ci = 0.2         |\n");
	ft_printf("| cr = -0.038088         | ci = 0.9754633   |\n");
	ft_printf("| cr = -1.417022285618   | ci = 0.0099534   |\n");
	ft_printf("\\-------------------------------------------/\n");
	free(pa);
}
