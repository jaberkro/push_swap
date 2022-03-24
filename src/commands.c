/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 11:16:37 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/24 22:19:40 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_command_to_terminal(char *command)
{
	static char last_command[4];

	if (command[0] == 'e')
	{
		ft_printf("%s\n", last_command);
	}
	else if (last_command[0] == '\0')
	{
		last_command[0] = command[0];
		last_command[1] = command[1];
		last_command[2] = command[2];
	}
	else if ((ft_strncmp(command, "ra", 2) == 0 && ft_strncmp(last_command, "rb", 2) == 0) || \
		(ft_strncmp(command, "rb", 2) == 0 && ft_strncmp(last_command, "ra", 2) == 0))
	{
		ft_printf("rr\n");
		last_command[0] = 'r';
		last_command[1] = 'r';
		last_command[2] = '\0';
	}
	else if ((ft_strncmp(command, "rra", 3) == 0 && ft_strncmp(last_command, "rrb", 3) == 0) || \
		(ft_strncmp(command, "rrb", 3) == 0 && ft_strncmp(last_command, "rra", 3) == 0))
	{
		ft_printf("rrr\n");
		last_command[0] = 'r';
		last_command[1] = 'r';
		last_command[2] = 'r';
		last_command[3] = '\0';
	}
	else if ((ft_strncmp(command, "sa", 2) == 0 && ft_strncmp(last_command, "sb", 2) == 0) || \
		(ft_strncmp(command, "sb", 2) == 0 && ft_strncmp(last_command, "sa", 2) == 0))
	{
		ft_printf("ss\n");
		last_command[0] = 's';
		last_command[1] = 's';
		last_command[2] = '\0';
	}
	else if ((ft_strncmp(command, "ra", 2) == 0 && ft_strncmp(last_command, "rra", 3) == 0) || \
		(ft_strncmp(command, "rra", 3) == 0 && ft_strncmp(last_command, "ra", 2) == 0) || \
		(ft_strncmp(command, "rrb", 3) == 0 && ft_strncmp(last_command, "rb", 2) == 0) || \
		(ft_strncmp(command, "rb", 2) == 0 && ft_strncmp(last_command, "rrb", 3) == 0) || \
		(ft_strncmp(command, "pa", 2) == 0 && ft_strncmp(last_command, "pb", 2) == 0) || \
		(ft_strncmp(command, "pb", 2) == 0 && ft_strncmp(last_command, "pa", 2) == 0))
	{
		//ft_printf("double operations deleted\n");
		last_command[0] = '\0';
		last_command[1] = '\0';
		last_command[2] = '\0';
	}
	else
	{
		ft_printf("%s\n", last_command);
		last_command[0] = command[0];
		last_command[1] = command[1];
		last_command[2] = command[2];
	}
}

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

/* allowed commands according to the subject */