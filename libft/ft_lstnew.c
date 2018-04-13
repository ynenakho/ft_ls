/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 22:35:44 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:16:56 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	new->content = ft_memalloc(content_size);
	if (!new->content)
		return (NULL);
	new->content_size = content_size;
	new->content = ft_memcpy(new->content, content, content_size);
	new->next = NULL;
	return (new);
}
