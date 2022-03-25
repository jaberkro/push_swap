/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 12:21:14 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 11:29:46 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	present(t_dlist *stack, int decimal, int tofind)
{
	while (stack)
	{
		if ((stack->val) / decimal % 10 == tofind)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	rotate_back(t_dlist **stack, int rotate_count, int len, int ab)
{
	if (rotate_count > len / 2)
	{
		while (rotate_count < len)
		{
			if (ab == 0)
				ps_ra(stack);
			else
				ps_rb(stack);
			rotate_count++;
		}
	}
	else
	{
		while (rotate_count > 0)
		{
			if (ab == 0)
				ps_rra(stack);
			else
				ps_rrb(stack);
			rotate_count--;
		}
	}
}

int	find_closest(t_dlist *stack, int decimal, int i)
{
	int		forward;
	int		backward;
	t_dlist	*tmp;

	forward = 0;
	backward = 1;
	tmp = ft_dlstlast(stack);
	if (present(stack, decimal, i) == 0)
		return (1000);
	while (tmp)
	{
		if (tmp->val / decimal % 10 == i)
			break ;
		tmp = tmp->previous;
		backward++;
	}
	while (stack)
	{
		if (stack->val / decimal % 10 == i)
			break ;
		stack = stack->next;
		forward++;
	}
	if (forward < backward)
		return (forward);
	return (backward);
}

void	sort_descending(t_dlist **stack_a, t_dlist **stack_b, int decimal)
{
	int	i;
	int	j;
	int	len;
	int	rotate_count;

	i = 0;
	while (i < 10)
	{
		rotate_count = 0;
		len = ft_dlstlen(*stack_a);
		j = 0;
		while (j < len)
		{
			if (present(*stack_a, decimal, i) == 0 && rotate_count > 0)
			{
				rotate_back(stack_a, rotate_count, ft_dlstlen(*stack_a), 0);
				break ;
			}
			if (*stack_a && (((*stack_a)->val) / decimal) % 10 == i)
				ps_pb(stack_b, stack_a);
			else if (*stack_a)
			{
				ps_ra(stack_a);
				rotate_count++;
			}
			j++;
		}
		i++;
	}
}

void	sort_ascending(t_dlist **stack_a, t_dlist **stack_b, int decimal)
{
	int	i;
	int	j;
	int	len;
	int	rotate_count;

	i = 9;
	while (i >= 0)
	{
		rotate_count = 0;
		len = ft_dlstlen(*stack_b);
		j = 0;
		while (j < len)
		{
			if (present(*stack_b, decimal, i) == 0 && rotate_count > 0)
			{
				rotate_back(stack_b, rotate_count, ft_dlstlen(*stack_b), 1);
				break ;
			}
			if (*stack_b && (((*stack_b)->val) / decimal) % 10 == i)
				ps_pa(stack_a, stack_b);
			else if (*stack_b)
			{
				ps_rb(stack_b);
				rotate_count++;
			}
			j++;
		}
		i--;
	}
}

void	radix_sort(t_dlist **stack_a, int total)
{
	int		decimal;
	t_dlist	*stack_b;

	decimal = 1;
	stack_b = NULL;
	while (decimal <= total)
	{
		if (*stack_a && check_sorted(*stack_a, 1) == 1)
			return ;
		sort_descending(stack_a, &stack_b, decimal);
		decimal *= 10;
		sort_ascending(stack_a, &stack_b, decimal);
		decimal *= 10;
	}
}