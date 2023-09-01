/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_all_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:17:37 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/22 14:18:09 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errormsg(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	ft_dupcheck(int *sorted, int size)
{
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	while (i < size - 1)
	{
		if (sorted[i] <= sorted[i + 1])
			i++;
		else
		{
			temp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = temp;
			i = 0;
		}
	}
	i = 0;
	while (i < size - 1)
	{
		if (sorted[i] == sorted[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	check_dups(t_stack *lst)
{
	int	size;
	int	*sorted;
	int	i;

	i = 0;
	size = ft_stacksize(lst);
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (0);
	while (i < size)
	{
		sorted[i] = lst->data;
		lst = lst->next;
		i++;
	}
	if (!(ft_dupcheck(sorted, size)))
	{
		free(sorted);
		return (0);
	}
	free(sorted);
	return (1);
}

void	do_all_checks(t_stack **sahead, int argc, char **argv)
{
	if (argc == 1 || parseargs(argv, argc) == NULL)
		errormsg();
	else
		create_t_stack(sahead, argv, argc);
	if (*sahead)
	{
		if (!(check_dups(*sahead)))
		{
			freeall(sahead);
			errormsg();
		}
	}
}
