/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createnewlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:41:14 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/20 14:31:16 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_indexes(t_stack **lst2)
{
	int			size;
	int			size_backup;
	int			i;
	int			*sortedarray;
	t_stack		*lst;

	lst = *lst2;
	sortedarray = ft_sortcomplete(lst);
	size = ft_stacksize(lst);
	size_backup = size;
	i = 0;
	while ((i < size))
	{
		(*lst2)->idx = ft_getindex(sortedarray, (*lst2)->data, size_backup);
		(*lst2) = (*lst2)->next;
		i++;
	}
	free (sortedarray);
}

t_stack	*createnewlst(int nbr)
{
	t_stack	*newlist;

	if (nbr < INT_MIN)
	{
		errormsg();
		exit(EXIT_FAILURE);
	}	
	newlist = (t_stack *)malloc(sizeof(t_stack));
	if (!newlist)
		newlist = NULL;
	newlist->data = nbr;
	newlist->idx = 0;
	newlist->next = NULL;
	return (newlist);
}

void	*parseargs(char **argv, int argc)
{
	int	i;
	int	d;

	i = 1;
	while (i < argc)
	{
		d = 0;
		while (argv[i][d] != '\0')
		{
			if (!(ft_isdigit(argv[i][d])))
				return (NULL);
			d++;
		}
		i++;
	}
	return ((void *)1);
}

void	createt_stacknodes(t_stack **sahead, t_stack *new, char **av, int ac)
{
	int		i;
	t_stack	*temp;

	i = 2;
	while (i < ac)
	{	
		if (ft_atoi(av[i]) < INT_MIN)
		{
			errormsg();
			exit(EXIT_FAILURE);
		}	
		temp = createnewlst(ft_atoi(av[i++]));
		if (!temp)
		{
			while (*sahead)
			{
				free(*sahead);
				*sahead = (*sahead)->next;
			}
			return ;
		}
		new = (new->next = temp);
		if (i == ac - 1)
			new->next = NULL;
	}
}

void	create_t_stack(t_stack **sahead, char **argv, int argc)
{
	int		i;
	int		set;
	t_stack	*newlist;
	t_stack	**temp;

	if (argc == 1)
		return ;
	i = 1;
	set = 0;
	if (argc > 2)
	{
		newlist = createnewlst(ft_atoi(argv[i]));
		if (!newlist)
			return ;
		createt_stacknodes(sahead, newlist, argv, argc);
	}
	else
	{
		newlist = createnewlst(createnewlistfromstr(argv, i, set, 0));
		create_fromarg(sahead, newlist, argv, set);
	}
	(*sahead) = newlist;
	temp = &newlist;
	assign_indexes(temp);
}
