/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:15:53 by jfelty            #+#    #+#             */
/*   Updated: 2019/09/07 14:11:51 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char *strspace;

	if (!(strspace = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	return (ft_memset(strspace, (int)'\0', len + 1));
}
