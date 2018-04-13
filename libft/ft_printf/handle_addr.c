/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:52:43 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 18:32:25 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_width(t_arg *arg)
{
	char	*width;

	arg->l = ft_strlen(arg->val.str);
	if (((arg->width > arg->l + 2 && arg->flag.zero)) && !(arg->flag.left_j))
	{
		width = ft_strnew(arg->width - arg->l - 2);
		ft_memset(width, '0', arg->width - arg->l - 2);
	}
	else if (arg->width > arg->l + 2)
	{
		width = ft_strnew(arg->width - arg->l - 2);
		ft_memset(width, ' ', arg->width - arg->l - 2);
	}
	else if (arg->precision > arg->l && !(arg->flag.left_j))
	{
		width = ft_strnew(arg->precision - arg->l);
		ft_memset(width, '0', arg->precision - arg->l);
	}
	else
		width = ft_strnew(0);
	return (width);
}

char		*ft_handle_addr(t_arg *arg, va_list *ap)
{
	char	*result;
	char	*width;

	arg->val.uintm = va_arg(*ap, unsigned long int);
	arg->val.str = ((arg->precision == 0) && (arg->val.uintm == 0)) ?
		ft_strnew(0) : ft_hex(arg->val.uintm);
	width = ft_get_width(arg);
	if (arg->flag.left_j && *width == ' ')
		result = ft_strmjoin(3, "0x", arg->val.str, width);
	else if (!(arg->flag.left_j) && *width == ' ')
		result = ft_strmjoin(3, width, "0x", arg->val.str);
	else
		result = ft_strmjoin(3, "0x", width, arg->val.str);
	arg->l = ft_strlen(result);
	ft_strdel(&arg->val.str);
	ft_strdel(&width);
	return (result);
}
