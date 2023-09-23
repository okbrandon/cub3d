/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:34:05 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/03 14:35:29 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*ft_strdup_fork(char *src, int from, int to)
{
	int		i;
	char	*copy;

	copy = malloc(sizeof(char) * ((to - from) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < (to - from))
	{
		copy[i] = src[from + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	ft_word_count(char const *str, char sep)
{
	int	i;
	int	count;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		last_i;
	int		j;

	if (!s)
		return (NULL);
	splitted = malloc(sizeof(*splitted) * (ft_word_count(s, c) + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		last_i = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != last_i)
			splitted[j++] = ft_strdup_fork((char *) s, last_i, i);
	}
	splitted[j] = 0;
	return (splitted);
}
