/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:39:02 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/20 00:29:34 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_ordercheck(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->data > lst->next->data)
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}

int	ft_isbiggest(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = lst->data;
	while (lst)
	{
		if (lst->data > i)
			i = lst->data;
		lst = lst->next;
	}
	return (i);
}

int	ft_issmallest(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = lst->data;
	while (lst)
	{
		if (lst->data < i)
			i = lst->data;
		lst = lst->next;
	}
	return (i);
}

void	freeall(t_stack **sahead)
{
	t_stack	*temp;

	while (*sahead)
	{
		temp = (*sahead)->next;
		free(*sahead);
		*sahead = temp;
	}
}
