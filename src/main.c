/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:06:05 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/14 17:24:50 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	test = 0;

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_data	data;
	time_t	start_time;

	i = 1;
	if (!parsing_handler(argc, argv))
	{
		while (argv[i])
		{
			if (verif_arg(ft_atoi(argv[i]), i, &data))
				return (1);
			i++;
		}
		j = 0;
		init_threads(&data);
		start_time = get_time();
		while (j < 100000000)
			j++;
		printf("%ld ms\n", get_time() - start_time);
	}
	return (0);
}
