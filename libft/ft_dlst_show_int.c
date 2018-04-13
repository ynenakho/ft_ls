/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_show_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 23:35:25 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:16:56 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_show_int(void *content)
{
	int		*data;

	data = (int*)content;
	while (*data)
	{
		ft_putnbr(*data);
		ft_putstr("->");
		data++;
	}
	ft_putchar('\n');
}
