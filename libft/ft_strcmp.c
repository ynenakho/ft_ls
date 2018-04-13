/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 13:57:06 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:06 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int		ft_strcmp(const char *s1, const char *s2)
// {
// 	const unsigned char *ptr1;
// 	const unsigned char *ptr2;
//
// 	ptr1 = (const unsigned char *)s1;
// 	ptr2 = (const unsigned char *)s2;
// 	while (*ptr1 && *ptr2)
// 		ptr1 += (ptr2++) ? 1 : 1;
// 	if (*ptr1 || *ptr2)
// 		return (*ptr1 - *ptr2);
// 	return (ft_memcmp((void *)s1, (void *)s2,
// 				(size_t)(ptr1 - (const unsigned char *)s1)));
// 	return (0);
// }
