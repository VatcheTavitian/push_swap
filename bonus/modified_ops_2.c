/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_ops_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:02:18 by vtavitia          #+#    #+#             */
/*   Updated: 2023/09/01 19:36:07 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	rra2(t_stack **sahead)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *sahead;
	last = NULL;
	if (ft_stacksize(*sahead) < 2)
		return ;
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
}

void	rrb2(t_stack **sbhead)
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
}

void	rrr2(t_stack **sahead, t_stack **sbhead)
{
	if (sahead && ft_stacksize(*sahead) > 2)
		rra2(sahead);
	if (sbhead && ft_stacksize(*sbhead) > 2)
		rrb2(sbhead);
}
