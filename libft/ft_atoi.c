/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:26:39 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/15 13:51:51 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	while (ATOI_CONDITION)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : sign;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
