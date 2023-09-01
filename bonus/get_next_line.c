/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:46:29 by vatche            #+#    #+#             */
/*   Updated: 2023/09/01 19:16:50 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*ft_processcache(char *cache)
{
	char	*newcache;
	int		i;
	int		n;

	i = 0;
	while (cache[i] != '\n' && cache[i] != '\0')
		i++;
	if (!cache[i])
	{
		free(cache);
		return (NULL);
	}
	newcache = malloc(sizeof(char) * (ft_strlenmod(cache) - i + 1));
	i++;
	n = 0;
	while (cache[i])
		newcache[n++] = cache[i++];
	newcache[n] = '\0';
	free (cache);
	if (ft_strlenmod(newcache) == 0 && newcache != NULL)
	{
		free (newcache);
		return (NULL);
	}
	return (newcache);
}

char	*ft_getline(char *cache)
{
	char	*line;
	int		i;

	i = 0;
	if (!cache[i])
		return (NULL);
	while (cache[i] != '\n' && cache[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (cache[i] != '\n' && cache[i])
	{
		line[i] = cache[i];
		i++;
	}
	if (cache[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_readfile(int fd, char *cache)
{
	int		text;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	text = 1;
	while (!ft_strchrmod(cache, '\n') && text != 0)
	{
		text = read(fd, buffer, BUFFER_SIZE);
		if (text == -1)
		{
			free(buffer);
			free(cache);
			return (NULL);
		}
		buffer[text] = '\0';
		if (ft_strlenmod(buffer) != 0)
			cache = ft_strjoingnl(cache, buffer);
	}
	free (buffer);
	return (cache);
}

char	*get_next_line(int fd, t_stack **sahead, t_stack **sbhead)
{
	static char	*cache;
	char		*line;
	int			readsize;

	readsize = 1;
	if (fd < 0 || readsize <= 0)
		return (NULL);
	cache = ft_readfile(fd, cache);
	if (!cache)
		return (NULL);
	if (cache)
		line = ft_getline(cache);
	if (ft_strlenmod(line) == 0)
	{
		free (line);
		return (NULL);
	}
	if (ft_strlenmod(cache) != 0)
		cache = ft_processcache(cache);
	if (ft_strlenmod(cache) == 0 && cache != NULL)
		free (cache);
	ft_docommand1(line, sahead, sbhead);
	return (line);
}
