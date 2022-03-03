/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 15:30:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/28 19:45:10 by jaberkro      ########   odam.nl         */
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

int check_sorted(t_dlist *stack, int ascending)
{
	int	last;

	last = stack->content;
	if (ascending == 1)
		last = 0;
	else 
		last = 2147483647;
	while (stack)
	{
		if ((ascending == 1 && stack->content > last) || \
			(ascending == 0 && stack->content < last ))
			last = stack->content;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	bucket_sort(t_dlist **stack_a, int ascending)
{
	int		len;
	int		i;
	t_dlist	*stack_b;

	i = 0;
	len = ft_dlstlen(*stack_a);
	// if (len < 2)
	// 	return ;
	// if (len == 2)
	// {
	// 	if (ascending == 1)
	// 	{
	// 		if ((*stack_a)->content > (*stack_a)->next->content)
	// 		{

	// 			ft_printf("content:%d rule: ", (*stack_a)->content);
	// 			ft_printf("sa\n");
	// 			ft_dlstswap(stack_a);
	// 		}
	// 	}
	// 	if (ascending == 0)
	// 	{
	// 		if ((*stack_a)->content < (*stack_a)->next->content)
	// 		{

	// 			ft_printf("content:%d rule: ", (*stack_a)->content);
	// 			ft_printf("sa\n");
	// 			ft_dlstswap(stack_a);
	// 		}
	// 	}
	// 	return ;
	// }
	// else
	// {
		if (check_sorted(*stack_a, ascending) == 0)
		{
			ft_printf("sorted: not yet.\n");
			while (i < len)
			{
				print_dlist(*stack_a);
				print_dlist(stack_b);
				ft_printf("content:%d rule: ", (*stack_a)->content);
				if ((*stack_a)->content > len / 2)
				{
					ft_printf("pb\n");
					ft_dlstpush(&stack_b, stack_a);
				}
				else
				{
					ft_printf("ra\n");
					ft_dlstrotate(stack_a);
				}
				i++;
			}
		}
		else
		{
			ft_printf("sorted: yes!\n");
			return ;
		}
		// bucket_sort(stack_a, 1);
		// bucket_sort(&stack_b, 0);
		// while ((*stack_a)->next)
		// 	*stack_a = (*stack_a)->next;
		// (*stack_a)->next = stack_b;
		// ft_dlstclear(&stack_b);
		// while ((*stack_a)->previous)
		// 	*stack_a = (*stack_a)->previous;
	//}
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
	ft_printf("[%d]\n", ft_dlstlen(stack_a));
	bucket_sort(&stack_a, 1);
	print_dlist(stack_a);
	ft_dlstclear(&stack_a);
	system("leaks push_swap");
	return (0);
}

