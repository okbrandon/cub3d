/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:02:34 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/26 19:07:08 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_is_valid_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (FALSE);
	if (g < 0 || g > 255)
		return (FALSE);
	if (b < 0 || b > 255)
		return (FALSE);
	return (TRUE);
}

int	dir_from_id(char *identifier)
{
	if (ft_strncmp(identifier, "NO ", 3) == 0)
		return (DIR_NORTH);
	if (ft_strncmp(identifier, "SO ", 3) == 0)
		return (DIR_SOUTH);
	if (ft_strncmp(identifier, "WE ", 3) == 0)
		return (DIR_WEST);
	if (ft_strncmp(identifier, "EA ", 3) == 0)
		return (DIR_EAST);
	return (-1);
}
