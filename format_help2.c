/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_help2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:21:49 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 21:33:25 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		get_pad(t_format *format, char *ret)
{
	if (format->flag->zero && !format->flag->minus && \
	(int)ft_strlen(ret) > format->prec)
		return ('0');
	return (' ');
}

int			null_check(t_format *format)
{
	int	i;

	i = 0;
	if (ft_strlen(format->retstr) == 0 && format->prec == 0)
		return (1);
	else if (format->type == 's' && ft_strlen(format->retstr) == 0)
		return (1);
	return (0);
}

int				get_format(char *str, char **fmt)
{
	char	*end;

	end = str;
	while (!(ft_strchr(CONV, *end)))
		end++;
	end++;
	*fmt = ft_strnew(end - str);
	ft_strncpy(*fmt, str, end - str);
	return (end - str + 1);
}

void			free_strings(char **str1, char **str2, char **str3)
{
	if (str1)
		ft_strdel(str1);
	if (str2)
		ft_strdel(str2);
	if (str3)
		ft_strdel(str3);
}

int				fmt_di_help(t_format *fmt, int64_t num, char **ret)
{
	if ((fmt->prec == 0 && num == 0) || num < -9223372036854775807)
		*ret = num < -9223372036854775807 ? ft_strdup("9223372036854775808") : \
		ft_strnew(0);
	else
		*ret = ft_ll_itoa_base(ft_makepos(num), 10, 0);
	return (ft_largest_int(fmt->prec + has_lead(fmt, num), ft_strlen(*ret)));
}
