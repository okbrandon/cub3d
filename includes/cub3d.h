/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:02:20 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/09/23 15:25:02 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>

# define RED 			"\033[0;31m"
# define PURPLE 		"\033[38;5;141m"
# define GREY 			"\033[38;5;240m"
# define GREEN 			"\033[38;5;46m"
# define RESET 			"\033[0m"
# define BOLD 			"\033[1m"

# define WIN_WIDTH		1280
# define WIN_HEIGHT		720
# define MAP_WIDTH		24
# define MAP_HEIGHT		24

# define KEY_FORWARD	13
# define KEY_BACKWARD	1
# define KEY_LEFT		0
# define KEY_RIGHT		2
# define KEY_ROT_LEFT	123
# define KEY_ROT_RIGHT	124

# define MOVE_SPEED		0.125
# define ROT_SPEED		0.075

typedef struct s_player
{
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
}				t_player;

typedef struct s_cub
{
	void			*mlx;
	void			*window;
	char			*addr;
	void			*img;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_player		player;
}				t_cub;

#endif