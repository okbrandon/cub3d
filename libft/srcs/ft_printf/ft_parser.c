/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:05:31 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/31 15:38:21 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_parse_formatters(const char *format, int i, va_list args)
{
	int	count;

	count = 0;
	if (format[i] != '%')
	{
		if (format[i] == 's')
			count += ft_putstr(va_arg(args, char *));
		else if (format[i] == 'd' || format[i] == 'i')
			count += ft_putnbr(va_arg(args, int));
		else if (format[i] == 'c')
			count += ft_putchar(va_arg(args, int));
		else if (format[i] == 'u')
			count += ft_putunsigned(va_arg(args, unsigned int));
		else if (format[i] == 'x')
			count += ft_puthexnbr(va_arg(args, unsigned int), 0);
		else if (format[i] == 'X')
			count += ft_puthexnbr(va_arg(args, unsigned int), 1);
		else if (format[i] == 'p')
			count += ft_putpointer(va_arg(args, unsigned long long));
		else
			count += ft_putchar(format[i]);
	}
	else
		count += ft_putchar(format[i]);
	return (count);
}
