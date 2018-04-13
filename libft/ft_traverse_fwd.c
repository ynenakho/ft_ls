/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse_fwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 23:30:56 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:08 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_traverse_fwd(t_dlist *head, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist *current;

	if (!head)
		return ;
	current = head;
	while (current)
	{
		f(current);
		current = current->next;
	}
}
