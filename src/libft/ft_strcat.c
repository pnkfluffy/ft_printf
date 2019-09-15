/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:56:49 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/04 12:20:37 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *source)
{
	int i;
	int b;

	i = 0;
	b = -1;
	while (dest[i])
		i++;
	while (source[++b])
		dest[i + b] = source[b];
	dest[i + b] = '\0';
	return (dest);
}
