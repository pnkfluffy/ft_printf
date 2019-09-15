/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:49:52 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/07 10:40:04 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	x;
	size_t	y;
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	x = destlen;
	y = 0;
	if (n < destlen + 1)
		return (srclen + n);
	if (n > destlen + 1)
	{
		while (x < n - 1)
			*(dest + x++) = *(src + y++);
		*(dest + x) = '\0';
	}
	return (destlen + srclen);
}
