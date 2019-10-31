/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:39:02 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/30 19:16:30 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		*initialize(const char *str)
{
	t_print	*print;
	char	*curr_fmt;
	char	*tmp;

	if (!(print = ft_memalloc(sizeof(t_print))))
		return (NULL);
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
	return (print);
}

//shrink to 1 function with dispatch
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
	else
		return (-1);
}

int		dispatch(t_print *print, va_list args)
{
	t_format	*format;
	int			choice;

	jump_function	*jump_to[7] = {
		format_c,
		format_s,
		format_p,
		format_di,
		format_o,
		format_u,
		format_xX
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

int		print_out(t_print *print)
{
	t_format	*curr_fmt;
	int			ret;

	ret = 0;
	curr_fmt = print->fmts;
	while (*print->str)
	{
		if (*print->str != '%')
		{
			ft_putchar(*print->str);
			ret++;
		}
		else
		{
			ft_putstr(curr_fmt->retstr);
			ret += ft_strlen(curr_fmt->retstr) - null_check(curr_fmt);
			print->str += ft_strlen(curr_fmt->fmt);
			curr_fmt = curr_fmt->next;
		}
		print->str++;
	}
	return (ret);
}

// void		print_params(t_format *curr)
// {
// 	while (curr)
// 	{
// 		printf("STRING: '%s'\nRETSTR: '%s'\nTYPE:\t%c\thas: %6d\thas: %6d\nFORMAT:\t\twidth: %4d\tprec: %5d\nFLAGS:\t\t-: %d   +: %d\t#: %8c\n\t\t0: %d   _: %d\tlenmod: %3d\n\n", \
// 		curr->fmt, curr->retstr, curr->type, curr->has_width, curr->has_precision, curr->width, curr->precision, \
// 		curr->flag->minus, curr->flag->plus, curr->flag->pound, curr->flag->zero, curr->flag->space, curr->lmod);
// 		curr = curr->next;
// 	}
// }

int			ft_printf(const char *str, ...)
{
	va_list		args;
	t_print		*print;
	int			ret;

	va_start(args, str);
	print = initialize(str);

	if ((ret = dispatch(print, args)) != 0)
	{
		ft_putstr("Error, %");
		ft_putchar(ret);
		ft_putstr(" is not a conversion type!\n");
		return (-1);
	}
	// print_params(print->fmts);

	ret = print_out(print);
	va_end(args);
	return (ret);
}
