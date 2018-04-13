/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:59:55 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 18:46:45 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*single_b(wint_t wide_char, t_arg *arg)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = wide_char;
	arg->l += 1;
	return (str);
}

static char	*double_b(wint_t wide_char, t_arg *arg)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = 0xC0 | (wide_char >> 6);
	str[1] = 0x80 | (wide_char & 0x3F);
	arg->l += 2;
	return (str);
}

static char	*triple_b(wint_t wide_char, t_arg *arg)
{
	char	*str;

	str = ft_strnew(3);
	str[0] = 0xE0 | (wide_char >> 12);
	str[1] = 0x80 | ((wide_char >> 6) & 0x3F);
	str[2] = 0x80 | (wide_char & 0x3F);
	arg->l += 3;
	return (str);
}

static char	*quadruple_b(wint_t wide_char, t_arg *arg)
{
	char	*str;

	str = ft_strnew(4);
	str[0] = 0xF0 | (wide_char >> 18);
	str[1] = 0x80 | ((wide_char >> 12) & 0x3F);
	str[2] = 0x80 | ((wide_char >> 6) & 0x3F);
	str[3] = 0x80 | (wide_char & 0x3F);
	arg->l += 4;
	return (str);
}

char		*ft_handle_wchar(t_arg *arg, va_list *ap)
{
	wint_t	wide_char;
	char	*str;

	wide_char = va_arg(*ap, wint_t);
	if (wide_char < 0x80)
		str = single_b(wide_char, arg);
	else if (wide_char < 0x800)
		str = double_b(wide_char, arg);
	else if (wide_char < 0x10000)
		str = triple_b(wide_char, arg);
	else if (wide_char < 0x200000)
		str = quadruple_b(wide_char, arg);
	else
		str = ft_strnew(0);
	return (str);
}
