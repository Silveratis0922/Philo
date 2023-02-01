/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:13:46 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/06 01:20:10 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_list;

	if (lst == NULL)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		ft_lstadd_back(&new_list, ft_lstnew(f(lst->content)));
		if (!ft_lstlast(new_list))
		{
			ft_lstclear(&new_list, del);
		}
		lst = lst->next;
	}
	return (new_list);
}
