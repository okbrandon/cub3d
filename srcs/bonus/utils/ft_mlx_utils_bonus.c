/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:25:16 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/28 14:52:48 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = cub->mlx.addr + (y * cub->mlx.line_length + x
			* (cub->mlx.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_to_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_get_pixel_color(t_mlx *mlx, int x, int y)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x
			* (mlx->bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}

int	ft_img_renderer(t_cub *cub)
{
	t_mlx	*mlx;

	mlx = &cub->mlx;
	mlx_clear_window(mlx->mlx, mlx->window);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	ft_raycast(cub);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}
