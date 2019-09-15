/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:00:15 by jfelty            #+#    #+#             */
/*   Updated: 2019/09/07 20:53:36 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s && (substr = (char *)ft_memalloc(sizeof(char) * len + 1)))
	{
		i = 0;
		while (i < len)
		{
			substr[i] = s[i + start];
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
