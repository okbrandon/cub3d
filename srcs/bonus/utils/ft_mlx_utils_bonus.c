/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:25:16 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/30 22:27:43 by evmorvan         ###   ########.fr       */
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

void	ft_draw_minimap(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < ft_strlen(cub->map.matrix[i]))
		{
			if (cub->map.matrix[i][j] == '1')
				ft_draw_square(cub, j * MINIMAP_MULT + 10, i * MINIMAP_MULT \
					+ 10, 0x000000);
			j++;
		}
		i++;
	}
	ft_draw_square(cub, (int) cub->player.pos_y * MINIMAP_MULT + 10,
		(int) cub->player.pos_x * MINIMAP_MULT + 10, MINIMAP_MULT, 0xFF0000);
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
	ft_draw_minimap(cub);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}
