/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:10:33 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:08 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t n)
{
	size_t counter;

	counter = 0;
	while (*(str + (int)counter) && n > 0)
	{
		counter++;
		n--;
	}
	return (counter);
}
