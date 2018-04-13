/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:07:09 by ynenakho          #+#    #+#             */
/*   Updated: 2017/11/27 01:22:14 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_u(t_arg *arg, va_list *ap)
{
	if (!(ft_strcmp(arg->length, "")))
		arg->val.uintm = va_arg(*ap, unsigned int);
	else if (!(ft_strcmp(arg->length, "hh")))
		arg->val.uintm = (unsigned char)va_arg(*ap, unsigned int);
	else if (!(ft_strcmp(arg->length, "h")))
		arg->val.uintm = (unsigned short)va_arg(*ap, unsigned int);
	else if (!(ft_strcmp(arg->length, "ll")))
		arg->val.uintm = va_arg(*ap, unsigned long long int);
	else if (!(ft_strcmp(arg->length, "l")))
		arg->val.uintm = va_arg(*ap, unsigned long int);
	else if (!(ft_strcmp(arg->length, "j")))
		arg->val.uintm = va_arg(*ap, uintmax_t);
	else if (!(ft_strcmp(arg->length, "z")))
		arg->val.uintm = va_arg(*ap, size_t);
}

void	convert(t_arg *arg, va_list *ap)
{
	if (!(ft_strcmp(arg->length, "")))
		arg->val.intm = va_arg(*ap, int);
	else if (!(ft_strcmp(arg->length, "hh")))
		arg->val.intm = (char)va_arg(*ap, int);
	else if (!(ft_strcmp(arg->length, "h")))
		arg->val.intm = (short int)va_arg(*ap, int);
	else if (!(ft_strcmp(arg->length, "ll")))
		arg->val.intm = va_arg(*ap, long long int);
	else if (!(ft_strcmp(arg->length, "l")))
		arg->val.intm = va_arg(*ap, long int);
	else if (!(ft_strcmp(arg->length, "j")))
		arg->val.intm = va_arg(*ap, intmax_t);
	else if (!(ft_strcmp(arg->length, "z")))
		arg->val.intm = va_arg(*ap, size_t);
}
