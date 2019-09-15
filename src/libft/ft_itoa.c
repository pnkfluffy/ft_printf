/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:30:21 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/07 11:49:42 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_numlength(n) - 1;
	if (!(str = (char *)malloc(sizeof(char) * ft_numlength(n) + 1)))
		return (NULL);
	str[i + 1] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	str[i] = n + '0';
	return (str);
}
