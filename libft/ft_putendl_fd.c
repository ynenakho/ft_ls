/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:56:07 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/28 16:17:05 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *str, int fd)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
	}
	ft_putchar_fd('\n', fd);
}
