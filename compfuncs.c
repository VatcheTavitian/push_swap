/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:37:04 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/20 00:29:23 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	comtopmid(t_stack *lst)
{
	if (!lst)
		return (0);
	if (lst->data <= lst->next->data)
		return (1);
	else
		return (0);
}

int	commidbot(t_stack *lst)
{
	int	second;

	if (!lst || !(lst->next))
		return (0);
	second = lst->next->data;
	while (lst->next)
		lst = lst->next;
	if (second <= lst->data)
		return (1);
	else
		return (0);
}

int	comtopbot(t_stack *lst)
{
	int	first;

	first = lst->data;
	while (lst->next)
		lst = lst->next;
	if (first <= lst->data)
		return (1);
	else
		return (0);
}

int	ft_secondbiggest(t_stack *lst)
{
	int	largest;
	int	second;

	if (!lst)
		return (0);
	largest = lst->data;
	second = INT_MIN;
	while (lst)
	{
		if (lst->data > largest)
		{
			second = largest;
			largest = lst->data;
		}
		else if (lst->data >= second && lst->data < largest)
			second = lst->data;
		lst = lst->next;
	}
	return (second);
}
