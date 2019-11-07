/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_diouxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:55:53 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 21:32:14 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			format_di(t_format *fmt, va_list args)
{
	int64_t	num;
	char	*ret;
	char	*pad;
	int		chlen;

	fmt->flag->pound = 0;
	num = get_arg_signed(fmt->lmod, args);
	chlen = fmt_di_help(fmt, num, &ret);
	pad = ft_fillstrnew(fmt->width - chlen - has_lead(fmt, num), \
	get_pad(fmt, ret));
	while ((int)ft_strlen(ret) < chlen && (int)ft_strlen(ret) < fmt->prec)
		ret = ft_push_to_str_front(ret, '0');
	if ((int)ft_strlen(ret) + (int)ft_strlen(pad) + \
	has_lead(fmt, num) < fmt->width)
		pad = ft_push_to_str_front(pad, get_pad(fmt, ret));
	if (has_lead(fmt, num))
		if (get_pad(fmt, ret) == '0')
			fmt->retstr = ft_strjoin(get_lead(fmt, num), \
			join_pad(ret, pad, fmt->flag->minus));
		else
			fmt->retstr = join_pad(ft_strjoin(get_lead(fmt, num), ret), pad, \
			fmt->flag->minus);
	else
		fmt->retstr = join_pad(ret, pad, fmt->flag->minus);
	free_strings(&ret, &pad, NULL);
	return (0);
}

int			format_o(t_format *fmt, va_list args)
{
	uint64_t	num;
	char		*ret;
	char		*pad;
	int			chlen;

	fmt->flag->plus = 0;
	fmt->flag->space = 0;
	num = get_arg_unsigned(fmt->lmod, args);
	ret = (fmt->prec == 0 && num == 0) ? ft_strnew(0) : \
	ft_ull_itoa_base(num, 8, 0);
	chlen = ft_largest_int(fmt->prec + has_lead(fmt, num), ft_strlen(ret));
	pad = ft_fillstrnew(fmt->width - chlen - has_lead(fmt, num), \
	get_pad(fmt, ret));
	while (ft_strlen(ret) < chlen && ft_strlen(ret) < fmt->prec)
		ret = ft_push_to_str_front(ret, '0');
	if (has_lead(fmt, num) && ret[0] != '0')
		fmt->retstr = join_pad(ft_strjoin(get_lead(fmt, num), ret), pad, \
		fmt->flag->minus);
	else
		fmt->retstr = join_pad(ret, pad, fmt->flag->minus);
	free_strings(&ret, &pad, NULL);
	return (0);
}

int			format_u(t_format *fmt, va_list args)
{
	uint64_t		num;
	char			*ret;
	char			*pad;
	int				chlen;

	fmt->flag->plus = 0;
	fmt->flag->space = 0;
	fmt->flag->pound = 0;
	num = (uint64_t)get_arg_unsigned(fmt->lmod, args);
	ret = (fmt->prec == 0 && num == 0) ? ft_strnew(0) : \
	ft_ull_itoa_base(num, 10, 0);
	chlen = ft_largest_int(fmt->prec, ft_strlen(ret));
	pad = ft_fillstrnew(fmt->width - chlen, get_pad(fmt, ret));
	while (ft_strlen(ret) < chlen && ft_strlen(ret) < fmt->prec)
		ret = ft_push_to_str_front(ret, '0');
	fmt->retstr = join_pad(ret, pad, fmt->flag->minus);
	free_strings(&ret, &pad, NULL);
	return (0);
}

int			format_xX(t_format *fmt, va_list args)
{
	uint64_t	num;
	char		*ret;
	char		*pad;
	int			chlen;

	fmt->flag->plus = 0;
	fmt->flag->space = 0;
	num = get_arg_unsigned(fmt->lmod, args);
	ret = (fmt->prec == 0 && num == 0) ? ft_strnew(0) : \
	ft_ull_itoa_base(num, 16, (fmt->type == 'x') ? 0 : 1);
	chlen = ft_largest_int(fmt->prec + has_lead(fmt, num), ft_strlen(ret));
	pad = ft_fillstrnew(fmt->width - chlen - has_lead(fmt, num), \
	get_pad(fmt, ret));
	while (ft_strlen(ret) < chlen && ft_strlen(ret) < fmt->prec)
		ret = ft_push_to_str_front(ret, '0');
	if (has_lead(fmt, num))
		if (get_pad(fmt, ret) == '0')
			fmt->retstr = ft_strjoin(get_lead(fmt, num), \
			join_pad(ret, pad, fmt->flag->minus));
		else
			fmt->retstr = join_pad(ft_strjoin(get_lead(fmt, num), ret), \
			pad, fmt->flag->minus);
	else
		fmt->retstr = join_pad(ret, pad, fmt->flag->minus);
	free_strings(&ret, &pad, NULL);
	return (0);
}
