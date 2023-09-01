/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:40:20 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/20 15:32:43 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>

typedef struct t_stack {
	int				data;
	int				idx;
	struct t_stack	*next;
}	t_stack;

t_stack	*createnewlst(int nbr);
void	create_t_stack(t_stack **sahead, char **argv, int argc);
void	createt_stacknodes(t_stack **sahead, t_stack *new, char **av, int ac);
void	freeall(t_stack **sahead);
void	*parseargs(char **argv, int argc);
int		errormsg(void);
void	sa(t_stack	**sahead);
void	sb(t_stack	**sbhead);
void	ss(t_stack **sahead, t_stack **sbhead);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **sahead, t_stack **sbhead);
void	ra(t_stack **sahead);
void	rb(t_stack **sbhead);
void	rr(t_stack **sahead, t_stack **sbhead);
void	rra(t_stack **sahead);
void	rrb(t_stack **sbhead);
void	rrr(t_stack **sahead, t_stack **sbhead);
int		ft_stacksize(t_stack *lst);
int		ft_ordercheck(t_stack *lst);
int		ft_isbiggest(t_stack *lst);
int		ft_secondbiggest(t_stack *lst);
int		createnewlistfromstr(char **av, int i, int stop, int start);
void	create_fromarg(t_stack **sahead, t_stack *new, char **av, int set);
int		ft_issmallest(t_stack *lst);
int		comtopmid(t_stack *lst);
int		commidbot(t_stack *lst);
int		comtopbot(t_stack *lst);
void	algo3(t_stack **ls);
void	algo10(t_stack **a, t_stack **b);
void	algo100(t_stack **a, t_stack **b, int x);
void	sorta(t_stack **a, t_stack **b);
int		ft_getindex(int *sorted, int num, int size);
int		*ft_sortcomplete(t_stack *lst);
void	butterfly_split(t_stack **a, t_stack **b, int size);
void	shift_position(t_stack ***a, t_stack ***b, int max);
int		findidxpos(t_stack *ls, int max);
void	ft_proximity(t_stack **a, t_stack **b);
void	ft_prox_bykey(t_stack **a, t_stack **b, int keynum, int x);
int		ft_findquarter_original(int *array, int size, int i);
int		comtopmid(t_stack *lst);
int		commidbot(t_stack *lst);
int		comtopbot(t_stack *lst);
int		findpos(t_stack *a, int min);
int		ft_sortarray_original(t_stack *lst, int **sorted, int size);
void	do_all_checks(t_stack **sahead, int argc, char **argv);

#endif