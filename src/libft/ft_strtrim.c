/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:58:17 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/07 18:41:42 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		x;
	int		y;
	char	*newstr;

	if (!s)
		return (NULL);
	x = 0;
	y = 0;
	while (s[x] && ft_isspace(s[x]))
		x++;
	y = ft_strlen(&s[x]) - 1;
	while (s[x] && ft_isspace(s[y + x]))
		y--;
	if (!(newstr = ft_strnew(y + 1)))
		return (NULL);
	ft_strncpy(newstr, (s + x), (y + 1));
	return (newstr);
}
