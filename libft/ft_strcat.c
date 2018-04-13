/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 21:44:04 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:06 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *des;

	des = dest;
	while (*des != '\0')
		des++;
	while (*src != '\0')
	{
		*(des) = *(src);
		src++;
		des++;
	}
	*(des) = '\0';
	return (dest);
}
