/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:36:08 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/11/01 18:35:27 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

bool	ft_is_wall(float x, float y, t_cub *cub)
{
	char	**worldmap;

	if (!cub->map.matrix)
		ft_error("map not found");
	worldmap = cub->map.matrix;
	if (worldmap[(int)x][(int)y] == '1' || worldmap[(int)x][(int)y] == 'C')
		return (true);
	return (false);
}

static void	ft_move_up_down(int keycode, t_cub *cub)
{
	if (keycode == KEY_FORWARD)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_x * \
				(MOVE_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_x * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y + \
				cub->player.dir_y * (MOVE_SPEED + 0.1), cub))
			cub->player.pos_y += cub->player.dir_y * MOVE_SPEED;
	}
	if (keycode == KEY_BACKWARD)
	{
		if (!ft_is_wall(cub->player.pos_x - cub->player.dir_x * \
				(MOVE_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x -= cub->player.dir_x * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y - \
				cub->player.dir_y * (MOVE_SPEED + 0.1), cub))
			cub->player.pos_y -= cub->player.dir_y * MOVE_SPEED;
	}
}

static void	ft_move_left_right(int keycode, t_cub *cub)
{
	if (keycode == KEY_LEFT)
	{
		if (!ft_is_wall(cub->player.pos_x - cub->player.dir_y * \
				(MOVE_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x -= cub->player.dir_y * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y + \
				cub->player.dir_x * (MOVE_SPEED + 0.1), cub))
			cub->player.pos_y += cub->player.dir_x * MOVE_SPEED;
	}
	if (keycode == KEY_RIGHT)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_y * \
				(MOVE_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_y * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y - \
				cub->player.dir_x * (MOVE_SPEED + 0.1), cub))
			cub->player.pos_y -= cub->player.dir_x * MOVE_SPEED;
	}
}

void	ft_move_rotate(int keycode, t_cub *cub)
{
	cub->player.old_dir_x = cub->player.dir_x;
	cub->player.old_plane_x = cub->player.plane_x;
	if (keycode == KEY_ROT_LEFT)
	{
		cub->player.dir_x = cub->player.dir_x * cos(ROT_SPEED) - \
			cub->player.dir_y * sin(ROT_SPEED);
		cub->player.dir_y = cub->player.old_dir_x * sin(ROT_SPEED) + \
			cub->player.dir_y * cos(ROT_SPEED);
		cub->player.plane_x = cub->player.plane_x * cos(ROT_SPEED) - \
			cub->player.plane_y * sin(ROT_SPEED);
		cub->player.plane_y = cub->player.old_plane_x * sin(ROT_SPEED) + \
			cub->player.plane_y * cos(ROT_SPEED);
	}
	if (keycode == KEY_ROT_RIGHT)
	{
		cub->player.dir_x = cub->player.dir_x * cos(-ROT_SPEED) - \
			cub->player.dir_y * sin(-ROT_SPEED);
		cub->player.dir_y = cub->player.old_dir_x * sin(-ROT_SPEED) + \
			cub->player.dir_y * cos(-ROT_SPEED);
		cub->player.plane_x = cub->player.plane_x * cos(-ROT_SPEED) - \
			cub->player.plane_y * sin(-ROT_SPEED);
		cub->player.plane_y = cub->player.old_plane_x * sin(-ROT_SPEED) + \
			cub->player.plane_y * cos(-ROT_SPEED);
	}
}

int	ft_key_press_handler(int keycode, t_cub *cub)
{
	if (keycode == KEY_DIS_TRACK)
		cub->track_mode = !cub->track_mode;
	if (keycode == KEY_ESCAPE)
		ft_close(cub);
	if (keycode == KEY_DOOR_OPEN || keycode == KEY_DOOR_CLOSE)
		ft_interact_with_door(cub, keycode);
	ft_move_up_down(keycode, cub);
	ft_move_left_right(keycode, cub);
	ft_move_rotate(keycode, cub);
	return (0);
}
