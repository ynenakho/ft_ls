/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:04:59 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 17:36:34 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_width(t_arg *arg)
{
	int		num;
	char	*width;

	num = arg->width - 1;
	num = (num < 0) ? 0 : num;
	width = ft_strnew(num);
	ft_memset(width, ' ', num);
	return (width);
}

char		*ft_handle_char(t_arg *arg, va_list *ap)
{
	char	*res;
	char	*width;

	if (arg->sp == '%' && arg->width < 1)
	{
		arg->l = 1;
		return (ft_strdup("%"));
	}
	else if (arg->sp == '%')
		arg->val.chr = '%';
	else
		arg->val.chr = (unsigned char)va_arg(*ap, int);
	width = get_width(arg);
	if (arg->flag.left_j)
		res = ft_strjoin(&arg->val.chr, width);
	else
		res = ft_strnjoin(width, &arg->val.chr, ft_strlen(width) + 1);
	ft_memdel((void **)&width);
	arg->l = (!arg->val.chr) ? ft_strlen(res) + 1 : ft_strlen(res);
	return (res);
}
