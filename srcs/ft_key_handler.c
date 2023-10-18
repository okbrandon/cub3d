/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:36:08 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/17 14:46:16 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_is_wall(float x, float y, t_cub *cub)
{
	char	**worldmap;

	if (!cub->map.matrix)
		ft_error("map not found");
	worldmap = cub->map.matrix;
	if (worldmap[(int)x][(int)y] == '1')
		return (TRUE);
	return (FALSE);
}

static void	ft_move_up_down(int keycode, t_cub *cub)
{
	if (keycode == KEY_FORWARD)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_x * MOVE_SPEED, \
				cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_x * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, \
				cub->player.pos_y + cub->player.dir_y * MOVE_SPEED, cub))
			cub->player.pos_y += cub->player.dir_y * MOVE_SPEED;
		printf("pos_x: %f | pos_y: %f\n", cub->player.pos_x, cub->player.pos_y);
	}
	if (keycode == KEY_BACKWARD)
	{
		if (!ft_is_wall(cub->player.pos_x - cub->player.dir_x * MOVE_SPEED, \
				cub->player.pos_y, cub))
			cub->player.pos_x -= cub->player.dir_x * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, \
				cub->player.pos_y - cub->player.dir_y * MOVE_SPEED, cub))
			cub->player.pos_y -= cub->player.dir_y * MOVE_SPEED;
		printf("pos_x: %f | pos_y: %f\n", cub->player.pos_x, cub->player.pos_y);
	}
}

static void	ft_move_left_right(int keycode, t_cub *cub)
{
	if (keycode == KEY_LEFT)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_y * MOVE_SPEED, \
				cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_y * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, \
				cub->player.pos_y - cub->player.dir_x * MOVE_SPEED, cub))
			cub->player.pos_y -= cub->player.dir_x * MOVE_SPEED;
		printf("pos_x: %f | pos_y: %f\n", cub->player.pos_x, cub->player.pos_y);
	}
	if (keycode == KEY_RIGHT)
	{
		if (!ft_is_wall(cub->player.pos_x - cub->player.dir_y * MOVE_SPEED, \
				cub->player.pos_y, cub))
			cub->player.pos_x -= cub->player.dir_y * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, \
				cub->player.pos_y + cub->player.dir_x * MOVE_SPEED, cub))
			cub->player.pos_y += cub->player.dir_x * MOVE_SPEED;
		printf("pos_x: %f | pos_y: %f\n", cub->player.pos_x, cub->player.pos_y);
	}
}

static void	ft_move_rotate(int keycode, t_cub *cub)
{
	if (keycode == KEY_ROT_LEFT)
	{
		cub->player.old_dir_x = cub->player.dir_x;
		cub->player.dir_x = cub->player.dir_x * cos(-ROT_SPEED) - \
			cub->player.dir_y * sin(-ROT_SPEED);
		cub->player.dir_y = cub->player.old_dir_x * sin(-ROT_SPEED) + \
			cub->player.dir_y * cos(-ROT_SPEED);
		cub->player.old_plane_x = cub->player.plane_x;
		cub->player.plane_x = cub->player.plane_x * cos(-ROT_SPEED) - \
			cub->player.plane_y * sin(-ROT_SPEED);
		cub->player.plane_y = cub->player.old_plane_x * sin(-ROT_SPEED) + \
			cub->player.plane_y * cos(-ROT_SPEED);
		printf("dir_x: %f | dir_y: %f\n", cub->player.dir_x, cub->player.dir_y);
	}
	if (keycode == KEY_ROT_RIGHT)
	{
		cub->player.old_dir_x = cub->player.dir_x;
		cub->player.dir_x = cub->player.dir_x * cos(MOVE_SPEED) - \
			cub->player.dir_y * sin(MOVE_SPEED);
		cub->player.dir_y = cub->player.old_dir_x * sin(MOVE_SPEED) + \
			cub->player.dir_y * cos(MOVE_SPEED);
		cub->player.old_plane_x = cub->player.plane_x;
		cub->player.plane_x = cub->player.plane_x * cos(MOVE_SPEED) - \
			cub->player.plane_y * sin(MOVE_SPEED);
		cub->player.plane_y = cub->player.old_plane_x * sin(MOVE_SPEED) + \
			cub->player.plane_y * cos(MOVE_SPEED);
		printf("dir_x: %f | dir_y: %f\n", cub->player.dir_x, cub->player.dir_y);
	}
}

int	ft_key_press_handler(int keycode, t_cub *cub)
{
	if (keycode == KEY_ESCAPE)
		ft_close(cub);
	ft_move_up_down(keycode, cub);
	ft_move_left_right(keycode, cub);
	ft_move_rotate(keycode, cub);
	ft_img_renderer(cub);
	return (0);
}
