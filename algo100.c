/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:50:28 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/20 14:36:31 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rb(t_stack ***a, t_stack ***b, int max, int *rbcount)
{
	while ((*rbcount) > 0)
	{
		max = ft_isbiggest(**b);
		if (ft_stacksize(**b) > 2)
			rrb(*b);
		if ((**b)->data == max)
			pa(*a, *b);
		(*rbcount)--;
	}
	return (*rbcount);
}

static void	if_secondpos(t_stack ***a, t_stack ***b, int *secondpos)
{
	if (*secondpos > 0)
	{
		pb(*a, *b);
		sb(*b);
		*secondpos = 0;
	}
	pa(*a, *b);
	if (**b)
		if ((**b)->data == ft_isbiggest(**b))
			pa(*a, *b);
}

static int	foundsecond_pos(t_stack ***a, t_stack ***b)
{
	pa(*a, *b);
	return (1);
}

static void	ft_prox_bymax(t_stack **a, t_stack **b, int rbcount)
{
	int	max;
	int	secondbiggest;
	int	secondpos;

	secondpos = 0;
	rbcount = 0;
	if (ft_stacksize(*b) > 1)
		secondbiggest = ft_secondbiggest(*b);
	while (*b)
	{
		max = ft_isbiggest(*b);
		if ((*b)->data != max)
		{
			if ((*b)->data == secondbiggest)
				secondpos = foundsecond_pos(&a, &b);
			rb(b);
			rbcount++;
		}
		else
		{
			if_secondpos(&a, &b, &secondpos);
			if (rbcount > 0 && ft_stacksize(*b) > 2)
				rbcount = reverse_rb(&a, &b, max, &rbcount);
		}
	}
}

void	algo100(t_stack **a, t_stack **b, int x)
{
	int	size;
	int	*original;
	int	keynum;

	original = NULL;
	x = 1;
	if (*a)
		original = (int *)malloc(ft_stacksize(*a) * sizeof(int));
	else
		errormsg();
	if (!original)
		return ;
	size = ft_stacksize(*a);
	ft_sortarray_original(*a, &original, size);
	while (x < 7)
	{
		keynum = ft_findquarter_original(original, size, x);
		ft_prox_bykey(a, b, keynum, x);
		x++;
	}
	sorta(a, b);
	if (*b)
		ft_prox_bymax(a, b, keynum);
	free(original);
}
