/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:56:53 by vtavitia          #+#    #+#             */
/*   Updated: 2023/03/28 18:10:12 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sublen(char *to_find)
{
	size_t	len;

	len = 0;
	while (to_find[len] != '\0')
	{
		len++;
	}
	return (len);
}

static char	*checkmatches(char *str, char *to_find, size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0' && i < length)
	{
		j = 0;
		while (to_find[j] != '\0' )
		{
			if (str[i + j] != to_find[j] || i + j >= length)
			{
				break ;
			}
			if (j == sublen(to_find) - (size_t)1)
			{
				return (&str[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *hayt_stack, const char *needle, size_t len)
{
	size_t	i;
	char	*hayt_stack1;
	char	*needle1;

	i = 0;
	hayt_stack1 = (char *)hayt_stack;
	needle1 = (char *)needle;
	if (needle1[i] == '\0')
	{
		return (hayt_stack1);
	}
	return (checkmatches(hayt_stack1, needle1, len));
}
