/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_push_swap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 11:16:37 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 13:12:37 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_dlist **stack)
{
	write_command_to_terminal("sa");
	ft_dlstswap(stack);
}

void	ps_sb(t_dlist **stack)
{
	write_command_to_terminal("sb");
	ft_dlstswap(stack);
}

void	ps_pb(t_dlist **stack_b, t_dlist **stack_a)
{
	write_command_to_terminal("pb");
	ft_dlstpush(stack_b, stack_a);
}

void	ps_pa(t_dlist **stack_a, t_dlist **stack_b)
{
	write_command_to_terminal("pa");
	ft_dlstpush(stack_a, stack_b);
}

int	check_swap_double_command(char *old, char *new)
{
	if ((ft_strncmp(new, "sa", 2) == 0 && ft_strncmp(old, "sb", 2) == 0) || \
		(ft_strncmp(new, "sb", 2) == 0 && ft_strncmp(old, "sa", 2) == 0))
		return (1);
	return (0);
}

/* Commands to push and swap the stacks and to check for double swaps */