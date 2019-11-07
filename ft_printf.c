/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:39:02 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 23:18:03 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize(t_print *print, const char *str)
{
	char	*curr_fmt;
	char	*tmp;

	curr_fmt = NULL;
	print->fmts = NULL;
	print->str = ft_strdup(str);
	tmp = (char *)print->str;
	while ((tmp = ft_strchr(tmp, '%')) != NULL)
	{
		tmp += get_format(tmp + 1, &curr_fmt);
		print->fmts = fill_format(print->fmts, curr_fmt);
		ft_strdel(&curr_fmt);
	}
}

int		print_char(t_format *format)
{
	if (ft_strlen(format->retstr) == 0)
	{
		ft_putchar((char)NULL);
		return (1);
	}
	else if (format->retstr[0] == ' ' && \
	format->retstr[ft_strlen(format->retstr) - 1] == ' ' && \
	(ft_strlen(format->retstr) > 1 || format->width > 1))
	{
		if (format->flag->minus)
		{
			ft_putchar((char)NULL);
			ft_putstr(format->retstr);
		}
		else
		{
			ft_putstr(format->retstr);
			ft_putchar((char)NULL);
		}
		return (ft_strlen(format->retstr) + 1);
	}
	ft_putstr(format->retstr);
	return (ft_strlen(format->retstr));
}

/*
**	void		print_params(t_format *curr)
**	{
**		while (curr)
**		{
**			printf("STRING: '%s'\nRETSTR: '%s'\nTYPE:\t%c\thas: %6d\thas: \
**			%6d\nFORMAT:\t\twidth: %4d\tprec: %5d\nFLAGS:\t\t-: %d   +: \
**			%d\t#: %8c\n\t\t0: %d   _: %d\tlenmod: %3d\n\n", \
**			curr->fmt, curr->retstr, curr->type, curr->has_width, \
**			curr->has_prec, curr->width, curr->prec, \
**			curr->flag->minus, curr->flag->plus, curr->flag->pound, \
**			curr->flag->zero, curr->flag->space, curr->lmod);
**			curr = curr->next;
**		}
**	}
*/

void	free_structs(t_print *print)
{
	t_format	*format;
	t_format	*prev;

	format = print->fmts;
	ft_strdel(&print->str);
	while (format)
	{
		if (format->retstr)
			ft_strdel(&format->retstr);
		ft_strdel(&format->fmt);
		prev = format;
		format = format->next;
		free(prev->flag);
		free(prev);
	}
	free(print);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	t_print		*print;
	int			ret;

	va_start(args, str);
	if (!(print = ft_memalloc(sizeof(t_print))))
		return (-1);
	initialize(print, str);
	if ((ret = dispatch(print, args)) != 0)
	{
		ft_putstr("Error, %");
		ft_putchar(ret);
		ft_putstr(" is not a conversion type!\n");
		free_structs(print);
		return (-1);
	}
	ret = print_out(print);
	va_end(args);
	free_structs(print);
	return (ret);
}
