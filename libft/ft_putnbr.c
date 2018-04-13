/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 12:59:39 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:06 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char	m[13];
	int		counter;

	if (nb < 0)
		ft_putchar('-');
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	counter = 0;
	while (nb != 0)
	{
		m[counter] = nb % 10;
		if (m[counter] < 0)
			m[counter] = -m[counter];
		nb /= 10;
		counter++;
	}
	while (counter > 0)
	{
		ft_putchar(m[counter - 1] + '0');
		counter--;
	}
}
