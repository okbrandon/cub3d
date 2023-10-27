/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:13 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/27 22:03:25 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	**ft_strsjoin(char **strs, char *str)
{
	int		i;
	char	**new_strs;

	i = 0;
	new_strs = malloc(sizeof(char *) * (ft_strslen(strs) + 2));
	if (!new_strs)
		ft_error("malloc error");
	while (strs[i])
	{
		new_strs[i] = strs[i];
		i++;
	}
	new_strs[i] = str;
	new_strs[i + 1] = NULL;
	free(strs);
	return (new_strs);
}

t_map	ft_map_parser(char *path)
{
	int			fd;
	char		*line;
	char		*tmp;
	int			reading_map;
	t_map		map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("file not found");
	line = get_next_line(fd);
	reading_map = FALSE;
	map.matrix = malloc(sizeof(char *));
	map.height = 0;
	map.width = 0;
	if (!map.matrix)
		ft_error("malloc error");
	while (line != NULL)
	{
		tmp = line;
		line = ft_strtrim(line, "\t\n");
		if (ft_is_line_valid(line) == TRUE)
		{
			reading_map = TRUE;
			map.matrix = ft_strsjoin(map.matrix, ft_strdup(line));
			if (ft_strlen(line) > map.width)
				map.width = ft_strlen(line);
			map.height++;
		}
		else if (reading_map == TRUE)
		{
			free(line);
			ft_error("invalid map");
		}
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	ft_is_map_valid(map);
	ft_normalise_width(map);
	ft_find_player(&map);
	return (map);
}
