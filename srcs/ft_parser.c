/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:13 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/28 10:36:14 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_map	ft_init_map(void)
{
	t_map	map;

	map.matrix = ft_calloc(1, sizeof(char *));
	map.height = 0;
	map.width = 0;
	if (!map.matrix)
		ft_error("malloc error");
	return (map);
}

static void	ft_fill_matrix(t_map *map, int fd)
{
	char		*line;
	int			reading_map;

	reading_map = FALSE;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_free_to_trim(line, "\t\n");
		if (ft_is_line_valid(line) == TRUE)
		{
			reading_map = TRUE;
			map->matrix = ft_strsjoin(map->matrix, ft_strdup(line));
			if (ft_strlen(line) > map->width)
				map->width = ft_strlen(line);
			map->height++;
		}
		else if (reading_map == TRUE)
		{
			free(line);
			ft_error("invalid map");
		}
		free(line);
	}
}

static void	ft_normalise_width(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = ft_strlen(map.matrix[i]);
		while (j < map.width)
		{
			map.matrix[i] = ft_free_to_join(map.matrix[i], "1");
			j++;
		}
		i++;
	}
}

t_map	ft_map_parser(char *path)
{
	int			fd;
	t_map		map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("file not found");
	map = ft_init_map();
	ft_fill_matrix(&map, fd);
	close(fd);
	ft_is_map_valid(map);
	ft_normalise_width(map);
	ft_find_player(&map);
	return (map);
}
