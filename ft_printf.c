/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:39:02 by jfelty            #+#    #+#             */
/*   Updated: 2019/09/15 20:15:05 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	format_c(t_format *format, char c)
{
	format->left = 0;
	ft_putchar(c);
}

void	format_i(t_format *format, int i)
{
	format->left = 0;
	ft_putnbr(i);
}

int		is_argtype(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
	c == 'f' || c == '%' || c == 's' || c == 'c')
		return (1);
	return (0);
}

t_format	*ft_populate(const char *str, int curr, int end)
{
	t_format 	*format;

	if (!(format = (t_format *)ft_memalloc(sizeof(*format))))
		return (NULL);
	if (!(format->arg = (char *)ft_memalloc(sizeof(char) * end)))
		return (NULL);
	ft_strncpy(format->arg, &str[curr], end);
	format->type = str[curr + end];
	return (format);
}

//shorten and do with pointer arithmatic instead of iterators
int	ft_printf(const char *str, char c, int num)
{
	int 		i;
	int			end;
	t_format	*tmp;

	i = -1;
	end = 1;
	while (str[++i])
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		else
		{
			while (!(is_argtype(str[i + end])))		//need error checking
				end++;								//for faulty input
			ft_populate(str, i, end);
			tmp = ft_populate(str, i, end);
			if (tmp->type == 'c')
				format_c(tmp, c);
			if (tmp->type == 'i')
				format_i(tmp, num);
			i += end;
			end = 1;
		}
	}
	return (0);
}

int	main()
{
	ft_putstr("ft_printf:\t");
	ft_printf("THE letter %c and THE number %i", 'f', 42);

	// ft_putstr("\nprintf:\t\t");
	// printf("the LETTER %c and the NUMBER %i", 'f', 42);

	return (0);
}
