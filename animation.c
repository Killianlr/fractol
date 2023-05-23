/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:28:43 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/23 14:31:19 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	boucle_1(t_params *pa)
{
	pa->cr = -0.7;
	pa->ci = 0.25;
	while(pa->ci < 0.40)
	{
		pa->ci += 0.001;
		julia(pa);
	}
	while (pa->ci > 0.25)
	{
		pa->ci -= 0.001;
		julia(pa);
	}
}

void	boucle_2(t_params *pa)
{
	pa->cr = 0.285;
	pa->ci = 0.0001;
	while (pa->ci < 0.015)
	{
		pa->ci += 0.0005;
		julia(pa);
	}
	while (pa->ci > 0.001)
	{
		pa->ci -= 0.0005;
		julia(pa);
	}
}

void	boucle_3(t_params *pa)
{
	pa->cr = -0.4;
	pa->ci = 0.58;
	while (pa->ci < 0.67)
	{
		pa->ci += 0.001;
		julia(pa);
	}
	while (pa->ci > 0.58)
	{
		pa->ci -= 0.001;
		julia(pa);
	}
}

void	boucle_4(t_params *pa)
{
	pa->cr = 0.3;
	pa->ci = 0.43;
	while (pa->ci < 0.70)
	{
		pa->ci += 0.001;
		julia(pa);
	}
	while (pa->ci > 0.43)
	{
		pa->ci -= 0.001;
		julia(pa);
	}
}
