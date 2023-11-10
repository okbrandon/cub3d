/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_to_trim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:33:39 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/11/10 11:19:32 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_free_to_trim(char *s1, const char *set)
{
	char	*tmp;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	tmp = ft_strtrim(s1, set);
	free(s1);
	return (tmp);
}
