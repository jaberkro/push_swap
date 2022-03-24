/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 12:23:38 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/24 21:31:14 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_dlist
{
	int				val;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}				t_dlist;

t_dlist	*ft_dlstnew(int content);
void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
void	ft_dlstrotate(t_dlist **dlst);
void	ft_dlstrev_rotate(t_dlist **dlst);
void	ft_dlstswap(t_dlist **dlst);
void	ft_dlstpush(t_dlist **dlst1, t_dlist **dlst2);
void	ft_dlstclear(t_dlist **dlst);
int		ft_dlstlen(t_dlist *to_check);
int		ft_dlstindex_lowest(t_dlist **dlst, int value);
t_dlist	*ft_dlstlast(t_dlist *dlst);

void	print_dlist(t_dlist *to_print);
int	check_sorted(t_dlist *stack, int ascending);
int	check_sorted_part(t_dlist *stack, int ascending, int len);

void	bubble_sort(t_dlist **stack_a, int ascending);
t_dlist	*quick_sort(t_dlist **stack_a, int start, int end);
void	smallest_sort(t_dlist **stack_a, int ascending);
void	bucket_sort(t_dlist **stack_a);
void	insertion_sort(t_dlist **stack_a, int len);
void    radix_sort(t_dlist **stack_a, int total);
void	insertion_sort_advanced(t_dlist **stack_a, t_dlist **stack_b);

void	ps_sa(t_dlist **stack);
void	ps_sb(t_dlist **stack);
void	ps_ra(t_dlist **stack);
void	ps_rb(t_dlist **stack);
void	ps_rra(t_dlist **stack);
void	ps_rrb(t_dlist **stack);
void	ps_pb(t_dlist **stack_b, t_dlist **stack_a);
void	ps_pa(t_dlist **stack_a, t_dlist **stack_b);

void	write_command_to_terminal(char *command);

#endif