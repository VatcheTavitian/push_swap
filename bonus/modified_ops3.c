/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_ops3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:45:29 by vtavitia          #+#    #+#             */
/*   Updated: 2023/09/01 19:36:56 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ra2(t_stack **sahead)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stacksize(*sahead) < 2)
		return ;
	temp = NULL;
	temp2 = NULL;
	if ((*sahead)->next)
	{
		temp = *sahead;
		temp2 = (*sahead)->next;
		while ((*sahead)->next)
			*sahead = (*sahead)->next;
		(*sahead)->next = temp;
		*sahead = (*sahead)->next;
		(*sahead)->next = NULL;
		*sahead = temp2;
	}
}

void	rb2(t_stack **sbhead)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stacksize(*sbhead) < 2)
		return ;
	temp = NULL;
	temp2 = NULL;
	if ((*sbhead)->next)
	{
		temp = *sbhead;
		temp2 = (*sbhead)->next;
		while ((*sbhead)->next)
			*sbhead = (*sbhead)->next;
		(*sbhead)->next = temp;
		*sbhead = (*sbhead)->next;
		(*sbhead)->next = NULL;
		*sbhead = temp2;
	}
}

void	rr2(t_stack **sahead, t_stack **sbhead)
{
	if (sahead && ft_stacksize(*sahead) > 2)
		ra2(sahead);
	if (sbhead && ft_stacksize(*sbhead) > 2)
		rb2(sbhead);
}
