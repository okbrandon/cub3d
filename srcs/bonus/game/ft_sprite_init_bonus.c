/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:09:04 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/11/01 18:30:41 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	ft_parse_sprite_texture(t_cub *cub, t_textures *textures, \
	char *path, int id)
{
	void	*image;
	int		height;
	int		width;

	height = SPRITE_HEIGHT;
	width = SPRITE_WIDTH;
	image = mlx_xpm_file_to_image(cub->mlx.mlx, path, &width, &height);
	if (!image)
		ft_error("door texture not found");
	textures->mlx_textures[id].img = image;
	textures->mlx_textures[id].addr = mlx_get_data_addr(image, \
			&textures->mlx_textures[id].bits_per_pixel, \
			&textures->mlx_textures[id].line_length, \
			&textures->mlx_textures[id].endian);
	if (!textures->mlx_textures[id].addr)
		ft_error("door mlx_get_data_addr failed");
}

void	ft_init_sprites_textures(t_cub *cub, t_textures *textures)
{
	ft_parse_sprite_texture(cub, textures, \
		"./textures/sprites/first-sprite.xpm", FST_SPRITE);
	ft_parse_sprite_texture(cub, textures, \
		"./textures/sprites/second-sprite.xpm", SND_SPRITE);
	ft_parse_sprite_texture(cub, textures, \
		"./textures/sprites/third-sprite.xpm", TRD_SPRITE);
	ft_parse_sprite_texture(cub, textures, \
		"./textures/sprites/fourth-sprite.xpm", FRTH_SPRITE);
	ft_parse_sprite_texture(cub, textures, \
		"./textures/sprites/fifth-sprite.xpm", FITH_SPRITE);
}

t_spritecast	ft_init_spritecast(void)
{
	t_spritecast	spritecast;

	spritecast.sprite_x = 0;
	spritecast.sprite_y = 0;
	spritecast.inv_det = 0;
	spritecast.transform_x = 0;
	spritecast.transform_y = 0;
	spritecast.screen_x = 0;
	spritecast.sprite_height = 0;
	spritecast.draw_start_y = 0;
	spritecast.draw_end_y = 0;
	spritecast.sprite_width = 0;
	spritecast.draw_start_x = 0;
	spritecast.draw_end_x = 0;
	spritecast.tex_x = 0;
	spritecast.tex_y = 0;
	spritecast.v_move_screen = 0;
	return (spritecast);
}

int	ft_run_sprite_cycle(t_cub *cub)
{
	t_textures	*textures;
	static int	frames = 0;

	textures = &cub->textures;
	if (frames < 15)
		textures->current_sprite = FST_SPRITE;
	else if (frames < 30)
		textures->current_sprite = SND_SPRITE;
	else if (frames < 45)
		textures->current_sprite = TRD_SPRITE;
	else if (frames < 60)
		textures->current_sprite = FRTH_SPRITE;
	else if (frames < 75)
		textures->current_sprite = FITH_SPRITE;
	else if (frames < 90)
		textures->current_sprite = FRTH_SPRITE;
	else if (frames < 105)
		textures->current_sprite = TRD_SPRITE;
	else if (frames < 120)
		textures->current_sprite = SND_SPRITE;
	else
		frames = 0;
	frames++;
	return (0);
}
