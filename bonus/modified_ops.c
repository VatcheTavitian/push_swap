/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:50:41 by vtavitia          #+#    #+#             */
/*   Updated: 2023/09/01 19:39:10 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	pa2(t_stack **sahead, t_stack **sbhead)
{
	t_stack	*temp;

	if (!ft_stacksize(*sbhead))
		return ;
	if (sbhead)
	{
		temp = *sbhead;
		*sbhead = (*sbhead)->next;
		temp->next = *sahead;
		*sahead = temp;
	}
}

void	pb2(t_stack **sahead, t_stack **sbhead)
{
	t_stack	*temp;

	if (!ft_stacksize(*sahead))
		return ;
	if (sbhead == NULL)
		return ;
	temp = *sahead;
	*sahead = (*sahead)->next;
	temp->next = *sbhead;
	*sbhead = temp;
}

void	sa2(t_stack	**sahead)
{
	t_stack	*temp;

	if (ft_stacksize(*sahead) < 2)
		return ;
	if (!(*sahead)->next)
		return ;
	temp = *sahead;
	*sahead = (*sahead)->next;
	temp->next = (*sahead)->next;
	(*sahead)->next = temp;
}

void	sb2(t_stack	**sbhead)
{
	t_stack	*temp;

	if (ft_stacksize(*sbhead) < 2)
		return ;
	if (!sbhead)
		return ;
	if (!(*sbhead)->next)
		return ;
	temp = *sbhead;
	*sbhead = (*sbhead)->next;
	temp->next = (*sbhead)->next;
	(*sbhead)->next = temp;
}

void	ss2(t_stack **sahead, t_stack **sbhead)
{
	if (sahead && ft_stacksize(*sahead) > 2)
		sa2(sahead);
	if (sbhead && ft_stacksize(*sbhead) > 2)
		sb2(sbhead);
}
