/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:02:51 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/28 13:35:09 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	ft_is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	ft_is_line_valid(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			break ;
		i++;
	}
	if (i >= ft_strlen(line))
		return (false);
	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			line[i] = '1';
		if (!ft_is_valid_map_char(line[i]))
			return (false);
	}
	return (true);
}

static bool	ft_is_matrix_valid(t_map map, int *spawn)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < ft_strlen(map.matrix[i]))
		{
			if (map.matrix[i][j] == 'N' || map.matrix[i][j] == 'S' \
				|| map.matrix[i][j] == 'E' || map.matrix[i][j] == 'W')
				(*spawn)++;
			if (*spawn > 1)
			{
				ft_error("Map contains more than one spawn point (N, S, E, W)");
				return (false);
			}
			if (!ft_is_valid_map_char(map.matrix[i][j]))
			{
				ft_error("Map contains invalid characters");
				return (false);
			}
		}
	}
	return (true);
}

bool	ft_is_map_valid(t_map map)
{
	int	spawn;

	spawn = 0;
	if (!ft_is_matrix_valid(map, &spawn))
		return (false);
	if (spawn == 0)
	{
		ft_error("Map contains no spawn point (N, S, E, W)");
		return (false);
	}
	if (fl_can_exit(map))
	{
		ft_error("Map is not closed");
		return (false);
	}
	return (true);
}

void	ft_find_player(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < ft_strlen(map->matrix[i]))
		{
			if (map->matrix[i][j] == 'N' || map->matrix[i][j] == 'S' \
				|| map->matrix[i][j] == 'E' || map->matrix[i][j] == 'W')
			{
				map->player_x = i;
				map->player_y = j;
				map->player_dir = map->matrix[i][j];
				return ;
			}
		}
	}
}
