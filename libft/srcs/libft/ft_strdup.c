/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:24:25 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/03 14:35:34 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		src_len;
	int		i;
	char	*src_cpy;

	src_len = ft_strlen(s1);
	src_cpy = malloc(sizeof(char) * src_len + 1);
	if (!src_cpy)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		src_cpy[i] = s1[i];
		i++;
	}
	src_cpy[i] = '\0';
	return (src_cpy);
}
