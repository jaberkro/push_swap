/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_print.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:38:02 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/25 13:08:39 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	overwrite_old(char *last_command, char a, char b, char c)
{
	last_command[0] = a;
	last_command[1] = b;
	last_command[2] = c;
}

int	check_rotate_double_command(char *old, char *new)
{
	if ((ft_strncmp(new, "ra", 2) == 0 && ft_strncmp(old, "rb", 2) == 0) || \
		(ft_strncmp(new, "rb", 2) == 0 && ft_strncmp(old, "ra", 2) == 0))
		return (1);
	return (0);
}

int	check_reverse_rotate_double_command(char *old, char *new)
{
	if ((ft_strncmp(new, "rra", 3) == 0 && ft_strncmp(old, "rrb", 3) == 0) || \
		(ft_strncmp(new, "rrb", 3) == 0 && ft_strncmp(old, "rra", 3) == 0))
		return (1);
	return (0);
}

int	check_rotate_push_forward_backward(char *old, char *new)
{
	if ((ft_strncmp(new, "ra", 2) == 0 && ft_strncmp(old, "rra", 3) == 0) || \
		(ft_strncmp(new, "rra", 3) == 0 && ft_strncmp(old, "ra", 2) == 0) || \
		(ft_strncmp(new, "rrb", 3) == 0 && ft_strncmp(old, "rb", 2) == 0) || \
		(ft_strncmp(new, "rb", 2) == 0 && ft_strncmp(old, "rrb", 3) == 0) || \
		(ft_strncmp(new, "pa", 2) == 0 && ft_strncmp(old, "pb", 2) == 0) || \
		(ft_strncmp(new, "pb", 2) == 0 && ft_strncmp(old, "pa", 2) == 0))
		return (1);
	return (0);
}

void	write_command_to_terminal(char *command)
{
	static char	last_command[4];

	if (check_rotate_push_forward_backward(last_command, command) == 1)
		overwrite_old(last_command, '\0', '\0', '\0');
	else if (check_rotate_double_command(last_command, command) == 1)
	{
		ft_printf("rr\n");
		overwrite_old(last_command, 'r', 'r', '\0');
	}
	else if (check_reverse_rotate_double_command(last_command, command) == 1)
	{
		ft_printf("rrr\n");
		overwrite_old(last_command, 'r', 'r', 'r');
	}
	else if (check_swap_double_command(last_command, command) == 1)
	{
		ft_printf("ss\n");
		overwrite_old(last_command, 's', 's', '\0');
	}
	else
	{
		if (last_command[0] != '\0')
			ft_printf("%s\n", last_command);
		overwrite_old(last_command, command[0], command[1], command[2]);
	}
}

/* these functions store the last given command and print it a round later */