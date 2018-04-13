/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:23:43 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:06 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *des, const char *src)
{
	unsigned int counter;

	counter = 0;
	while (*(src + counter))
	{
		*(des + counter) = *(src + counter);
		counter++;
	}
	*(des + counter) = '\0';
	return (des);
}
