/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:12:55 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/31 20:30:36 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	fl_init_visited(bool **visited, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			visited[i][j] = false;
			j++;
		}
		i++;
	}
}

void	floodfill(t_map map, bool **visited, int i, int j)
{
	if (i < 0 || i >= map.height || j < 0 || j >= map.width)
		return ;
	if (visited[i][j] || map.matrix[i][j] == '1')
		return ;
	visited[i][j] = true;
	floodfill(map, visited, i + 1, j);
	floodfill(map, visited, i - 1, j);
	floodfill(map, visited, i, j + 1);
	floodfill(map, visited, i, j - 1);
}

bool	fl_can_exit(t_map map)
{
	bool	**visited;
	int		i;
	int		sr;
	int		sc;
	bool	can_exit;

	visited = malloc(map.height * sizeof(bool *));
	i = 0;
	while (i < map.height)
	{
		visited[i] = malloc(map.width * sizeof(bool));
		i++;
	}
	fl_init_visited(visited, map);
	fl_find_player(map, &sr, &sc);
	if (sr == -1)
		return (false);
	floodfill(map, visited, sr, sc);
	can_exit = fl_visited_boundary(visited, map);
	fl_free(visited, map);
	return (can_exit);
}
