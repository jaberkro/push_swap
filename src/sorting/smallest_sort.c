/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallest_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 13:52:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/24 22:13:13 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest(t_dlist *stack_a)
{
	int	highest;

	highest = 0;
	while (stack_a && stack_a->val)
	{
		if (stack_a->val > highest)
			highest = stack_a->val;
		stack_a = stack_a->next;
	}
	return (highest);
}

static int	find_lowest(t_dlist *stack_a)
{
	int	lowest;

	lowest = 2147483647;
	while (stack_a && stack_a->val)
	{
		if (stack_a->val < lowest)
			lowest = stack_a->val;
		stack_a = stack_a->next;
	}
	return (lowest);
}

static void	three_sort(t_dlist **stack_a, int as)
{
	int		low;
	int		up;
	t_dlist	*tmp;

	low = find_lowest(*stack_a);
	up = find_highest(*stack_a);
	tmp = *stack_a;
	if ((tmp->val == up && as == 1) || (tmp->val == low && as == 0))
	{
		ps_ra(stack_a);
		if (check_sorted(*stack_a, as) == 0)
			ps_sa(stack_a);
	}
	else if (((tmp->val == low && as == 1) || (tmp->val == up && as == 0)) && \
	((tmp->next->val == up && as == 1) || (tmp->next->val != low && as == 0)))
	{
		ps_sa(stack_a);
		ps_ra(stack_a);
	}
	else if ((tmp->next->val == low && as == 1) || \
	(tmp->next->val != up && as == 0))
		ps_sa(stack_a);
	else if (check_sorted(*stack_a, as) == 0)
		ps_rra(stack_a);
	return ;
}

static void	six_sort(t_dlist **stack_a, t_dlist **stack_b, int len, int as)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while ((*stack_a)->val < len - 2)
		{
			ps_pb(stack_b, stack_a);
			i++;
		}
		if (i >= len)
			break ;
		ps_ra(stack_a);
		i++;
	}
	three_sort(stack_a, as);
	if (len == 5 && check_sorted(*stack_b, 0) == 0)
		ps_sb(stack_b);
	else if (len == 6)
		three_sort(stack_b, 0);
	while (*stack_b)
		ps_pa(stack_a, stack_b);
	return ;
}

void	smallest_sort(t_dlist **stack_a, int ascending)
{
	int		len;
	t_dlist	*stack_b;

	stack_b = NULL;
	len = ft_dlstlen(*stack_a);
	if (check_sorted(*stack_a, ascending) == 1)
		return ;
	else if (len == 2 && ascending == 1)
		ps_ra(stack_a);
	else if (len == 2 && ascending == 0)
		ps_rb(stack_a);
	else if (len == 3)
		three_sort(stack_a, ascending);
	else
		six_sort(stack_a, &stack_b, len, ascending);
	return ;
}
