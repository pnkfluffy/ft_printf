/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:32:01 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/05 09:57:25 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	wordend;
	size_t	x;
	char	**r;

	i = 0;
	x = 0;
	wordend = 0;
	if (!s)
		return (NULL);
	if (!(r = (char **)ft_memalloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			while (s[i + wordend] != c && s[i + wordend])
				wordend++;
			r[x++] = ft_strsub(s, i, wordend);
			i += wordend - 1;
			wordend = 0;
		}
		i++;
	}
	return (r);
}
