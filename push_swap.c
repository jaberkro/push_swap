/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 15:30:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/28 17:12:07 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char **argv, t_dlist **stack_a);

void	print_dlist(t_dlist *to_print)
{
	while (to_print)
	{
		ft_printf("<%d>", to_print->content);
		to_print = to_print->next;
	}
	ft_printf("\n");
}

int	main(int argc, char**argv)
{
	t_dlist	*stack_a;

	if (argc == 1)
		return (0);
	if (parse_input(argc, argv, &stack_a) == 0)
	{
		ft_dlstclear(&stack_a);
		system("leaks push_swap");
		return (write(1, "Error\n", 6));
	}
	print_dlist(stack_a);
	ft_printf("[%d]", ft_dlstlen(stack_a));
	ft_dlstclear(&stack_a);
	system("leaks push_swap");
	return (0);
}

