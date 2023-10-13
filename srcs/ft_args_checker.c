/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:03:18 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/10/13 19:05:40 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*ft_get_file_extension(char *filename)
{
	int		length;
	int		i;

	if (!filename)
		return (NULL);
	length = ft_strlen(filename);
	i = length - 1;
	while (i >= 0 && filename[i] != '.' \
		&& filename[i] != '/' && filename[i] != '\\')
		i--;
	if (i > 0 && filename[i] == '.' \
		&& filename[i - 1] != '/' && filename[i - 1] != '\\')
		return (filename + i);
	else
		return (filename + length);
}

void	ft_check_args(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		ft_error("invalid file input");
	if (ft_strncmp(ft_get_file_extension(argv[1]), ".cub", ft_strlen(argv[1])))
		ft_error("invalid file extension");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(strerror(errno));
	close(fd);
}