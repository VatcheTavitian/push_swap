/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findindex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:24:23 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/20 00:29:30 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sortarrayforindex(int **sortthis, int size)
{
	int	i;
	int	temp;
	int	*sorted;

	sorted = *sortthis;
	i = 0;
	temp = 0;
	while (i < size - 1)
	{
		if (sorted[i] <= sorted[i + 1])
			i++;
		else
		{
			temp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = temp;
			i = 0;
		}
	}
}

int	findidxpos(t_stack *ls, int max)
{
	int	i;

	i = 1;
	if (ft_stacksize(ls) > 1)
	{
		while (max != ls->idx && i <= ft_stacksize(ls))
		{
			i++;
			ls = ls->next;
		}
	}
	return (i);
}

int	findpos(t_stack *ls, int num)
{
	int	i;

	i = 1;
	while (num != ls->data && i <= ft_stacksize(ls))
	{
		i++;
		ls = ls->next;
	}
	return (i);
}

int	ft_getindex(int *sorted, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	*ft_sortcomplete(t_stack *lst)
{
	int	size;
	int	*sorted;
	int	i;
	int	size_backup;

	i = 0;
	size = ft_stacksize(lst);
	size_backup = size;
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (0);
	while (i < size)
	{
		sorted[i] = lst->data;
		lst = lst->next;
		i++;
	}
	ft_sortarrayforindex(&sorted, size_backup);
	return (sorted);
}
