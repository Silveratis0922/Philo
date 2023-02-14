/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:46 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/14 17:28:04 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

extern int test;

void	init_data(int arg, int index_arg, t_data *data)
{
	if (index_arg == 1)
		data->nbr_philo = arg;
	else if (index_arg == 2)
		data->t_die = arg;
	else if (index_arg == 3)
		data->t_eat = arg;
	else if (index_arg == 4)
		data->t_sleep = arg;
	else if (index_arg == 5)
		data->must_eat = arg;
}

void	init_threads(t_data *data)
{
	pthread_t	tab[data->nbr_philo];
	pthread_mutex_t	mutex;
	int		i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < data->nbr_philo)
	{
		pthread_create(&tab[i], NULL, &start_routine, &mutex);
		printf("Tread %d created\n", i);
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(tab[i], NULL);
		printf("thread %d finished\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("test = %d\n", test);
}
