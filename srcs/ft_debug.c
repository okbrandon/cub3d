/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:15:39 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/26 19:01:10 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map_matrix(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		printf("%s\n", map.matrix[i]);
		i++;
	}
}
