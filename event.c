/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:43:06 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/24 19:54:01 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_mouse(int key, int x, int y, t_params *pa)
{
	if (key == 4)
		mouse_zoom(pa, x, y);
	if (key == 5)
		dezoom(pa);
	return (0);
}

void	next_deal_key(int key, t_params *pa)
{
	if (key == 65436)
		boucle_1(pa);
	if (key == 65433)
		boucle_2(pa);
	if (key == 65435)
		boucle_3(pa);
	if (key == 65430)
		boucle_4(pa);
	if (key == 65437)
		boucle_5(pa);
	if (key == 32)
		setup(pa);
	if (key == 115)
	{
		pa->data->c = 1;
		setup(pa);
	}
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
	if (key == 114)
		color(pa, 1);
	if (key == 103)
		color(pa, 2);
	if (key == 98)
		color(pa, 3);
	next_deal_key(key, pa);
	return (0);
}
