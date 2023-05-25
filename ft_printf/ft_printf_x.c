/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:37:24 by kle-rest          #+#    #+#             */
/*   Updated: 2022/12/12 17:59:10 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_printf_x(unsigned long nb)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	i = ft_putnbr_base(nb, base);
	return (i);
}
