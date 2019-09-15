/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:54:21 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/05 11:16:10 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	if (ft_strlen(substr) == 0)
		return ((char *)str);
	while (str[j] && n > 0)
	{
		i = 0;
		while (substr[i] == str[i + j] && i + j < n)
		{
			i++;
			if (i == ft_strlen(substr))
				return ((char *)str + j);
		}
		j++;
	}
	return (0);
}
