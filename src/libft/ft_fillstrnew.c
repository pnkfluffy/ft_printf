/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstrnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:18:21 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/11 13:18:29 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillstrnew(int width, char fill)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_strnew(width + 1);
	while (++i < width)
		str[i] = fill;
	return (str);
}