/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3and10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vatche <vatche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:22:26 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/20 00:29:22 by vatche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo3(t_stack **ls)
{
	while (!(ft_ordercheck(*ls)))
	{
		if (!(comtopmid(*ls)) && comtopbot(*ls))
			sa(ls);
		else if (!(comtopmid(*ls)) && !(comtopbot(*ls)) && !(commidbot(*ls)))
		{
			sa(ls);
			rra(ls);
		}
		else if (!(comtopmid(*ls)) && !(comtopbot(*ls)) && commidbot(*ls))
			ra(ls);
		else if (comtopbot(*ls) && comtopmid(*ls) && (!(commidbot(*ls))))
		{
			sa(ls);
			ra(ls);
		}
		else
			rra(ls);
	}
}

void	sorta(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stacksize(*a);
	while (ft_stacksize(*a) != 3)
		ft_proximity(a, b);
	algo3(a);
	while (ft_stacksize(*a) < size)
		pa(a, b);
}

void	ft_prox_bykey(t_stack **a, t_stack **b, int keynum, int x)
{
	int	pos;
	int	prox;
	int	size;

	size = ft_stacksize(*a) + ft_stacksize(*b);
	pos = findpos(*a, keynum);
	while (ft_stacksize(*b) < (size / 7) * x)
	{
		prox = (ft_stacksize(*a) / 2);
		if ((*a)->data <= keynum)
			pb(a, b);
		if (prox >= pos)
			ra(a);
		else
			rra(a);
	}
}

void	ft_proximity(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;
	int	prox;

	min = ft_issmallest(*a);
	pos = findpos(*a, min);
	prox = (ft_stacksize(*a) / 2);
	if ((*a)->data == min)
	{
		pb(a, b);
		min = ft_issmallest(*a);
		pos = findpos(*a, min);
		prox = (ft_stacksize(*a) / 2);
	}
	if (prox >= pos)
		ra(a);
	else
		rra(a);
}

void	algo10(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*a) > 3)
		ft_proximity(a, b);
	algo3(a);
	while (*b)
		pa(a, b);
}
