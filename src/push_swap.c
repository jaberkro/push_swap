/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 15:30:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/21 20:43:39 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char **argv, t_dlist **stack_a);

void	print_dlist(t_dlist *to_print)
{
	while (to_print)
	{
		ft_printf("<%d>", to_print->val);
		to_print = to_print->next;
	}
	ft_printf("\n");
}

int	check_sorted(t_dlist *stack, int ascending)
{
	int	last;

	last = stack->val;
	if (ascending == 1)
		last = 0;
	else
		last = 2147483647;
	while (stack)
	{
		if ((ascending == 1 && stack->val > last) || \
			(ascending == 0 && stack->val < last))
			last = stack->val;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_part(t_dlist *stack, int ascending, int len)
{
	int	last;
	int	i;

	i = 0;
	if (ascending == 1)
		last = 0;
	else
		last = 2147483647;
	while (i < len)
	{
		if ((ascending == 1 && stack->val > last) || \
			(ascending == 0 && stack->val < last))
			last = stack->val;
		else
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}




// t_dlist	*bucket_sort(t_dlist *stack_a, int ascending)
// {
// 	int		len;
// 	int		i;
// 	t_dlist	*stack_b;

// 	i = 0;
// 	len = ft_dlstlen(stack_a);
// 	stack_b = NULL;
// 	if (check_sorted(stack_a, ascending) == 0)
// 	{
// 		ft_printf("sorted: not yet.\n");
// 		if (len == 2)
// 		{
// 			if ((ascending == 1 && stack_a->content > stack_a->next->content) \
// 			|| (ascending == 0 && stack_a->content < stack_a->next->content))
// 			{
// 				ft_printf("sa\n");
// 				ft_dlstswap(&stack_a);
// 				print_dlist(stack_a);
// 				return (stack_a);
// 			}
// 		}
// 		ft_printf("splitting starting\n");
// 		while (i < len)
// 		{
// 			if (stack_a->content <= len / 2)
// 			{
// 				ft_printf("pb\n");
// 				ft_dlstpush(&stack_b, &stack_a);
// 			}
// 			else
// 			{
// 				ft_printf("ra\n");
// 				ft_dlstrotate(&stack_a);
// 			}
// 			print_dlist(stack_a);
// 			print_dlist(stack_b);
// 			i++;
// 		}
// 		ft_printf("recursion starting\n");
// 		print_dlist(stack_a);
// 		stack_a = bucket_sort(stack_a, 1);
// 		print_dlist(stack_a);
// 		stack_b = bucket_sort(stack_b, 0);
// 		ft_printf("recursion coming back\n");
// 		while (stack_b)
// 		{
// 			ft_printf("pa\n");
// 			print_dlist(stack_a);
// 			print_dlist(stack_b);
// 			ft_dlstpush(&stack_a, &stack_b);
// 		}
// 		return (stack_a);
// 	}
// 	else
// 	{
// 		ft_printf("sorted: yes!\n");
// 		print_dlist(stack_a);
// 		return (stack_a);
// 	}

// 	// while ((*stack_a)->next)
// 	// 	*stack_a = (*stack_a)->next;
// 	// (*stack_a)->next = stack_b;
// 	// ft_dlstclear(&stack_b);
// 	// while ((*stack_a)->previous)
// 	// 	*stack_a = (*stack_a)->previous;
// //}
// }

int	main(int argc, char**argv)
{
	t_dlist	*stack_a;
	// t_dlist	*tmp1;

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
	if (ft_dlstlen(stack_a) <= 6)
		smallest_sort(&stack_a, 1);
	else 
		bucket_sort(&stack_a);
		//bubble_sort(&stack_a, 1);
	//ft_printf("bubble sort done. Starting quick sort now\n");
	//quick_sort(&stack_a, 1, ft_dlstlen(stack_a));
	//stack_a = tmp1;
	//ft_printf("arriving home:\n");
	print_dlist(stack_a);
	//ft_dlstclear(&stack_a);
	//system("leaks push_swap");
	return (0);
}
