/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:40:57 by kle-rest          #+#    #+#             */
/*   Updated: 2022/12/12 17:56:31 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	perse_params(va_list params, char c)
{
	if (c == '%')
		return (write(1, "%%", 1));
	else if (c == 'c')
		return (ft_printf_c((char)va_arg(params, int)));
	else if (c == 's')
		return (ft_printf_s(va_arg(params, char *)));
	else if (c == 'p')
		return (ft_printf_p(va_arg(params, unsigned long)));
	else if (c == 'd')
		return (ft_printf_d(va_arg(params, int)));
	else if (c == 'i')
		return (ft_printf_i(va_arg(params, int)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(params, unsigned int)));
	else if (c == 'x')
		return (ft_printf_x(va_arg(params, unsigned int)));
	else if (c == 'X')
		return (ft_printf_xx(va_arg(params, unsigned int)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	params;

	va_start (params, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += perse_params(params, format[i]);
		}
		else
			len += ft_printf_c(format[i]);
		i++;
	}
	return (len);
}
