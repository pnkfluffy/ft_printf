/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:51:28 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/04 12:19:21 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srce;
	size_t			i;

	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	i = -1;
	while (++i < n)
	{
		dest[i] = srce[i];
		if (srce[i] == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
