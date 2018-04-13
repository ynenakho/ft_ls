/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 14:22:55 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:07 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *des, const char *src, size_t n)
{
	char	*temp;
	size_t	counter;

	temp = des;
	counter = 0;
	while (*(src + counter) && (counter < n))
	{
		*(temp + counter) = *(src + counter);
		counter++;
	}
	while (counter < n)
	{
		*(temp + counter) = '\0';
		counter++;
	}
	return (des);
}
