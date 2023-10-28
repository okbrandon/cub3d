/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:33:13 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/28 10:46:02 by bsoubaig         ###   ########.fr       */
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
	ft_printf("%s%s%sError%s\n%s\n", \
		RESET, RED, BOLD, RESET, message);
	exit(EXIT_FAILURE);
}

char	**ft_strsjoin(char **strs, char *str)
{
	int		i;
	char	**new_strs;

	i = 0;
	new_strs = malloc(sizeof(char *) * (ft_strslen(strs) + 2));
	if (!new_strs)
		ft_error("malloc error");
	while (strs[i])
	{
		new_strs[i] = strs[i];
		i++;
	}
	new_strs[i] = str;
	new_strs[i + 1] = NULL;
	free(strs);
	return (new_strs);
}

bool	ft_is_valid_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (false);
	if (g < 0 || g > 255)
		return (false);
	if (b < 0 || b > 255)
		return (false);
	return (true);
}

int	dir_from_id(char *identifier)
{
	if (ft_strncmp(identifier, "NO ", 3) == 0)
		return (DIR_NORTH);
	if (ft_strncmp(identifier, "SO ", 3) == 0)
		return (DIR_SOUTH);
	if (ft_strncmp(identifier, "WE ", 3) == 0)
		return (DIR_WEST);
	if (ft_strncmp(identifier, "EA ", 3) == 0)
		return (DIR_EAST);
	return (-1);
}
