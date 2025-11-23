/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:21:11 by berrabia          #+#    #+#             */
/*   Updated: 2025/11/05 17:21:13 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *rest)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	j = 0;
	if (!rest)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = rest[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *rest)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\0')
		return (NULL);
	i++;
	j = i;
	while (rest[i])
		i++;
	if (i == j)
		return (NULL);
	res = malloc(i - j + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (rest[j])
		res[i++] = rest[j++];
	res[i] = '\0';
	return (res);
}

char	*main_loop(int fd, char *rest)
{
	char	*tmp;
	int		bytes;
	char	*buffer;

	bytes = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes > 0 && not_a_newline(rest))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		tmp = rest;
		rest = ft_strjoin(rest, buffer);
		free(tmp);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = main_loop(fd, rest);
	if (!rest || !*rest)
		return (free(rest), NULL);
	line = get_line(rest);
	tmp = rest;
	rest = get_rest(rest);
	free(tmp);
	return (line);
}
// # include <fcntl.h>
// # include <stdio.h>

// int	main(void)
// {
//  	char	*line;

//  	line = get_next_line(0);
// 	printf("%s",line);
// 	free(line);
// }
