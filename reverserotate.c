/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:02:18 by vtavitia          #+#    #+#             */
/*   Updated: 2023/09/01 19:44:27 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **sahead)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*sahead) < 2)
		return ;
	temp = *sahead;
	last = NULL;
	while ((*sahead)->next)
	{
		if (!(last))
		{
			if ((*sahead)->next->next == NULL)
			{
				last = (*sahead)->next;
				(*sahead)->next = NULL;
				break ;
			}
		}
		*sahead = (*sahead)->next;
	}
	*sahead = last;
	(*sahead)->next = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **sbhead)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*sbhead) < 2)
		return ;
	temp = *sbhead;
	last = NULL;
	while ((*sbhead)->next)
	{
		if (!(last))
		{
			if ((*sbhead)->next->next == NULL)
			{
				last = (*sbhead)->next;
				(*sbhead)->next = NULL;
				break ;
			}
		}
		*sbhead = (*sbhead)->next;
	}
	*sbhead = last;
	(*sbhead)->next = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **sahead, t_stack **sbhead)
{
	if (sahead && ft_stacksize(*sahead) > 2)
		rra(sahead);
	if (sbhead && ft_stacksize(*sbhead) > 2)
		rrb(sbhead);
}
