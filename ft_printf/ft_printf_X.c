/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:37:26 by kle-rest          #+#    #+#             */
/*   Updated: 2022/12/12 17:54:55 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printf_xx(unsigned int nb)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	i = ft_putnbr_base(nb, base);
	return (i);
}
