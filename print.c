/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:17:50 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 23:19:58 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

int		print_out(t_print *print)
{
	t_format	*curr_fmt;
	int			ret;
	int			i;

	ret = 0;
	i = -1;
	curr_fmt = print->fmts;
	while (print->str[++i])
	{
		if (print->str[i] != '%')
		{
			ft_putchar(print->str[i]);
			ret++;
		}
		else
		{
			if (curr_fmt->type == 'c')
				ret += print_char(curr_fmt);
			else
				ret += print_str(curr_fmt->retstr);
			i += ft_strlen(curr_fmt->fmt);
			curr_fmt = curr_fmt->next;
		}
	}
	return (ret);
}
