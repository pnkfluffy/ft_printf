/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:09:09 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/30 17:18:37 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		null_check(t_format *format)
{
	int i;

	i = 0;
	if (format->type == 'c')
	{
		while (format->retstr[i] && format->retstr[i + 1])
		{
			if (format->retstr[i] == '^' && format->retstr[i + 1] == '@')
				return (1);
			i++;
		}
	}
	return (0);
}

int		format_c(t_format *format, va_list args)
{
	char *c;
	char *padding;

	c = NULL;
	if (format->type != '%')
	{
		c = ft_fillstrnew(1, va_arg(args, int));
		if (ft_strlen(c) == 0)
		{
			ft_strdel(&c);
			c = ft_strdup("^@");
		}
	}
	else
		c = ft_fillstrnew(1, '%');
	if (!(format->has_width))
		format->width = 1;
	padding = ft_fillstrnew(format->width - 1, ' ');
	format->retstr = join_padding(c, padding, format->flag->minus);
	free(c);
	return (0);
}

int		format_s(t_format *format, va_list args)
{
	char *s;
	char *padding;

	if (!(s = ft_strdup(va_arg(args, char *))))
	{
		format->retstr = "(null)";
		return (0);
	}
	if (format->has_precision)
	{
		format->precision = format->precision > (int)ft_strlen(s) ? 0 : format->precision;
		s[format->precision] = '\0';
	}
	if (format->has_width)
	{
		if (format->has_precision)
		{
			if (format->precision > format->width)
				format->width = format->precision;
		}
		else
			format->has_width = format->width > (int)ft_strlen(s) ? 1 : 0;
	}
	padding = ft_fillstrnew(format->width - ft_strlen(s), ' ');
	format->retstr = join_padding(s, padding, format->flag->minus);
	free(s);
	return (0);
}

int		format_p(t_format *format, va_list args)
{
	uint64_t	long_address;
	char		*p;
	char 		*padding;

	long_address = va_arg(args, uint64_t);
	p = ft_strjoin("0x", ft_ull_itoa_base(long_address, 16, 0));
	if (!(format->has_width) || format->width < (int)ft_strlen(p))
		format->width = ft_strlen(p);
	padding = ft_fillstrnew(format->width - ft_strlen(p), ' ');
	format->retstr = join_padding(p, padding, format->flag->minus);
	free(p);
	return (0);
}
