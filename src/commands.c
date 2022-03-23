/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 11:16:37 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/21 19:56:34 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_dlist **stack)
{
	ft_printf("sa\n");
	ft_dlstswap(stack);
}

void	ps_sb(t_dlist **stack)
{
	ft_printf("sb\n");
	ft_dlstswap(stack);
}

void	ps_ra(t_dlist **stack)
{
	ft_printf("ra\n");
	ft_dlstrotate(stack);
}

void	ps_rb(t_dlist **stack)
{
	ft_printf("rb\n");
	ft_dlstrotate(stack);
}

void	ps_rra(t_dlist **stack)
{
	ft_printf("rra\n");
	ft_dlstrev_rotate(stack);
}

void	ps_rrb(t_dlist **stack)
{
	ft_printf("rrb\n");
	ft_dlstrev_rotate(stack);
}

void	ps_pb(t_dlist **stack_b, t_dlist **stack_a)
{
	ft_printf("pb\n");
	ft_dlstpush(stack_b, stack_a);
}

void	ps_pa(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_printf("pa\n");
	ft_dlstpush(stack_a, stack_b);
}

/* allowed commands according to the subject */