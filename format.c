/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:09:09 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/11 13:09:37 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fillstrnew(int width, char fill)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_strnew(width + 1);
	while (++i < width)
		str[i] = fill;
	return (str);
}

int		print_c(t_format *format, va_list args)
{
	char c;
	char *filler;

	c = va_arg(args, int);
	if (!(format->has_width))
		format->width = 1;
	filler = ft_fillstrnew(format->width - 1, ' ');
	if (format->flag->minus)
		format->retstr = ft_strjoin(&c, filler);
	else
		format->retstr = ft_strjoin(filler, &c);
	return (0);
}

int		print_s(t_format *format, va_list args)
{
	char *s;
	char *filler;

	s = ft_strdup(va_arg(args, char *));
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
	filler = ft_fillstrnew(format->width - ft_strlen(s), ' ');
	if (format->flag->minus)
		format->retstr = ft_strjoin(s, filler);
	else
		format->retstr = ft_strjoin(filler, s);
	free(s);
	return (0);
}

int		print_i(t_format *format, va_list args)
{
	int i;
	i = va_arg(args, int);
	format->width += 0;
	return (0);
}
