/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:54:09 by tchantro          #+#    #+#             */
/*   Updated: 2022/07/16 15:05:04 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	k;
	int	a;

	i = 0;
	j = 0;
	k = 1;
	a = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '+' || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			k = k * -1;
		i++;
		j++;
	}
	if (j >= 2)
		return (0);
	while (nptr[i] >= 48 && nptr[i] <= 57)
		a = a * 10 + nptr[i++] - 48;
	return (a * k);
}
/*
int	main()
{
	char tab[] = "		 	-0";

	printf("%d\n", ft_atoi(tab));
	printf("%d\n", atoi(tab));
	return (0);	
}*/
