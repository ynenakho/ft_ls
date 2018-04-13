/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:03:31 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:00 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *new;

	if (size <= 0)
		return (NULL);
	new = malloc(size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
