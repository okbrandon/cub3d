/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spritecaster_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:04:09 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/31 20:23:25 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	ft_transform_sprite(t_cub *cub, int sprite)
{
	t_spritecast	*cast;

	cast = &cub->spritecast;
	cast->sprite_x = cub->map.sprites[sprite].pos.x - cub->player.pos_x;
	cast->sprite_y = cub->map.sprites[sprite].pos.y - cub->player.pos_y;
	cast->inv_det = 1.0 / (cub->player.plane_x * cub->player.dir_y - \
	cub->player.dir_x * cub->player.plane_y);
	cast->transform_x = cast->inv_det * (cub->player.dir_y * \
		cast->sprite_x - cub->player.dir_x * cast->sprite_y);
	cast->transform_y = cast->inv_det * (-cub->player.plane_y * \
		cast->sprite_x + cub->player.plane_x * cast->sprite_y);
	cast->screen_x = (int)((WIN_WIDTH / 2) * (1 + \
		cast->transform_x / cast->transform_y));
}

static void	ft_calc_width_height(t_cub *cub)
{
	t_spritecast	*cast;

	cast = &cub->spritecast;
	cast->v_move_screen = (int)(V_MOVE / cast->transform_y);
	cast->sprite_height = ft_abs((int)(WIN_HEIGHT / (cast->transform_y))) \
		/ V_DIV;
	cast->draw_start_y = -cast->sprite_height / 2 + WIN_HEIGHT / 2 + \
		(int)(cast->v_move_screen / cast->transform_y);
	if (cast->draw_start_y < 0)
		cast->draw_start_y = 0;
	cast->draw_end_y = cast->sprite_height / 2 + WIN_HEIGHT / 2 + \
		(int)(cast->v_move_screen / cast->transform_y);
	if (cast->draw_end_y >= WIN_HEIGHT)
		cast->draw_end_y = WIN_HEIGHT - 1;
	cast->sprite_width = ft_abs((int)(WIN_HEIGHT / (cast->transform_y))) \
		/ U_DIV;
	cast->draw_start_x = -cast->sprite_width / 2 + cast->screen_x;
	if (cast->draw_start_x < 0)
		cast->draw_start_x = 0;
	cast->draw_end_x = cast->sprite_width / 2 + cast->screen_x;
	if (cast->draw_end_x >= WIN_WIDTH)
		cast->draw_end_x = WIN_WIDTH - 1;
}

static void	ft_draw_sprites(t_cub *cub)
{
	t_spritecast	*cast;
	int				stripe;
	int				d;
	int				y;

	cast = &cub->spritecast;
	stripe = cast->draw_start_x - 1;
	while (++stripe < cast->draw_end_x)
	{
		y = cast->draw_start_y - 1;
		cast->tex_x = (int)(256 * (stripe - (-cast->sprite_width / 2 + \
			cast->screen_x)) * SPRITE_WIDTH / cast->sprite_width) / 256;
		if (cast->transform_y > 0 && stripe > 0 && stripe < WIN_WIDTH && \
			cast->transform_y < cub->raycast.z_buffer[stripe])
		{
			while (++y < cast->draw_end_y)
			{
				d = (y - (int)(cast->v_move_screen / cast->transform_y)) * 256 \
					- WIN_HEIGHT * 128 + cast->sprite_height * 128;
				cast->tex_y = ((d * SPRITE_HEIGHT) / cast->sprite_height) / 256;
				ft_apply_sprite_texture(cub, cub->textures.current_sprite, \
					stripe, y);
			}
		}
	}
}

void	ft_spritecast(t_cub *cub)
{
	int		i;

	i = -1;
	ft_sort_sprites_by_dist(cub);
	while (++i < cub->map.sprites_count)
	{
		ft_transform_sprite(cub, i);
		ft_calc_width_height(cub);
		ft_draw_sprites(cub);
	}
}
