/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:48:54 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/07 10:58:27 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_puthexnbr(unsigned int n, int is_upper)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthexnbr(n / 16, is_upper);
		i += ft_puthexnbr(n % 16, is_upper);
	}
	else
	{
		if (n < 10)
			i += ft_putchar(n + '0');
		else
		{
			if (is_upper)
				i += ft_putchar(ft_toupper(n + 'a' - 10));
			else
				i += ft_putchar(ft_tolower(n + 'a' - 10));
		}
	}
	return (i);
}
