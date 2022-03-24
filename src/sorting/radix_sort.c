/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 12:21:14 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/03/24 12:56:03 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    radix_sort(t_dlist **stack_a, int total)
{
    int i;
    int j;
    int len;
    int decimal;
    t_dlist *stack_b;

    decimal = 1;
    stack_b = NULL;
    while (decimal <= total)
    {
        // print_dlist(*stack_a);
        // print_dlist(stack_b);
        if (check_sorted(*stack_a, 1) == 1)
            return ;
        i = 0;
        while (i < 10)
        {
            len = ft_dlstlen(*stack_a);
            j = 0;
            while (j < len)
            {
                if (*stack_a && (((*stack_a)->val) / decimal) % 10 == i)
                    ps_pb(&stack_b, stack_a);
                else if (*stack_a)
                    ps_ra(stack_a);
                j++;
                
            }
            i++;
        }
        // print_dlist(*stack_a);
        // print_dlist(stack_b);
        decimal *= 10;
        while (i >= 0)
        {
            len = ft_dlstlen(stack_b);
            j = 0;
            while (j < len)
            {
                if (stack_b && ((stack_b->val) / decimal) % 10 == i)
                    ps_pa(stack_a, &stack_b);
                else if (stack_b)
                    ps_rb(&stack_b);
                j++;
                // print_dlist(*stack_a);
                // print_dlist(stack_b);
            }
            i--;
        }
        // print_dlist(stack_b);
        // while (stack_b)
        //     ps_pa(stack_a, &stack_b);
        decimal *= 10;
    }
}
