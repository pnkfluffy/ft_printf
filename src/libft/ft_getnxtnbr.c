/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnxtnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 05:20:11 by jfelty            #+#    #+#             */
/*   Updated: 2019/09/18 06:47:56 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnxtnbr(char *str, char c)
{
	int i;
	int pos;
	int result;

	pos = 1;
	i = 0;
	result = 0;
	while (*str != c && !ft_isspace(*str) && *str)
	{
		if (*str == '-')
			pos *= -1;
		if (*str == '+' || *str == '-')
			str++;
		while ((*str >= '0') && (*str <= '9'))
		{
			result = (result * 10) + (*str - '0');
			str++;
		}
	}
	return (result * pos);
}
