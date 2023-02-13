/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:06:05 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/13 18:03:57 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_data	data;
	time_t	start_time;
	pthread_t	*tab;

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
		tab = malloc(sizeof(pthread_t) * data.nbr_philo);
		if (!tab)
			printf("RIP\n");
		start_time = get_time();
		while (j < 100000000)
			j++;
		printf("%ld ms\n", get_time() - start_time);
	}
	return (0);
}
