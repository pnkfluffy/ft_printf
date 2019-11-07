/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_cspf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:09:09 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 21:33:11 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_c(t_format *fmt, va_list args)
{
	char *c;
	char *pad;

	c = NULL;
	if (fmt->type != '%')
		c = ft_fillstrnew(1, va_arg(args, int));
	else
		c = ft_fillstrnew(1, '%');
	if (!(fmt->has_width))
		fmt->width = 1;
	pad = ft_fillstrnew(fmt->width - 1, ' ');
	fmt->retstr = join_pad(c, pad, fmt->flag->minus);
	free_strings(&c, &pad, NULL);
	return (0);
}

int		format_s(t_format *fmt, va_list args)
{
	char *s;
	char *pad;

	if (!(s = ft_strdup(va_arg(args, char *))))
	{
		fmt->retstr = ft_strdup("(null)");
		return (0);
	}
	if (fmt->has_prec)
		s[fmt->prec] = '\0';
	pad = ft_fillstrnew(fmt->width - ft_strlen(s), ' ');
	fmt->retstr = join_pad(s, pad, fmt->flag->minus);
	free_strings(&s, &pad, NULL);
	return (0);
}

int		format_p(t_format *fmt, va_list args)
{
	uint64_t	num;
	char		*ret;
	char		*pad;
	int			chlen;

	num = va_arg(args, uint64_t);
	ret = (fmt->prec == 0 && num == 0) ? ft_strnew(0) : \
	ft_ull_itoa_base(num, 16, 0);
	chlen = ft_largest_int(fmt->prec, ft_strlen(ret));
	if (!fmt->has_width)
		fmt->width = ft_strlen(ret) + 2;
	pad = ft_fillstrnew(fmt->width - chlen - 2, ' ');
	while ((int)ft_strlen(ret) < chlen && (int)ft_strlen(ret) < fmt->prec)
		ret = ft_push_to_str_front(ret, '0');
	fmt->retstr = join_pad(ft_strjoin("0x", ret), pad, fmt->flag->minus);
	free_strings(&ret, &pad, NULL);
	return (0);
}

char	*get_decimal(long double num, int prec)
{
	int			i;
	uint64_t	first;
	long double	second;
	int			check;

	i = -1;
	first = (uint64_t)num;
	second = num - (long double)first;
	prec = (prec == -1) ? 6 : prec;
	while (++i <= prec)
		second *= 10;
	check = second;
	second /= 10;
	if (check % 10 > 4)
		second += 1;
	return (ft_ull_itoa_base((uint64_t)second, 10, 0));
}

int		format_f(t_format *fmt, va_list args)
{
	long double	num;
	char		*first;
	char		*second;
	char		*pad;
	int			chlen;

	if (fmt->lmod == 5)
		num = va_arg(args, long double);
	else
		num = (long double)va_arg(args, double);
	first = ft_ull_itoa_base(ft_makepos((uint64_t)num), 10, 0);
	chlen = ft_largest_int(fmt->prec, 6);
	chlen += ft_strlen(first) + 1 + has_lead(fmt, num);
	pad = ft_fillstrnew(fmt->width - chlen - has_lead(fmt, num), ' ');
	second = get_decimal(num > 0 ? num : -num, fmt->prec);
	if (has_lead(fmt, num))
		fmt->retstr = ft_strjoin(get_lead(fmt, num), \
		ft_strjoin(first, ft_strjoin(".", second)));
	else
		fmt->retstr = ft_strjoin(first, ft_strjoin(".", second));
	free_strings(&first, &second, &pad);
	return (0);
}
