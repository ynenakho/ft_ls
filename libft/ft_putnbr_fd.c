/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 12:59:39 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:06 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	m[13];
	int		counter;

	if (nb < 0)
		ft_putchar_fd('-', fd);
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
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
		ft_putchar_fd(m[counter - 1] + '0', fd);
		counter--;
	}
}
