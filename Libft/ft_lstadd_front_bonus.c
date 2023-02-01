/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:43:06 by tchantro          #+#    #+#             */
/*   Updated: 2022/05/30 15:34:44 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main()
{
	t_list	*lst;

	lst = ft_lstnew("");
	ft_lstadd_front(&lst, ft_lstnew(""));
	while (lst != NULL)
	{
		printf("%s\n",(char*)lst->content);
		lst = lst->next;
	}
	return (0);
}*/
