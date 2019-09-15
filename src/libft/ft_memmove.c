/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:03:48 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/07 09:21:40 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*srce;
	int				i;

	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	i = -1;
	if (srce < dest)
		while ((int)(--len) >= 0)
			dest[len] = srce[len];
	else if (srce > dest)
		while (++i < (int)len)
			dest[i] = srce[i];
	return (dst);
}
