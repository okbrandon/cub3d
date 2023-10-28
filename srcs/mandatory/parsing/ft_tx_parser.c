/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tx_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:14:50 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/28 11:19:45 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	parse_color(t_textures *texture, char *line)
{
	int	*rgb;

	if (line[0] == 'C')
	{
		if (texture->ceiling != -1)
			ft_error("ceiling color already set");
		rgb = scan_rgb("C", line);
		if (!ft_is_valid_rgb(rgb[0], rgb[1], rgb[2]))
			ft_error("invalid rgb color");
		texture->ceiling = ft_to_trgb(0, rgb[0], rgb[1], rgb[2]);
		free(rgb);
	}
	if (line[0] == 'F')
	{
		if (texture->floor != -1)
			ft_error("floor color already set");
		rgb = scan_rgb("F", line);
		if (!ft_is_valid_rgb(rgb[0], rgb[1], rgb[2]))
			ft_error("invalid rgb color");
		texture->floor = ft_to_trgb(0, rgb[0], rgb[1], rgb[2]);
		free(rgb);
	}
}

static void	parse_texture(t_cub *cub, t_textures texture, char *line)
{
	void	*image;
	int		dir;
	int		height;
	int		width;

	height = TEX_HEIGHT;
	width = TEX_WIDTH;
	dir = dir_from_id(line);
	if (dir == -1)
		ft_error("invalid texture identifier");
	if (texture.mlx_textures[dir].img != NULL)
		ft_error("texture already set");
	line += 2;
	line = ft_strtrim(line, " \t\n");
	image = mlx_xpm_file_to_image(cub->mlx.mlx, line, &width, &height);
	if (!image)
		ft_error("texture not found");
	texture.mlx_textures[dir].img = image;
	texture.mlx_textures[dir].addr = mlx_get_data_addr(image, \
			&texture.mlx_textures[dir].bits_per_pixel, \
			&texture.mlx_textures[dir].line_length, \
			&texture.mlx_textures[dir].endian);
	if (!texture.mlx_textures[dir].addr)
		ft_error("mlx_get_data_addr failed");
	free(line);
}

static void	ft_tx_init(t_textures *textures)
{
	textures->mlx_textures = malloc(sizeof(t_mlx) * 5);
	if (!textures->mlx_textures)
		ft_error("malloc error");
	textures->ceiling = -1;
	textures->floor = -1;
	textures->mlx_textures[DIR_NORTH].img = NULL;
	textures->mlx_textures[DIR_SOUTH].img = NULL;
	textures->mlx_textures[DIR_WEST].img = NULL;
	textures->mlx_textures[DIR_EAST].img = NULL;
}

t_textures	ft_texture_parser(t_cub *cub, char *path)
{
	int			fd;
	char		*line;
	t_textures	textures;

	ft_tx_init(&textures);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("file not found");
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = ft_free_to_trim(line, " \t");
		if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E'
			|| line[0] == 'W')
			parse_texture(cub, textures, line);
		if (line[0] == 'C' || line[0] == 'F')
			parse_color(&textures, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (textures);
}
