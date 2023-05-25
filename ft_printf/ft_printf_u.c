/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:37:21 by kle-rest          #+#    #+#             */
/*   Updated: 2022/12/12 17:58:10 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printf_u(unsigned int nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	i = ft_putnbr_base(nb, base);
	return (i);
}
