/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:44:52 by vtavitia          #+#    #+#             */
/*   Updated: 2023/05/22 14:08:01 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../push_swap.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char	*get_next_line(int fd, t_stack **sahead, t_stack **sbhead);
char	*ft_strchrmod(const char *s, int c);
size_t	ft_strlenmod(const char *s);
char	*ft_strjoingnl(char *s1, char *s2);
void	do_all_checks(t_stack **sahead, int argc, char **argv);
void	ft_docommand1(char *line, t_stack **sahead, t_stack **sbhead);
void	sa2(t_stack	**sahead);
void	sb2(t_stack	**sbhead);
void	ss2(t_stack **sahead, t_stack **sbhead);
void	pa2(t_stack **stack_a, t_stack **stack_b);
void	pb2(t_stack **sahead, t_stack **sbhead);
void	ra2(t_stack **sahead);
void	rb2(t_stack **sbhead);
void	rr2(t_stack **sahead, t_stack **sbhead);
void	rra2(t_stack **sahead);
void	rrb2(t_stack **sbhead);
void	rrr2(t_stack **sahead, t_stack **sbhead);

#endif
