/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:57:00 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/03 14:36:06 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	mallocable;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t) ft_strlen(s) < start)
		return (ft_strdup(""));
	mallocable = 0;
	if ((size_t) ft_strlen(s) > start)
		mallocable = ft_strlen(s) - start;
	if (mallocable > len)
		mallocable = len;
	str = malloc(sizeof(char) * (mallocable + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
