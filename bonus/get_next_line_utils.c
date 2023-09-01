/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:47:13 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/22 13:15:24 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*ft_strchrmod(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	if (!s1)
		return (NULL);
	if (c == '\0')
		return (&(s1[ft_strlen(s1)]));
	while (s1[i] != '\0')
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlenmod(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	return (len);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	char		*join;
	size_t		i;
	size_t		k;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * ((ft_strlenmod(s1) + ft_strlenmod(s2) + 1)));
	if (!join)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i] != '\0')
			join[i] = s1[i];
	k = -1;
	while (s2[++k] != '\0')
		join[i++] = s2[k];
	join[i] = '\0';
	free (s1);
	return (join);
}
