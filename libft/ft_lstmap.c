/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:52:55 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/14 20:09:07 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	newl = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&newl, del);
			return (NULL);
		}
		ft_lstadd_back(&newl, tmp);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (newl);
}
