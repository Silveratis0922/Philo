/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:32:47 by tchantro          #+#    #+#             */
/*   Updated: 2022/06/08 13:55:46 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = malloc(sizeof (char) * j + 1);
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = (char)(*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
