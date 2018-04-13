/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:46:37 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:05 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*push(void *array, size_t len, void *data, size_t data_len)
{
	void	*newarr;

	newarr = ft_memalloc(len + data_len);
	newarr = ft_memcpy(newarr, array, len);
	newarr = ft_memcpy(newarr + len, data, data_len);
	free(array);
	return (newarr - (len + data_len - 1));
}
