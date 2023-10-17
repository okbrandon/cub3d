/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:01:19 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/17 14:30:42 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub		*cub;

	ft_check_args(argc, argv);
	cub = ft_init_cub(argv[1]);
	ft_img_renderer(cub);
	mlx_hook(cub->mlx.window, 2, 1L << 0, ft_key_press_handler, cub);
	mlx_hook(cub->mlx.window, 17, 1L << 17, ft_close, cub);
	mlx_loop(cub->mlx.mlx);
	return (0);
}
