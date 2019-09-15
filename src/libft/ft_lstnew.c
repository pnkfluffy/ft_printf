/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:59:49 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/07 14:00:22 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list *newlist;

	if (!(newlist = (t_list *)ft_memalloc(sizeof(*newlist))))
		return (NULL);
	if (!(content))
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		if (!(newlist->content = (void *)malloc(size)))
		{
			free(newlist);
			return (NULL);
		}
		ft_memcpy(newlist->content, content, size);
		newlist->content_size = size;
	}
	newlist->next = NULL;
	return (newlist);
}
