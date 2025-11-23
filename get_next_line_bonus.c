/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:54:43 by berrabia          #+#    #+#             */
/*   Updated: 2025/11/05 17:54:45 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (j < i)
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
	static char	*rest[1024];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = main_loop(fd, rest[fd]);
	if (!(rest[fd]) || !*(rest[fd]))
		return (free(rest[fd]), NULL);
	line = get_line(rest[fd]);
	tmp = rest[fd];
	rest[fd] = get_rest(rest[fd]);
	free(tmp);
	return (line);
}

// # include <fcntl.h>
// # include <stdio.h>

// int	main(void)
// {
// int	fd1, fd2;
// char	*line;
// int fd;
// int i;

// i = 0;
// fd1 = open("bilal.txt", O_RDONLY);
// fd2 = open("yahya.txt", O_RDONLY);

// printf("%d\n", fd1);
// printf("%d\n", fd2);
// fd = (i % 2 == 0)?fd1:fd2;
// while ((line = get_next_line(fd)))
// {
// 	printf("%s", line);
// 	free(line);
// 	fd = (i % 2 == 1)?fd1:fd2;
// 	i++;
// }
// close(fd1);
// close(fd2);

// line = get_next_line(0);
// printf("%s",line);
// free(line);
// }
