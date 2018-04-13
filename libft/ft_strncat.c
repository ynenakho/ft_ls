/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 22:10:20 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:07 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	char *des;

	des = dest;
	while (*des != '\0')
		des++;
	while (*src && (nb != 0))
	{
		*des = *src;
		des++;
		src++;
		nb--;
	}
	*des = '\0';
	return (dest);
}
