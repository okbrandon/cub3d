/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmorvan <evmorvan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:44:26 by evmorvan          #+#    #+#             */
/*   Updated: 2023/10/26 19:05:03 by evmorvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	*scan_rgb(char *identifier, char *line)
{
	int		*rgb;
	char	**rgb_str;

	rgb = malloc(sizeof(int) * 3);
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, identifier, ft_strlen(identifier)))
		ft_error("rgb format error");
	line += ft_strlen(identifier);
	while (*line == ' ')
		line++;
	rgb_str = ft_split(line, ',');
	if (ft_strslen(rgb_str) != 3)
		ft_error("rgb format error");
	if (!ft_is_str_digit(rgb_str[0]) || !ft_is_str_digit(rgb_str[1])
		|| !ft_is_str_digit(rgb_str[2]))
	{
		ft_error("rgb must be digit");
	}
	rgb[0] = ft_atoi(rgb_str[0]);
	rgb[1] = ft_atoi(rgb_str[1]);
	rgb[2] = ft_atoi(rgb_str[2]);
	ft_free_strs(rgb_str);
	return (rgb);
}
