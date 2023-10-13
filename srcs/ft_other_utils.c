/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:33:13 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/14 11:13:03 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_error(char *message)
{
	ft_printf("%s%s%sAn error occurred: %s%s\n", \
		RESET, RED, BOLD, RESET, message);
	exit(EXIT_FAILURE);
}

int	ft_close(t_cub *cub)
{
	if (!cub)
		return (1);
	if (cub->mlx.window)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.window);
	if (cub->mlx.img)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	exit(EXIT_SUCCESS);
	return (0);
}
