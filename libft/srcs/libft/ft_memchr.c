/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:19:08 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/11/01 20:30:32 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*clone;

	i = 0;
	clone = (unsigned char *) s;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char) c)
			return (&clone[i]);
		i++;
	}
	return (NULL);
}
