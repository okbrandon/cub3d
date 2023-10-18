/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:02:51 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/18 19:03:54 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	ft_is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

int	ft_is_map_valid(t_map map)
{
	int	i;
	int	j;
	int	spawn;

	i = 0;
	spawn = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.matrix[i][j] == 'N' || map.matrix[i][j] == 'S' \
				|| map.matrix[i][j] == 'E' || map.matrix[i][j] == 'W')
				spawn++;
			if (spawn > 1)
			{
				printf("Error at map[%d][%d]\n", i, j);
				ft_error("Map contains more than one spawn point (N, S, E, W)");
				return (FALSE);
			}
			if (!ft_is_valid_map_char(map.matrix[i][j]))
			{
				printf("Error at map[%d][%d]\n", i, j);
				ft_error("Map contains invalid characters");
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	if (spawn == 0)
	{
		ft_error("Map contains no spawn point (N, S, E, W)");
		return (FALSE);
	}
	return (TRUE);
}