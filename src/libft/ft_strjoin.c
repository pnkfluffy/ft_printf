/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:30:58 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/28 12:56:10 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		x;
	int		y;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = ft_strnew(len1 + len2);
	if (!newstr)
		return (NULL);
	x = -1;
	y = -1;
	while (++x < len1)
		newstr[x] = s1[x];
	while (++y < len2)
		newstr[x++] = s2[y];
	return (newstr);
}
