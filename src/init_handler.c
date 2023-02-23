/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:46 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/23 15:22:41 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		philo[i].die = 0;
		philo[i].data = data;
		philo[i].left_f = &chop[philo->name - 1];
		philo[i].right_f = &chop[philo->name % data->nbr_philo];
		i++;
	}
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
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->nbr_philo)
	{
		philo[i].last_eat = philo->data->start;
		pthread_create(&philo->thread, NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(philo->thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&data->mutex);
}
