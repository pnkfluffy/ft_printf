/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_diou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:55:53 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/25 18:59:53 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		get_pad(t_format *format, char *ret)
{
	if (format->flag->zero && !format->flag->minus && (int)ft_strlen(ret) > format->precision)
		return '0';
	return (' ');
}

int			format_di(t_format *format, va_list args)
{
	int		num;
	char	*ret;
	char	*padding;
	int		charwidth;

	format->flag->pound = 0;
	num = (int)get_arg_signed(format->lmod, args);
	ret = num != INTMIN ? ft_itoa(ft_makepos(num)) : ft_strdup("2147483648");
	charwidth = ft_largest_int(format->precision + has_lead(format, num), ft_strlen(ret));
	padding = ft_fillstrnew(format->width - charwidth, get_pad(format, ret));
	while ((int)ft_strlen(ret) < charwidth && (int)ft_strlen(ret) < format->precision)
		ret = ft_push_to_str_front(ret, '0');
	if (has_lead(format, num))
		format->retstr = join_padding(ft_strjoin(get_lead(format, num), ret), padding, format->flag->minus);
	else
		format->retstr = join_padding(ret, padding, format->flag->minus);
	return (0);
}

int			format_o(t_format *format, va_list args)
{
	uint64_t	num;
	char		*ret;
	char		*padding;
	int			charwidth;

	format->flag->plus = 0;
	format->flag->space = 0;
	num = get_arg_unsigned(format->lmod, args);
	ret = ft_ll_itoa_base(num, 8, 0);
	charwidth = ft_largest_int(format->precision + has_lead(format, num), ft_strlen(ret));
	padding = ft_fillstrnew(format->width - charwidth - has_lead(format, num), get_pad(format, ret));
	if (has_lead(format, 1))
		format->retstr = join_padding(ft_strjoin(get_lead(format, num), ret), padding, format->flag->minus);
	else
		format->retstr = join_padding(ret, padding, format->flag->minus);
	return (0);
}

int			format_u(t_format *format, va_list args)
{
	uint32_t		num;
	char			*ret;
	char			*padding;
	int				charwidth;

	format->flag->plus = 0;
	format->flag->space = 0;
	format->flag->pound = 0;
	num = (uint32_t)get_arg_signed(format->lmod, args);
	ret = ft_ll_itoa_base(num, 10, 0);
	charwidth = ft_largest_int(format->precision, ft_strlen(ret));
	padding = ft_fillstrnew(format->width - charwidth, get_pad(format, ret));
	while ((int)ft_strlen(ret) < charwidth && (int)ft_strlen(ret) < format->precision)
		ret = ft_push_to_str_front(ret, '0');
	format->retstr = join_padding(ret, padding, format->flag->minus);
	return (0);
}

int			format_xX(t_format *format, va_list args)
{
	uint64_t	num;
	char		*ret;
	char		*padding;
	int			charwidth;

	format->flag->plus = 0;
	format->flag->space = 0;
	num = get_arg_unsigned(format->lmod, args);
	ret = ft_ll_itoa_base(num, 16, (format->type == 'x') ? 0 : 1);
	charwidth = ft_largest_int(format->precision + has_lead(format, num), ft_strlen(ret));
	padding = ft_fillstrnew(format->width - charwidth - has_lead(format, num), get_pad(format, ret));
	if (has_lead(format, num))
		format->retstr = join_padding(ft_strjoin(get_lead(format, num), ret), padding, format->flag->minus);
	else
		format->retstr = join_padding(ret, padding, format->flag->minus);
	return (0);
}