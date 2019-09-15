/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:29 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/04 18:18:06 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srce;

	if (!n || dst == src)
		return (dst);
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	i = -1;
	while (++i < n)
		dest[i] = srce[i];
	return (dst);
}
