/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 12:23:38 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/24 21:22:00 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}				t_dlist;

t_dlist	*ft_dlstnew(int content);
void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
void	ft_dlstrotate(t_dlist **dlst);
void	ft_dlstrev_rotate(t_dlist **dlst);
void    ft_dlstswap(t_dlist **dlst);
void    ft_dlstpush(t_dlist **dlst1, t_dlist **dlst2);

#endif