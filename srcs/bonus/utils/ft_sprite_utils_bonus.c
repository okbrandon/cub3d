/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:34:31 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/31 19:42:08 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	ft_alloc_sprites_array(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->sprites_count = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->matrix[i][j] == 'X')
				map->sprites_count++;
		}
	}
	map->sprites = ft_calloc(map->sprites_count, sizeof(t_sprite));
	if (!map->sprites)
		ft_error("malloc error");
}

static void	ft_calc_sprite_dist(t_map *map, t_player player)
{
	int	i;

	i = -1;
	while (++i < map->sprites_count)
	{
		map->sprites[i].dist = (player.pos_x - map->sprites[i].pos.x) * \
			(player.pos_x - map->sprites[i].pos.x) + \
			(player.pos_y - map->sprites[i].pos.y) * \
			(player.pos_y - map->sprites[i].pos.y);
	}
}

void	ft_sort_sprites_by_dist(t_cub *cub)
{
	int			i;
	int			j;
	t_sprite	tmp;

	ft_calc_sprite_dist(&cub->map, cub->player);
	i = -1;
	while (++i < cub->map.sprites_count)
	{
		j = -1;
		while (++j < cub->map.sprites_count - 1)
		{
			if (cub->map.sprites[j].dist < cub->map.sprites[j + 1].dist)
			{
				tmp = cub->map.sprites[j];
				cub->map.sprites[j] = cub->map.sprites[j + 1];
				cub->map.sprites[j + 1] = tmp;
			}
		}
	}
}

void	ft_find_sprites(t_map *map)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	x = 0;
	ft_alloc_sprites_array(map);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->matrix[i][j] == 'X')
			{
				map->sprites[x].pos.x = i;
				map->sprites[x].pos.y = j;
				x++;
			}
		}
	}
}

void	ft_apply_sprite_texture(t_cub *cub, int direction, int x, int y)
{
	int	color;

	color = ft_get_pixel_color(&cub->textures.mlx_textures[direction], \
		cub->spritecast.tex_x, cub->spritecast.tex_y);
	if ((color & 0x00FFFFFF) != 0)
		ft_mlx_pixel_put(cub, x, y, color);
}
