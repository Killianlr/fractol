/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:24:36 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/24 19:54:21 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

double	next_ft_atoi_f(const char *nptr, int i, double nb, int d)
{
	if (nptr[i] == '.')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i] - 48;
		i++;
		d++;
	}
	while (d > 0)
	{
		nb /= 10;
		d--;
	}
	return (nb);
}

double	ft_atoi_f(const char *nptr)
{
	int		i;
	int		s;
	int		d;
	double	nb;

	nb = 0;
	i = 0;
	d = 0;
	s = 1;
	while ((nptr[i] == ' ') || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = s * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i] - 48;
		i++;
	}
	nb = next_ft_atoi_f(nptr, i, nb, d);
	return (s * nb);
}

void	next_boucle_5(t_params *pa)
{
	while (pa->cr < -0.2)
	{
		pa->cr += 0.0015;
		pa->ci += 0.001;
		julia(pa);
	}
	while (pa->ci < 0.84)
	{
		pa->ci += 0.001;
		julia(pa);
	}
	while (pa->cr < 0)
	{
		pa->cr += 0.0015;
		pa->ci += 0.0001;
		julia(pa);
	}
}

void	boucle_5(t_params *pa)
{
	pa->cr = -0.7;
	pa->ci = 0.25;
	while (pa->ci < 0.40)
	{
		pa->ci += 0.001;
		julia(pa);
	}
	while (pa->cr < -0.4)
	{
		pa->cr += 0.0015;
		pa->ci += 0.001;
		julia(pa);
	}
	while (pa->ci < 0.67)
	{
		pa->ci += 0.01;
		julia(pa);
	}
	next_boucle_5(pa);
}
