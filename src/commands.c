/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 11:16:37 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/24 15:14:00 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_dlist **stack, char *last_move)
{
	if (last_move[0] == 's' && last_move[1] == 'b')
	{
		ft_printf("ss\n");
		last_move[0] = 's';
		last_move[1] = 's';
	}
	else
	{
		if (last_move[0] != '0' && last_move[1] == 'r' && last_move[2] != '0')
			ft_printf("%c%c%c\n", last_move[0], last_move[1], last_move[2]);
		else if (last_move[0] != '0')
			ft_printf("%c%c\n", last_move[0], last_move[1]);
		last_move[0] = 's';
		last_move[1] = 'a';
	}
	ft_dlstswap(stack);
}

void	ps_sb(t_dlist **stack, char *last_move)
{
	if (last_move[0] == 's' && last_move[1] == 'a')
	{
		ft_printf("ss\n");
		last_move[0] = 's';
		last_move[1] = 's';
	}
	else
	{
		if (last_move[0] != '0' && last_move[1] == 'r' && last_move[2] != '0')
			ft_printf("%c%c%c\n", last_move[0], last_move[1], last_move[2]);
		else if (last_move[0] != '0')
			ft_printf("%c%c\n", last_move[0], last_move[1]);
		last_move[0] = 's';
		last_move[1] = 'b';
	}
	ft_dlstswap(stack);
}

void	ps_ra(t_dlist **stack, char *last_move)
{
	if (last_move[0] == 'r' && last_move[1] == 'b')
	{
		ft_printf("rr\n");
		last_move[0] = 'r';
		last_move[1] = 'r';
		last_move[2] = '0';
	}
	else
	{
		if (last_move[0] != '0' && last_move[1] == 'r' && last_move[2] != '0')
			ft_printf("%c%c%c\n", last_move[0], last_move[1], last_move[2]);
		else if (last_move[0] != '0')
			ft_printf("%c%c\n", last_move[0], last_move[1]);
		last_move[0] = 'r';
		last_move[1] = 'a';
	}
	ft_dlstrotate(stack);
}

void	ps_rb(t_dlist **stack, char *last_move)
{
	if (last_move[0] == 'r' && last_move[1] == 'a')
	{
		ft_printf("rr\n");
		last_move[0] = 'r';
		last_move[1] = 'r';
		last_move[2] = '0';
	}
	else
	{
		if (last_move[0] != '0' && last_move[1] == 'r' && last_move[2] != '0')
			ft_printf("%c%c%c\n", last_move[0], last_move[1], last_move[2]);
		else if (last_move[0] != '0')
			ft_printf("%c%c\n", last_move[0], last_move[1]);
		last_move[0] = 'r';
		last_move[1] = 'b';
	}
	ft_dlstrotate(stack);
}

void	ps_rra(t_dlist **stack, char *last_move)
{
	if (last_move[0] == 'r' && last_move[1] == 'r' && last_move[2] == 'b')
	{
		ft_printf("rrr\n");
		last_move[0] = 'r';
		last_move[1] = 'r';
		last_move[2] = 'r';
	}
	else
	{
		if (last_move[0] != '0' && last_move[1] == 'r' && last_move[2] != '0')
			ft_printf("%c%c%c\n", last_move[0], last_move[1], last_move[2]);
		else if (last_move[0] != '0')
			ft_printf("%c%c\n", last_move[0], last_move[1]);
		last_move[0] = 'r';
		last_move[1] = 'r';
		last_move[2] = 'a';
	}
	ft_dlstrev_rotate(stack);
}

void	ps_rrb(t_dlist **stack, char *last_move)
{
	if (last_move[0] == 'r' && last_move[1] == 'r' && last_move[2] == 'a')
	{
		ft_printf("rrr\n");
		last_move[0] = 'r';
		last_move[1] = 'r';
		last_move[2] = 'r';
	}
	else
	{
		if (last_move[0] != '0' && last_move[1] == 'r' && last_move[2] != '0')
			ft_printf("%c%c%c\n", last_move[0], last_move[1], last_move[2]);
		else if (last_move[0] != '0')
			ft_printf("%c%c\n", last_move[0], last_move[1]);
		last_move[0] = 'r';
		last_move[1] = 'r';
		last_move[2] = 'b';
	}
	ft_dlstrev_rotate(stack);
}

void	ps_pb(t_dlist **stack_b, t_dlist **stack_a, char *last_move)
{
	if (last_move[0] != '0' && last_move[1] == 'r' && last_move[2] != '0')
			ft_printf("%c%c%c\n", last_move[0], last_move[1], last_move[2]);
	else if (last_move[0] != '0')
		ft_printf("%c%c\n", last_move[0], last_move[1]);
	last_move[0] = 'p';
	last_move[1] = 'a';
	ft_dlstpush(stack_b, stack_a);
}

void	ps_pa(t_dlist **stack_a, t_dlist **stack_b, char *last_move)
{
	if (last_move[0] != '0' && last_move[1] == 'r' && last_move[2] != '0')
			ft_printf("%c%c%c\n", last_move[0], last_move[1], last_move[2]);
	else if (last_move[0] != '0')
		ft_printf("%c%c\n", last_move[0], last_move[1]);
	last_move[0] = 'p';
	last_move[1] = 'b';
	ft_dlstpush(stack_a, stack_b);
}

/* allowed commands according to the subject */