/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:06:05 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/08 15:57:07 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_init	init;

	i = 1;
	if (!parsing_handler(argc, argv))
	{
		while (argv[i])
		{
			if (verif_arg(ft_atoi(argv[i]), i, &init))
				break ;
			i++;
		}
	}
	return (0);
}
