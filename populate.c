/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:01:42 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 23:22:34 by jfelty           ###   ########.fr       */
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
			curr->flag->pound = 1;
	}
	return (i);
}

void			initialize_values(t_format *curr)
{
	curr->retstr = NULL;
	curr->type = (char)NULL;
	curr->has_width = -1;
	curr->has_prec = -1;
	curr->width = -1;
	curr->prec = -1;
	curr->lmod = 0;
	curr->flag->minus = 0;
	curr->flag->plus = 0;
	curr->flag->zero = 0;
	curr->flag->space = 0;
	curr->flag->pound = 0;
	curr->next = NULL;
}

int				populate_lenmod(t_format *curr, char *fmt)
{
	int i;

	i = 0;
	if ((fmt[0] == 'h' && fmt[1] == 'h') || (fmt[0] == 'l' && fmt[1] == 'l'))
	{
		curr->lmod = (fmt[0] == 'h') ? 1 : 4;
		i = 2;
	}
	else if (fmt[0] == 'h' || fmt[0] == 'l' || fmt[0] == 'L')
	{
		i = 1;
		if (fmt[0] == 'h')
			curr->lmod = 2;
		else if (fmt[0] == 'l')
			curr->lmod = 3;
		else if (fmt[0] == 'L')
			curr->lmod = 5;
	}
	else
		curr->lmod = 0;
	return (i);
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
	curr->has_prec = (fmt[i] == '.') ? 1 : 0;
	if (curr->has_prec)
	{
		curr->prec = ft_isdigit(fmt[++i]) ? ft_atoi(&fmt[i]) : 0;
		while (ft_isdigit(fmt[i]))
			i++;
	}
	i += populate_lenmod(curr, &fmt[i]);
	curr->type = fmt[i];
}

t_format		*fill_format(t_format *head, char *fmt)
{
	t_format	*curr;

	if (!head)
	{
		if (!(head = ft_memalloc(sizeof(t_format))) || \
		!(head->flag = ft_memalloc(sizeof(t_flag))))
			return (NULL);
		head->fmt = ft_strdup(fmt);
		populate_format(head, head->fmt);
	}
	else
	{
		curr = head;
		while (curr->next)
			curr = curr->next;
		if (!(curr->next = ft_memalloc(sizeof(t_format))) || \
		!(curr->next->flag = ft_memalloc(sizeof(t_flag))))
			return (NULL);
		curr->next->fmt = ft_strdup(fmt);
		populate_format(curr->next, curr->next->fmt);
	}
	return (head);
}
