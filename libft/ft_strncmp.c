/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 14:46:48 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:07 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *pt1;
	const unsigned char *pt2;

	pt1 = (const unsigned char *)s1;
	pt2 = (const unsigned char *)s2;
	while ((*pt1 != '\0' || *pt2 != '\0') && n != 0)
	{
		if ((*pt1 < *pt2) || (*pt1 > *pt2))
			return (*pt1 - *pt2);
		pt1++;
		pt2++;
		n--;
	}
	return (0);
}
