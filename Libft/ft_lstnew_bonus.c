/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:29:43 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/06 01:07:37 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof (t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
