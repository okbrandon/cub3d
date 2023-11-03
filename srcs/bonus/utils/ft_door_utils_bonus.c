/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:05:33 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/11/03 18:19:44 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static t_vector	ft_get_door_at_direction(t_cub *cub)
{
	t_vector	door;
	int			x;
	int			y;
	char		**map;

	map = cub->map.matrix;
	door.x = -1;
	door.y = -1;
	x = -1;
	while (++x < cub->map.height)
	{
		y = -1;
		while (++y < cub->map.width)
		{
			if ((map[x][y] == 'C' || map[x][y] == 'O') && \
				ft_abs(cub->player.pos_x - x) <= 1.85 && \
				ft_abs(cub->player.pos_y - y) <= 1.85)
			{
				door.x = x;
				door.y = y;
				return (door);
			}
		}
	}
	return (door);
}

static float	ft_get_dist_from_door(t_cub *cub, t_vector door)
{
	float	dist;
	float	player_x;
	float	player_y;

	player_x = cub->player.pos_x;
	player_y = cub->player.pos_y;
	dist = sqrt(pow(player_x - door.x, 2) + pow(player_y - door.y, 2));
	return (dist);
}

void	ft_interact_with_door(t_cub *cub, int keycode)
{
	t_vector	door;
	float		dist;

	door = ft_get_door_at_direction(cub);
	if (door.x != -1 && door.y != -1)
	{
		dist = ft_get_dist_from_door(cub, door);
		if (dist <= 1.85)
		{
			if (keycode == K_O && \
					cub->map.matrix[(int)door.x][(int)door.y] == 'C')
				cub->map.matrix[(int)door.x][(int)door.y] = 'O';
			if (keycode == K_C && \
					cub->map.matrix[(int)door.x][(int)door.y] == 'O')
				cub->map.matrix[(int)door.x][(int)door.y] = 'C';
		}
	}
}
