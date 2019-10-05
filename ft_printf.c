/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:39:02 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/04 20:21:37 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int				get_format(char *str, char **fmt)
// {
// 	char	*end;

// 	str++;
// 	end = str;
// 	while (!(ft_strchr(CONV, *end)))
// 	{
// 		if (*end == '#')
// 			end++;
// 		end++;
// 	}
// 	*fmt = ft_strnew(end - str);
// 	ft_strncpy(*fmt, str, end - str);
// 	return (end - str);
// }

int				get_format(char *str, char **fmt)
{
	char	*end;

	end = str + 1;
	while (!(ft_strchr(CONV, *end)))
	{
		if (*end == '#')
			end++;
		end++;
	}
	end++;
	*fmt = ft_strnew(end - str);
	ft_strncpy(*fmt, str, end - str);
	return (end - str);
}

int				populate_flags(t_format *curr, char *fmt)
{
	int i;

	i = -1;
	while (ft_strchr(FLAG, fmt[++i]))
	{
		if (fmt[i] == '-')
			curr->flag->minus = 1;
		else if (fmt[i] == '+')
			curr->flag->plus = 1;
		else if (fmt[i] == '0')
			curr->flag->zero = 1;
		else if (fmt[i] == ' ')
			curr->flag->space = 1;
		else if (fmt[i] == '#')
			curr->flag->pound = fmt[++i];
	}
	return (i);
}

void			initialize_values(t_format *curr)
{
	curr->retstr = NULL;
	curr->type = (char)NULL;
	curr->has_width = -1;
	curr->has_precision = -1;
	curr->width = -1;
	curr->precision = -1;
	curr->flag->minus = 0;
	curr->flag->plus = 0;
	curr->flag->zero = 0;
	curr->flag->space = 0;
	curr->flag->pound = (char)NULL;
	curr->next = NULL;
}

void			populate_format(t_format *curr, char *fmt)
{
	int		i;

	initialize_values(curr);
	i = populate_flags(curr, fmt);
	curr->has_width = ft_isdigit(fmt[i]) ? 1 : 0;
	if (curr->has_width)
	{
		curr->width = ft_atoi(&fmt[i]);
		while (ft_isdigit(fmt[i]))
			i++;
	}
	curr->has_precision = (fmt[i] == '.') ? 1 : 0;
	if (curr->has_precision)
	{
		//DOSNT WORK FIX, THATS NOT HOW YOU READ PRECISION
		curr->precision = ft_atoi(&fmt[++i]);
		while (ft_isdigit(fmt[i]))
			i++;
	}
	curr->type = fmt[i];
}

t_format		*fill_format(t_format *head, char *fmt)
{
	t_format	*curr;

	if (!head)
	{
		if (!(head = ft_memalloc(sizeof(t_format))) || !(head->flag = ft_memalloc(sizeof(t_flag))))
			return (NULL);
		head->fmt = ft_strdup(fmt);
		populate_format(head, head->fmt);
	}
	else
	{
		curr = head;
		while (curr->next)
			curr = curr->next;
		if (!(curr->next = ft_memalloc(sizeof(t_format))) || !(curr->next->flag = ft_memalloc(sizeof(t_flag))))
			return (NULL);
		curr->next->fmt = ft_strdup(fmt);
		populate_format(curr->next, curr->next->fmt);
	}
	return (head);
}

t_print		*initialize(const char *str)
{
	t_print	*print;
	char	*curr_fmt;
	char	*tmp;

	if (!(print = ft_memalloc(sizeof(t_print))))
		return (NULL);
	curr_fmt = NULL;
	print->args = NULL;
	print->str = ft_strdup(str);
	tmp = (char *)print->str;
	while ((tmp = ft_strchr(tmp, '%')) != NULL)
	{
		tmp += get_format(tmp + 1, &curr_fmt);
		print->args = fill_format(print->args, curr_fmt);
		ft_strdel(&curr_fmt);
	}
	return (print);
}

void		print_params(t_format *curr)
{
	while (curr)
	{
		printf("string:\t%s\t\t\t\t\t\ttype: %c\nFORMAT:\t\twidth?: %d\twidth: %d\tprec?: %d\tprec: %d\nFLAGS:\t-: %d\t+: %d\t\t' ': %d\t\t0: %d\t\t#: %c\n\n", \
		curr->fmt, curr->type, curr->has_width, curr->width, curr->has_precision, curr->precision, \
		curr->flag->minus, curr->flag->plus, curr->flag->space, curr->flag->zero, curr->flag->pound);
		curr = curr->next;
	}
}

int			ft_printf(const char *str, ...)
{
	va_list		args;
	t_print		*print;
	int			ret = 1;

	va_start(args, str);
	print = initialize(str);

	print_params(print->args);
//	ret = ft_vfprintf(stdout, str, args);
	va_end(args);
	return (ret);
}

int	main()
{
	ft_printf("%0.5c % -+#gs %c %-10.009x %%", "hi", "there", 5);
}

/*
// void	format_c(t_format *format, char c)
// {
// 	format->left = 0;
// 	ft_putchar(c);
// }

// void	format_i(t_format *format, int i)
// {
// 	format->left = 0;
// 	ft_putnbr(i);
// }

// int		is_argtype(char c)
// {
// 	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
// 	c == 'f' || c == '%' || c == 's' || c == 'c')
// 		return (1);
// 	return (0);
// }

// t_format	*ft_populate(const char *str, int curr, int end)
// {
// 	t_format 	*format;

// 	if (!(format = (t_format *)ft_memalloc(sizeof(*format))))
// 		return (NULL);
// 	if (!(format->arg = (char *)ft_memalloc(sizeof(char) * end)))
// 		return (NULL);
// 	ft_strncpy(format->arg, &str[curr], end);
// 	format->type = str[curr + end];
// 	return (format);
// }

// //shorten and do with pointer arithmatic instead of iterators
// int	ft_printf(const char *str, char c, int num)
// {
// 	int 		i;
// 	int			end;
// 	t_format	*tmp;

// 	i = -1;
// 	end = 1;
// 	while (str[++i])
// 	{
// 		if (str[i] != '%')
// 			ft_putchar(str[i]);
// 		else
// 		{
// 			while (!(is_argtype(str[i + end])))		//need error checking
// 				end++;								//for faulty input
// 			ft_populate(str, i, end);
// 			tmp = ft_populate(str, i, end);
// 			if (tmp->type == 'c')
// 				format_c(tmp, c);
// 			if (tmp->type == 'i')
// 				format_i(tmp, num);
// 			i += end;
// 			end = 1;
// 		}
// 	}
// 	return (0);
// }

// int	main()
// {
// 	ft_putstr("ft_printf:\t");
// 	ft_printf("THE letter %c and THE number %i", 'f', 42);

// 	ft_putstr("\nprintf:\t\t");
// 	printf("the LETTER %c and the NUMBER %i", 'f', 42);

// 	return (0);
// }
*/