/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 08:44:04 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/31 12:41:48 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

/**
 * @brief Search for a character in a string
 * This function is a replicated version of the libft function ft_strchr
 * The difference is that it returns NULL if the parameter s is empty
 * 
 * @param s 		- The string to search in
 * @param c 		- The character to be searched for
 * @return char* 	- A pointer to the first occurrence of the character
 */
char	*ft_strchr_fork(const char *s, char c)
{
	int	s_len;
	int	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s) + 1;
	i = 0;
	while (i < s_len)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

/**
 * @brief Join two strings together
 * This function is a replicated version of the libft function ft_strjoin
 * 
 * @param s1 		- The first string to be joined
 * @param s2 		- The second string to be joined
 * @return char* 	- THe joined string
 */
char	*ft_strjoin_fork(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

/**
 * @brief Join two strings together and free the first string
 * 
 * @param s1 		- The first string to be joined
 * @param s2 		- The second string to be joined
 * @return char* 	- The joined string
 */
char	*ft_free_to_join(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *) malloc(1);
		s1[0] = '\0';
	}
	str = ft_strjoin_fork(s1, s2);
	free(s1);
	return (str);
}
