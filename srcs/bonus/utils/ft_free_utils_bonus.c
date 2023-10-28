/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:30:52 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/28 14:53:00 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_free_map(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->map.height)
		free(cub->map.matrix[i]);
	free(cub->map.matrix);
}

void	ft_free_textures(t_cub *cub)
{
	if (!cub->textures.mlx_textures)
		return ;
	if (cub->textures.mlx_textures[DIR_NORTH].img)
		mlx_destroy_image(cub->mlx.mlx,
			cub->textures.mlx_textures[DIR_NORTH].img);
	if (cub->textures.mlx_textures[DIR_SOUTH].img)
		mlx_destroy_image(cub->mlx.mlx,
			cub->textures.mlx_textures[DIR_SOUTH].img);
	if (cub->textures.mlx_textures[DIR_EAST].img)
		mlx_destroy_image(cub->mlx.mlx,
			cub->textures.mlx_textures[DIR_EAST].img);
	if (cub->textures.mlx_textures[DIR_WEST].img)
		mlx_destroy_image(cub->mlx.mlx,
			cub->textures.mlx_textures[DIR_WEST].img);
	free(cub->textures.mlx_textures);
}

int	ft_close(t_cub *cub)
{
	if (!cub)
		return (1);
	if (cub->mlx.window)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.window);
	if (cub->mlx.img)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	ft_free_map(cub);
	ft_free_textures(cub);
	exit(EXIT_SUCCESS);
	return (0);
}
