/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:32:45 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/30 22:28:19 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	fl_find_player(t_map map, int *sr, int *sc)
{
	int	i;
	int	j;

	*sr = -1;
	*sc = -1;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.matrix[i][j] == 'N' || map.matrix[i][j] == 'S'
				|| map.matrix[i][j] == 'E' || map.matrix[i][j] == 'W')
			{
				*sr = i;
				*sc = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

bool	fl_visited_boundary(bool **visited, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		if (visited[i][0] || visited[i][map.width - 1])
			return (true);
		i++;
	}
	j = 0;
	while (j < map.width)
	{
		if (visited[0][j] || visited[map.height - 1][j])
			return (true);
		j++;
	}
	return (false);
}

void	ft_draw_square(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_MULT)
	{
		j = 0;
		while (j < MINIMAP_MULT)
		{
			ft_mlx_pixel_put(cub, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	fl_free(bool **visited, t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
