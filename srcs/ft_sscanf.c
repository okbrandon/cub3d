/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:44:26 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/18 16:39:55 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdarg.h>

int	ft_sscanf(const char *str, const char *format, ...)
{
	va_list		ap;
	int			count;
	char		*c;
	int			*d;
	int			value;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 'c')
			{
				c = va_arg(ap, char *);
				*c = *str;
				++str;
				++count;
			}
			else if (*format == 'd')
			{
				d = va_arg(ap, int *);
				value = 0;
				while (*str >= '0' && *str <= '9')
				{
					value = value * 10 + (*str - '0');
					++str;
				}
				*d = value;
				++count;
			}
			else if (*format == 's')
			{
				c = va_arg(ap, char *);
				c = va_arg(ap, char *);
				while (*str != ' ' && *str != '\0')
				{
					*c = *str;
					++c;
					++str;
				}
				*c = '\0';
				++count;
			}
			++str;
		}
		else
		{
			if (*str == *format)
				++str;
		}
		++format;
	}
	va_end(ap);
	return (count);
}
