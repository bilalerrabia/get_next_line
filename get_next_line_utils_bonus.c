/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berrabia <berrabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:54:27 by berrabia          #+#    #+#             */
/*   Updated: 2025/11/05 17:54:30 by berrabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*rest;
	int		total_len;

	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	rest = malloc(total_len + 1);
	if (!rest)
		return (NULL);
	if (s1)
		while (s1[i])
			rest[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i])
			rest[j++] = s2[i++];
	rest[j] = '\0';
	return (rest);
}

int	not_a_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
		if (s[i++] == '\n')
			return (0);
	return (1);
}
