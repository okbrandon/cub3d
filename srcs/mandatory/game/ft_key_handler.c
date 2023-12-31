/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:36:08 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/11/01 20:32:12 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	ft_is_wall(float x, float y, t_cub *cub)
{
	char	**worldmap;

	if (!cub->map.matrix)
		ft_error("map not found");
	worldmap = cub->map.matrix;
	if (worldmap[(int)x][(int)y] == '1')
		return (true);
	return (false);
}

static void	ft_move_up_down(int keycode, t_cub *cub)
{
	if (keycode == K_W)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_x * \
				(MOVE_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_x * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y + \
				cub->player.dir_y * (MOVE_SPEED + 0.1), cub))
			cub->player.pos_y += cub->player.dir_y * MOVE_SPEED;
	}
	if (keycode == K_S)
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
	if (keycode == K_A)
	{
		if (!ft_is_wall(cub->player.pos_x - cub->player.dir_y * \
				(MOVE_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x -= cub->player.dir_y * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y + \
				cub->player.dir_x * (MOVE_SPEED + 0.1), cub))
			cub->player.pos_y += cub->player.dir_x * MOVE_SPEED;
	}
	if (keycode == K_D)
	{
		if (!ft_is_wall(cub->player.pos_x + cub->player.dir_y * \
				(MOVE_SPEED + 0.1), cub->player.pos_y, cub))
			cub->player.pos_x += cub->player.dir_y * MOVE_SPEED;
		if (!ft_is_wall(cub->player.pos_x, cub->player.pos_y - \
				cub->player.dir_x * (MOVE_SPEED + 0.1), cub))
			cub->player.pos_y -= cub->player.dir_x * MOVE_SPEED;
	}
}

static void	ft_move_rotate(int keycode, t_cub *cub)
{
	cub->player.old_dir_x = cub->player.dir_x;
	cub->player.old_plane_x = cub->player.plane_x;
	if (keycode == K_AR_L)
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
	if (keycode == K_AR_R)
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
	if (keycode == K_ESC)
		ft_close(cub);
	ft_move_up_down(keycode, cub);
	ft_move_left_right(keycode, cub);
	ft_move_rotate(keycode, cub);
	ft_img_renderer(cub);
	return (0);
}
