/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:17:09 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/25 17:19:28 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_p(unsigned long int d, char *base)
{
	int	count;

	count = 0;
	if (d < (unsigned long int)ft_strlen_p(base))
		count += ft_printf_c(base[d]);
	else
	{
		count += ft_putnbr_base(d / (ft_strlen_p(base)), base);
		count += ft_putnbr_base(d % (ft_strlen_p(base)), base);
	}
	return (count);
}
