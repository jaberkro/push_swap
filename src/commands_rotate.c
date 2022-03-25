/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_rotate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:35:37 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 13:41:33 by jaberkro      ########   odam.nl         */
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

/* Commands to rotate and reverse rotate stacks */