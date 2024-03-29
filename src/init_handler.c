/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:46 by tchantro          #+#    #+#             */
/*   Updated: 2023/03/01 14:37:01 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int arg, int index_arg, t_data *data, int argc)
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
	if (argc == 5)
		data->must_eat = 0;
}

t_philo	*init_philo(t_data *data, t_chop *chop)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = malloc(sizeof (t_philo) * data->nbr_philo);
	if (!philo)
		return (NULL);
	while (i < data->nbr_philo)
	{
		philo[i].name = i + 1;
		philo[i].nbr_eat = 0;
		philo[i].data = data;
		philo[i].left_f = &chop[philo[i].name - 1];
		philo[i].right_f = &chop[philo[i].name % data->nbr_philo];
		i++;
	}
	data->death = 0;
	data->full = 0;
	return (philo);
}

t_chop	*init_chop(t_data *data)
{
	int			i;
	t_chop		*chop;

	i = 0;
	chop = malloc(sizeof (t_chop) * data->nbr_philo);
	if (!chop)
		return (NULL);
	while (i < data->nbr_philo)
	{
		chop[i].i_chop = 1;
		pthread_mutex_init(&chop[i].m_chop, NULL);
		i++;
	}
	return (chop);
}

void	init_threads(t_philo *philo, t_data *data)
{
	int		i;

	i = 0;
	init_mutex(data);
	while (i < data->nbr_philo)
	{
		philo[i].last_eat = philo->data->start;
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]))
		{
			while (i < 0)
			{
				pthread_join(philo[i].thread, NULL);
				i--;
			}
			destroy_mutex(data);
			printf("Thread Error\n");
			return ;
		}
		i++;
	}
	i = -1;
	while (++i < data->nbr_philo)
		pthread_join(philo[i].thread, NULL);
	destroy_mutex(data);
}
