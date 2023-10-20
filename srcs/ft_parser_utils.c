/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:02:51 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/20 15:53:42 by evmorvan         ###   ########.fr       */
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

int	ft_is_line_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_is_valid_map_char(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_top_or_bottom(char **matrix, int i, int j)
{
	if (!matrix || !matrix[i] || !matrix[i][j])
		return (FALSE);
	while (matrix[i][j] == ' ' || matrix[i][j] == '\t'
	|| matrix[i][j] == '\r' || matrix[i][j] == '\v'
	|| matrix[i][j] == '\f')
		j++;
	while (matrix[i][j])
	{
		if (matrix[i][j] != '1')
		{
			printf("Error at map[%d][%d]=%c\n", i, j, matrix[i][j]);
			return (FALSE);
		}
		j++;
	}
	return (TRUE);
}

int	check_map_sides(t_map *map, char **matrix)
{
	int	i;
	int	j;

	if (check_top_or_bottom(matrix, 0, 0) == FALSE)
		return (FALSE);
	i = 0;
	while (i < map->height)
	{
		j = ft_strlen(matrix[i]) - 1;
		if (matrix[i][j] != '1')
			return (FALSE);
		i++;
	}
	i -= 1;
	if (check_top_or_bottom(matrix, i, 0) == FALSE)
		return (FALSE);
	return (TRUE);
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
		while (j < ft_strlen(map.matrix[i]))
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
	if (check_map_sides(&map, map.matrix) == FALSE)
	{
		ft_error("Map must be surrounded by walls");
		return (FALSE);
	}
	return (TRUE);
}