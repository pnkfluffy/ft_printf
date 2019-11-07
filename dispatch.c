/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:14:15 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/07 12:05:38 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_choice(t_format *format)
{
	if (format->type == 'c' || format->type == '%')
		return (0);
	else if (format->type == 's')
		return (1);
	else if (format->type == 'p')
		return (2);
	else if (format->type == 'i' || format->type == 'd')
		return (3);
	else if (format->type == 'o')
		return (4);
	else if (format->type == 'u')
		return (5);
	else if (format->type == 'x' || format->type == 'X')
		return (6);
	else if (format->type == 'f')
		return (7);
	else
		return (-1);
}

int		dispatch(t_print *print, va_list args)
{
	t_format		*format;
	int				choice;
	jump_function	*jump_to[8] = {
					format_c,
					format_s,
					format_p,
					format_di,
					format_o,
					format_u,
					format_xx,
					format_f
	};

	format = print->fmts;
	while (format)
	{
		if ((choice = get_choice(format)) < 0)
			return (format->type);
		jump_to[choice](format, args);
		format = format->next;
	}
	return (0);
}

int		get_format(char *str, char **fmt)
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
