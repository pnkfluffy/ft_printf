/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_help2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:21:49 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 23:13:44 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_pad(t_format *format, char *ret)
{
	if (format->flag->zero && !format->flag->minus && \
	(int)ft_strlen(ret) > format->prec)
		return ('0');
	return (' ');
}

int		null_check(t_format *format)
{
	int	i;

	i = 0;
	if (ft_strlen(format->retstr) == 0 && format->prec == 0)
		return (1);
	else if (format->type == 's' && ft_strlen(format->retstr) == 0)
		return (1);
	return (0);
}

void	free_strings(char **str1, char **str2, char **str3)
{
	if (str1)
		ft_strdel(str1);
	if (str2)
		ft_strdel(str2);
	if (str3)
		ft_strdel(str3);
}

int		di_help(t_format *fmt, int64_t num, char **ret)
{
	if ((fmt->prec == 0 && num == 0) || num < -9223372036854775807)
		*ret = num < -9223372036854775807 ? ft_strdup("9223372036854775808") : \
		ft_strnew(0);
	else
		*ret = ft_ll_itoa_base(ft_makepos(num), 10, 0);
	return (ft_largest_int(fmt->prec + has_lead(fmt, num), ft_strlen(*ret)));
}

char	*f_help(t_format *fmt, long double num, char **f, char *s)
{
	char	*tmp;
	char	*temp;
	char	*ret;

	if (has_lead(fmt, num))
	{
		tmp = ft_strjoin(".", s);
		temp = ft_strjoin(*f, tmp);
		ret = ft_strjoin(get_lead(fmt, num), temp);
		free_strings(&tmp, &temp, NULL);
	}
	else
		ret = ft_strjoin(*f, ft_strjoin(".", s));
	ft_strdel(f);
	return (ret);
}
