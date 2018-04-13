/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:14:02 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:05 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array_int(int *array, size_t array_size)
{
	size_t count;

	count = 0;
	while (count < array_size)
	{
		ft_putnbr(array[count]);
		ft_putchar(' ');
		count++;
	}
}
