/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_cycle_Darwin_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:17:39 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/11/01 20:55:33 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	ft_mouse_handler(t_cub *cub)
{
	int	x;
	int	y;

	if (!cub->track_mode)
	{
		mlx_mouse_show();
		return ;
	}
	mlx_mouse_hide();
	mlx_mouse_get_pos(cub->mlx.window, &x, &y);
	if (x > WIN_WIDTH / 2)
		ft_move_rotate(K_AR_R, cub);
	else if (x < WIN_WIDTH / 2)
		ft_move_rotate(K_AR_L, cub);
	mlx_mouse_move(cub->mlx.window, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}

int	ft_run_game_cycle(t_cub *cub)
{
	ft_run_sprite_cycle(cub);
	ft_mouse_handler(cub);
	ft_img_renderer(cub);
	return (0);
}
