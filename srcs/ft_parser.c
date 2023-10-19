/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:49:10 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/19 13:40:55 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

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

char	*get_file_content(char *path)
{
	int		fd;
	char	*line;
	char	*content;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("file not found");
	content = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		content = ft_strjoin(content, line);
		content = ft_strjoin(content, "\n");
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (content);
}

void	init_textures(t_cub *cub)
{
	cub->textures.mlx_textures = malloc(sizeof(t_mlx) * 5);
	cub->textures.ceiling = 0;
	cub->textures.floor = 0;
}

void	path_to_texture(t_cub *cub, int dir, char *path)
{
	void	*image;
	int		height;
	int		width;

	height = 64;
	width = 64;
	image = mlx_xpm_file_to_image(cub->mlx.mlx, path, &width, &height);
	if (image == NULL)
		ft_error("texture not found");
	cub->textures.mlx_textures[dir].img = image;
	cub->textures.mlx_textures[dir].addr = mlx_get_data_addr(image, \
		&cub->textures.mlx_textures[dir].bits_per_pixel, \
		&cub->textures.mlx_textures[dir].line_length, \
		&cub->textures.mlx_textures[dir].endian);
	if (!cub->textures.mlx_textures[dir].addr)
		ft_error("mlx_get_data_addr failed");
	free(path);
}

// Replace with constants
void	parse_texture_lines(char *line, t_cub *cub)
{
	char	*path;

	path = malloc(sizeof(char) * ft_strlen(line));
	if (line[0] == 'N' && line[1] == 'O')
    {
        sscanf(line, "NO %s", path);
		path_to_texture(cub, 0, path);
    }
	else if (line[0] == 'S' && line[1] == 'O')
	{
		sscanf(line, "SO %s", path);
		path_to_texture(cub, 1, path);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		sscanf(line, "WE %s", path);
		path_to_texture(cub, 2, path);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		sscanf(line, "EA %s", path);
		path_to_texture(cub, 3, path);
	}
}

void	parse_color_lines(char *line, t_cub *cub)
{
	int	r;
	int	g;
	int	b;

	if (line[0] == 'F')
	{
		sscanf(line, "F %d,%d,%d", &r, &g, &b);
		if (ft_is_valid_rgb(r, g, b) == FALSE)
			ft_error("color value must be between 0 and 255");
		cub->textures.floor = ft_to_trgb(0, r, g, b);
	}
	else if (line[0] == 'C')
	{
		sscanf(line, "C %d,%d,%d", &r, &g, &b);
		if (ft_is_valid_rgb(r, g, b) == FALSE)
			ft_error("color value must be between 0 and 255");
		cub->textures.ceiling = ft_to_trgb(0, r, g, b);
	}
}

void	parse_map_lines(char *line, t_map *map, int *j)
{
	map->matrix[*j] = malloc(sizeof(char) * ft_strlen(line));
	ft_strcpy(map->matrix[*j], line);
	(*j)++;
}

t_map	ft_unsafe_parse(t_cub *cub, char *map_str)
{
	int		i;
	int		j;
	char	line[1024];
	t_map	map;

	map_str = get_file_content(map_str);
	map.width = 21;
	map.height = 21;
    map.matrix = malloc(sizeof(char *) * map.height);
	init_textures(cub);
	j = 0;
	while (sscanf(map_str, "%1023[^\n]\n%n", line, &i) == 1)
	{
		if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
			|| line[0] == 'E')
			parse_texture_lines(line, cub);
		else if (line[0] == 'F' || line[0] == 'C')
			parse_color_lines(line, cub);
		else
			parse_map_lines(line, &map, &j);
		map_str += i;
	}
	ft_is_map_valid(map);
	return (map);
}
