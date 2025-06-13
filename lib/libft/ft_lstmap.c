/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomaia <joaomaia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:39:22 by jomaia            #+#    #+#             */
/*   Updated: 2025/04/23 11:50:34 by joaomaia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list	*ptr;
	t_list	*new;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	ptr = lst;
	while (ptr)
	{
		new = ft_lstnew(f(ptr->content));
		if (!new)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		ptr = ptr ->next;
	}
	return (res);
}
