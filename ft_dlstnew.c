/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstnew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 12:19:07 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/24 17:50:32 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*out;

	out = malloc(sizeof(t_dlist));
	if (out == NULL)
		return (NULL);
	out->content = content;
    out->previous = NULL;
	out->next = NULL;
	return (out);
}
