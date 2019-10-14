/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_diou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:55:53 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/13 18:34:55 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int			ft_largest_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int			ft_isneg(int a)
{
	if (a < 0)
		return (1);
	return (0);
}

int			ft_positive(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int			has_lead(t_format *format, int num)
{
	if (format->flag->plus || format->flag->space || ft_isneg(num))
		return (1);
	return (0);
}

char		*get_lead(t_flag *flag, int num)
{
	if (flag->plus)
		return (ft_isneg(num) ? "-" : "+");
	else if (ft_isneg(num))
		return ("-");
	else
		return (" ");
}

char		*push_to_str_front(char *str, char c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_memalloc(sizeof(char) * (ft_strlen(str) + 2));
	ret[i] = c;
	while (str[i])
	{
		ret[i + 1] = str[i];
		i++;
	}
	ret[i + 1] = '\0';
	free(str);
	return (ret);
}

char		get_pad(t_format *format, char *ret)
{
	if (format->flag->zero && !format->flag->minus && (int)ft_strlen(ret) > format->precision)
		return '0';
	return (' ');
}

int			format_d(t_format *format, va_list args)
{
	int		num;
	char	*ret;
	char	*padding;
	int		charwidth;

	num = (int)get_arg_signed(format->lmod, args);
	ret = ft_itoa(ft_positive(num));
	charwidth = ft_largest_int(format->precision + has_lead(format, num), ft_strlen(ret));
	padding = ft_fillstrnew(format->width - charwidth - has_lead(format, num), get_pad(format, ret));
	// padding = ft_fillstrnew(format->width - charwidth - has_lead(format, num), ' ');
	while ((int)ft_strlen(ret) < charwidth - has_lead(format, num))
		ret = push_to_str_front(ret, '0');
	if (has_lead(format, num))
	{
	//	charwidth++;	not necessary?
		format->retstr = ft_strjoin(get_lead(format->flag, num), join_padding(ret, padding, format->flag->minus));
	}
	else
		format->retstr = join_padding(ret, padding, format->flag->minus);
	return (0);
}
