/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findsegment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:55:59 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/20 00:23:37 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findquarter_original(int *array, int size, int i)
{
	return (array[((size / 7) * i)] - 1);
}

static int	crudesort(int ***sorted, int i)
{
	int	temp;

	temp = 0;
	if ((**sorted)[i] <= (**sorted)[i + 1])
		i++;
	else
	{
		temp = (**sorted)[i];
		(**sorted)[i] = (**sorted)[i + 1];
		(**sorted)[i + 1] = temp;
		i = 0;
	}
	return (i);
}

int	ft_sortarray_original(t_stack *lst, int **sorted, int size)
{
	int	i;

	i = 0;
	size = ft_stacksize(lst);
	while (i < size)
	{
		(*sorted)[i] = lst->data;
		lst = lst->next;
		i++;
	}
	i = 0;
	while (i < size - 1)
		i = crudesort(&sorted, i);
	return (i);
}
