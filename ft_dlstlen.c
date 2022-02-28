/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 12:07:02 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/28 12:11:10 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_dlstlen(t_dlist *to_check)
{
    int i;

    i = 0;
    while (to_check)
    {
        to_check = to_check->next;
        i++;
    }
    return (i);
}

/*
    count the length of a doubly linked list
*/