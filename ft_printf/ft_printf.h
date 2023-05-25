/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:15:06 by kle-rest          #+#    #+#             */
/*   Updated: 2023/05/25 17:19:43 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);
int				ft_printf_d(int d);
int				ft_printf_c(char c);
int				ft_printf_s(char *s);
int				ft_printf_i(int nb);
unsigned long	ft_printf_x(unsigned long nb);
unsigned int	ft_printf_xx(unsigned int nb);
unsigned int	ft_printf_u(unsigned int nb);
unsigned long	ft_printf_p(unsigned long nb);
int				ft_strlen_p(char *str);
int				ft_putnbr_base(long int d, char *base);
int				ft_putnbr_base_p(unsigned long int d, char *base);

#endif