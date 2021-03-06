/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:28:08 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:16:56 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_bubblesort(int *array, size_t array_size)
{
	int		temp_value;
	int		*sorted;
	size_t	count;

	sorted = (int *)malloc(array_size * sizeof(*array));
	if (!sorted)
		return (NULL);
	ft_memcpy(sorted, array, array_size * sizeof(*array));
	count = 0;
	while (count < array_size - 1)
	{
		if (sorted[count] > sorted[count + 1])
		{
			temp_value = sorted[count];
			sorted[count] = sorted[count + 1];
			sorted[count + 1] = temp_value;
			count = 0;
			continue ;
		}
		count++;
	}
	return (sorted);
}
