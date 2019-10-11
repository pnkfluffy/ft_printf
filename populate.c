/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:01:42 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/09 12:11:13 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	curr->flag->pound = 0;
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
		while (fmt[++i] == '0')
			curr->has_precision *= 10;
		curr->precision = ft_atoi(&fmt[i]);
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

int				get_format(char *str, char **fmt)
{
	char	*end;

	end = str;
	while (!(ft_strchr(CONV, *end)))
	{
		if (*end == '#')
			end++;
		end++;
	}
	end++;
	*fmt = ft_strnew(end - str);
	ft_strncpy(*fmt, str, end - str);
	return (end - str + 1);
}
