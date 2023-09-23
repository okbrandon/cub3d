/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:54:04 by bsoubaig          #+#    #+#             */
/*   Updated: 2023/01/31 12:47:37 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

/**
 * @brief Parses the line from the buffer
 * Include the newline character if it exists
 * 
 * @param str 		- The line from the buffer
 * @return char* 	- The line with or without the newline
 */
char	*ft_parse_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			line[i] = str[i];
			i++;
			break ;
		}
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/**
 * @brief Treats the next line from the buffer
 * Allocates memory for the next line by removing the current line's length
 * 
 * @param str 		- The current line from the buffer
 * @return char* 	- The next line
 */
char	*ft_treat_next_line(char *str)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	next_line = (char *) malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	while (str[i])
		next_line[j++] = str[i++];
	next_line[j] = '\0';
	free(str);
	return (next_line);
}

/**
 * @brief Reads the file and stores it in a buffer
 * Loop until a newline is found or the end of the file is reached
 * 
 * @param fd 		- The file descriptor
 * @param str 		- The current line in the buffer
 * @return char* 	- The next line with the read data
 */
char	*ft_parse(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		if (ft_strchr_fork(str, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str = ft_free_to_join(str, buffer);
	}
	free(buffer);
	return (str);
}

/**
 * @brief The main function that can read multiple file descriptors
 * and store them in different buffers
 * 
 * @param fd 		- The file descriptor
 * @return char* 	- The next line read
 */
char	*get_next_line(int fd)
{
	static char	*str[1025];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (str[fd])
			free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_parse(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_parse_line(str[fd]);
	str[fd] = ft_treat_next_line(str[fd]);
	return (line);
}
