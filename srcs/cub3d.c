/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:01:19 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/09/23 15:28:57 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	worldMap[MAP_WIDTH][MAP_HEIGHT] = 
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = cub->addr + (y * cub->line_length + x * (cub->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_to_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_color_from_map(int x, int y) {
	int	color;

	if (worldMap[x][y] == 1)
		color = ft_to_trgb(0, 255, 0, 0);
	else if (worldMap[x][y] == 2)
		color = ft_to_trgb(0, 0, 255, 0);
	else if (worldMap[x][y] == 3)
		color = ft_to_trgb(0, 0, 0, 255);
	else if (worldMap[x][y] == 4)
		color = ft_to_trgb(0, 255, 255, 255);
	else
		color = ft_to_trgb(0, 0, 0, 0);
	return (color);
}

void	ft_draw_vertical_line(t_cub *cub, int x, int drawStart, int drawEnd, int color)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < drawStart)
			ft_mlx_pixel_put(cub, x, y, ft_to_trgb(0, 0, 0, 0));
		else if (y >= drawStart && y <= drawEnd)
			ft_mlx_pixel_put(cub, x, y, color);
		else
			ft_mlx_pixel_put(cub, x, y, ft_to_trgb(0, 0, 0, 0));
		y++;
	}
}

void	ft_draw(t_cub *cub) {
	int		x;
	int		wallHit;
	int		sideWallHit;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;

	x = -1;
	while (++x < WIN_WIDTH) {
		rayDirX = cub->player.dirX + cub->player.planeX * (2 * x / (double)WIN_WIDTH - 1);
		rayDirY = cub->player.dirY + cub->player.planeY * (2 * x / (double)WIN_WIDTH - 1);
		mapX = (int) cub->player.posX;
		mapY = (int) cub->player.posY;
		deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1 / rayDirY);

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cub->player.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cub->player.posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cub->player.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cub->player.posY) * deltaDistY;
		}
		wallHit = 0;
		while (wallHit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				sideWallHit = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				sideWallHit = 1;
			}
			if(worldMap[mapX][mapY] > 0)
				wallHit = 1;
		}
		if (sideWallHit == 0)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;
		lineHeight = (int)(WIN_HEIGHT / perpWallDist);
		drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;
		if (sideWallHit == 1)
			ft_draw_vertical_line(cub, x, drawStart, drawEnd, ft_color_from_map(mapX, mapY));
		else
			ft_draw_vertical_line(cub, x, drawStart, drawEnd, ft_color_from_map(mapX, mapY));
	}
}

int	ft_img_renderer(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->window);
	mlx_destroy_image(cub->mlx, cub->img);
	cub->img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel,
			&cub->line_length, &cub->endian);
	ft_draw(cub);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->img, 0, 0);
	return (0);
}

// int	is_valid_pos_in_map(t_cub *cub, double x, double y)
// {
// 	if (x < 0.25 || x >= data->mapinfo.width - 1.25)
// 		return (false);
// 	if (y < 0.25 || y >= data->mapinfo.height -0.25)
// 		return (false);
// 	return (true);
// }

int	ft_key_handler(int keycode, t_cub *cub)
{
	double	oldDirX;
	double	oldPlaneX;

	if (keycode == KEY_FORWARD) {
		if (worldMap[(int) (cub->player.posX + cub->player.dirX * MOVE_SPEED)][(int) (cub->player.posY)] == 0)
			cub->player.posX += cub->player.dirX * MOVE_SPEED;
		if (worldMap[(int) (cub->player.posX)][(int) (cub->player.posY + cub->player.dirY * MOVE_SPEED)] == 0)
			cub->player.posY += cub->player.dirY * MOVE_SPEED;
	}
	if (keycode == KEY_BACKWARD) {
		if (worldMap[(int) (cub->player.posX - cub->player.dirX * MOVE_SPEED)][(int) (cub->player.posY)] == 0)
			cub->player.posX -= cub->player.dirX * MOVE_SPEED;
		if (worldMap[(int) (cub->player.posX)][(int) (cub->player.posY - cub->player.dirY * MOVE_SPEED)] == 0)
			cub->player.posY -= cub->player.dirY * MOVE_SPEED;
	}
	if (keycode == KEY_LEFT) {
		if (worldMap[(int) (cub->player.posX - cub->player.dirY * MOVE_SPEED)][(int) (cub->player.posY)] == 0)
			cub->player.posX -= cub->player.dirY * MOVE_SPEED;
		if (worldMap[(int) (cub->player.posX)][(int) (cub->player.posY + cub->player.dirX * MOVE_SPEED)] == 0)
			cub->player.posY += cub->player.dirX * MOVE_SPEED;
	}
	if (keycode == KEY_RIGHT) {
		if (worldMap[(int) (cub->player.posX + cub->player.dirY * MOVE_SPEED)][(int) (cub->player.posY)] == 0)
			cub->player.posX += cub->player.dirY * MOVE_SPEED;
		if (worldMap[(int) (cub->player.posX)][(int) (cub->player.posY - cub->player.dirX * MOVE_SPEED)] == 0)
			cub->player.posY -= cub->player.dirX * MOVE_SPEED;
	}
	if (keycode == KEY_ROT_LEFT) {
		oldDirX = cub->player.dirX;
		cub->player.dirX = cub->player.dirX * cos(MOVE_SPEED) - cub->player.dirY * sin(MOVE_SPEED);
		cub->player.dirY = oldDirX * sin(MOVE_SPEED) + cub->player.dirY * cos(MOVE_SPEED);
		oldPlaneX = cub->player.planeX;
		cub->player.planeX = cub->player.planeX * cos(MOVE_SPEED) - cub->player.planeY * sin(MOVE_SPEED);
		cub->player.planeY = oldPlaneX * sin(MOVE_SPEED) + cub->player.planeY * cos(MOVE_SPEED);
	}
	if (keycode == KEY_ROT_RIGHT) {
		oldDirX = cub->player.dirX;
		cub->player.dirX = cub->player.dirX * cos(-ROT_SPEED) - cub->player.dirY * sin(-ROT_SPEED);
		cub->player.dirY = oldDirX * sin(-ROT_SPEED) + cub->player.dirY * cos(-ROT_SPEED);
		oldPlaneX = cub->player.planeX;
		cub->player.planeX = cub->player.planeX * cos(-ROT_SPEED) - cub->player.planeY * sin(-ROT_SPEED);
		cub->player.planeY = oldPlaneX * sin(-ROT_SPEED) + cub->player.planeY * cos(-ROT_SPEED);
	}
	ft_img_renderer(cub);
	return (0);
}


int	main(void) {
	t_cub		*cub;
	t_player	player;

	/* Player init */
	player.posX = 22;
	player.posY = 12;
	player.dirX = -1;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = 0.66;
	/* Cub init */
	cub = ft_calloc(1, sizeof(t_cub));
	cub->mlx = mlx_init();
	cub->window = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	cub->img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel,
			&cub->line_length, &cub->endian);
	cub->player = player;
	ft_img_renderer(cub);
	mlx_hook(cub->window, 2, 1L << 0, ft_key_handler, cub);
	mlx_loop(cub->mlx);
	return (0);
}