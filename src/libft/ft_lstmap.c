/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:02:22 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/07 14:06:17 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	newlist = f(lst);
	head = newlist;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlist->next = f(lst)))
		{
			free(newlist->next);
			return (NULL);
		}
		newlist = newlist->next;
	}
	return (head);
}
