/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse_bwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 23:33:03 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:08 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_traverse_bwd(t_dlist *tail, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist *current;

	if (!tail)
		return ;
	current = tail;
	while (current)
	{
		f(current);
		current = current->previous;
	}
}
