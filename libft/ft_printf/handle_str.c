/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 00:02:37 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 17:50:58 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_width_str(t_arg *arg)
{
	int		num;
	char	*str;

	if (arg->precision != -1 && arg->precision < arg->l)
		num = arg->width - arg->precision;
	else if (arg->precision == 0)
		num = arg->width;
	else
		num = arg->width - arg->l;
	num = (num < 0) ? 0 : num;
	str = ft_strnew(num);
	ft_memset(str, ' ', num);
	return (str);
}

char		*get_precision_str(t_arg *arg)
{
	char	*str;

	if (arg->precision != -1 && arg->precision < arg->l)
		str = ft_strsub(arg->val.str, 0, arg->precision);
	else if (arg->precision == 0)
		str = ft_strdup("");
	else
		str = ft_strsub(arg->val.str, 0, arg->l);
	return (str);
}

char		*ft_handle_str(t_arg *arg, va_list *ap)
{
	char	*result;
	char	*width;
	char	*tmp;

	tmp = NULL;
	arg->val.str = va_arg(*ap, char*);
	if (arg->val.str == NULL)
	{
		arg->val.str = ft_strdup("(null)");
		tmp = arg->val.str;
	}
	arg->l = ft_strlen(arg->val.str);
	arg->val.str = get_precision_str(arg);
	arg->l = ft_strlen(arg->val.str);
	width = get_width_str(arg);
	if (arg->flag.left_j)
		result = ft_strjoin(arg->val.str, width);
	else
		result = ft_strjoin(width, arg->val.str);
	arg->l = ft_strlen(result);
	ft_strdel(&tmp);
	ft_strdel(&arg->val.str);
	ft_strdel(&width);
	return (result);
}
