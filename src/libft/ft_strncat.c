/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:06:20 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/04 16:32:52 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (dest[i])
		i++;
	while (src[b] && n > 0)
	{
		dest[i + b] = src[b];
		b++;
		n--;
	}
	dest[i + b] = '\0';
	return (dest);
}
