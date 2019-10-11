/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:39:02 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/11 13:14:42 by jfelty           ###   ########.fr       */
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

void		print_params(t_format *curr)
{
	while (curr)
	{
		printf("STRING: '%s'\nRETSTR: '%s'\nTYPE:\t%c\thas: %6d\thas: %6d\nFORMAT:\t\twidth: %4d\tprec: %5d\nFLAGS:\t\t-: %d   +: %d   ' ': %d   0: %d  #: %c\n\n", \
		curr->fmt, curr->retstr, curr->type, curr->has_width, curr->has_precision, curr->width, curr->precision, \
		curr->flag->minus, curr->flag->plus, curr->flag->space, curr->flag->zero, curr->flag->pound);
		curr = curr->next;
	}
}

//shrink to 1 function with dispatch
int		get_choice(char type)
{
	if (type == 'c')
		return (0);
	else if (type == 's')
		return (1);
	else if (type == 'i')
		return (2);
	
	return (-1);
}

int		dispatch(t_print *print, va_list args)
{
	t_format	*format;
	int			choice;

	jump_function	*jump_to[3] = {
		print_c,
		print_s,
		print_i
	};

	format = print->fmts;
	while (format)
	{
		if ((choice = get_choice(format->type)) < 0)
			return (format->type);
		jump_to[choice](format, args);
		format = format->next;
	}
	return (0);
}

void		print_out(t_print *print)
{
	t_format	*curr_fmt;

	curr_fmt = print->fmts;
	while (*print->str)
	{
		if (*print->str != '%')
			ft_putchar(*print->str);
		else
		{
			ft_putstr(curr_fmt->retstr);
			print->str += ft_strlen(curr_fmt->fmt);
			curr_fmt = curr_fmt->next;
		}
		print->str++;
	}
}

int			ft_printf(const char *str, ...)
{
	va_list		args;
	t_print		*print;
	int			ret;

	va_start(args, str);
	print = initialize(str);

	if ((ret = dispatch(print, args)) != 0)
	{
		printf("Error, %c is not a conversion type!", ret);
		return (-1);
	}
//	print_params(print->fmts);

	print_out(print);
//	ret = ft_vfprintf(stdout, str, args);
	va_end(args);
	return (ret);
}

int	main()
{
	char *s = "hello";
	ft_printf("'%2.5s'", s);
	ft_printf("'%4.2s'", s);
	ft_printf("'%-2.1s'", s);
	ft_printf("'%1.2s'", s);
//	ft_printf("-first letter: '%-10c'\nsecond letter: '%10c'\ntest width:    '1234567890'\nthird letter: %c", 'a', 'b', 'c');
	return (0);
}
