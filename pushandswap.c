/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushandswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:50:41 by vtavitia          #+#    #+#             */
/*   Updated: 2023/09/01 19:43:54 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **sahead, t_stack **sbhead)
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
	write(1, "pa\n", 3);
}

void	pb(t_stack **sahead, t_stack **sbhead)
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
	write(1, "pb\n", 3);
}

void	sa(t_stack	**sahead)
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
	write(1, "sa\n", 3);
}

void	sb(t_stack	**sbhead)
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
	write(1, "sb\n", 3);
}

void	ss(t_stack **sahead, t_stack **sbhead)
{
	if (sahead && ft_stacksize(*sahead) > 2)
		sa(sahead);
	if (sbhead && ft_stacksize(*sbhead) > 2)
		sb(sbhead);
}
