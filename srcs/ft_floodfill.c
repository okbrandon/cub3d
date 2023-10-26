/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:12:55 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/26 23:54:22 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
