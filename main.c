/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:17:46 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/22 14:20:29 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*sahead;
	t_stack	*sbhead;
	int		i;

	i = 1;
	sahead = NULL;
	sbhead = NULL;
	if (argc == 1)
		return (0);
	do_all_checks(&sahead, argc, argv);
	if (!(ft_ordercheck(sahead)))
	{
		if (ft_stacksize(sahead) == 3)
			algo3(&sahead);
		else if (ft_stacksize(sahead) <= 10)
			algo10(&sahead, &sbhead);
		else if (ft_stacksize(sahead) > 10 && ft_stacksize(sahead) < 100)
			algo100(&sahead, &sbhead, i);
		else
			butterfly_split(&sahead, &sbhead, ft_stacksize(sahead));
	}
	freeall(&sahead);
	freeall(&sbhead);
	return (0);
}
