/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:35:37 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 12:09:41 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_dlist **stack)
{
	write_command_to_terminal("ra");
	ft_dlstrotate(stack);
}

void	ps_rb(t_dlist **stack)
{
	write_command_to_terminal("rb");
	ft_dlstrotate(stack);
}

void	ps_rra(t_dlist **stack)
{
	write_command_to_terminal("rra");
	ft_dlstrev_rotate(stack);
}

void	ps_rrb(t_dlist **stack)
{
	write_command_to_terminal("rrb");
	ft_dlstrev_rotate(stack);
}

/* Commands to rotate and reverse rotate stacks */