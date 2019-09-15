/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:22:02 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/04 12:22:42 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	int i;
	int numwords;

	numwords = 0;
	i = 0;
	if (s[i] != c)
		numwords++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			numwords++;
		i++;
	}
	return (numwords);
}
