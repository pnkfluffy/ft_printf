/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_str_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:18:27 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/25 14:18:36 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_push_to_str_front(char *str, char c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_memalloc(sizeof(char) * (ft_strlen(str) + 2));
	ret[i] = c;
	while (str[i])
	{
		ret[i + 1] = str[i];
		i++;
	}
	ret[i + 1] = '\0';
	free(str);
	return (ret);
}
