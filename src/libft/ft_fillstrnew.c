/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstrnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:18:21 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 23:34:52 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillstrnew(int width, char fill)
{
	char	*str;
	int		i;

	if (width < 1)
		return (ft_strnew(0));
	i = -1;
	str = ft_strnew(width + 1);
	while (++i < width)
		str[i] = fill;
	return (str);
}
