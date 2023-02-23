/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:20:29 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/23 17:53:05 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_sleeping(t_philo *philo)
{
	float	f;

	f = 0;
	printing(get_time() - philo->data->start, philo, SLEEP);
	while (f < philo->data->t_sleep)
	{
		pthread_mutex_lock(&philo->data->mutex);
		usleep(100);
		f = f + 0.1;
		if (get_time() - philo->last_eat > philo->data->t_die)
		{
			printing(get_time() - philo->data->start, philo, DIE);
			pthread_mutex_unlock(&philo->data->mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->mutex);
	}
	return (0);
}

int	is_eating(t_philo *philo)
{
	float	f;

	f = 0;
	philo->last_eat = get_time();
	printing(get_time() - philo->data->start, philo, EAT);
	while (f < philo->data->t_eat)
	{
		pthread_mutex_lock(&philo->data->mutex);
		usleep(100);
		f = f + 0.1;
		if (get_time() - philo->last_eat > philo->data->t_die)
		{
			printing(get_time() - philo->data->start, philo, DIE);
			pthread_mutex_unlock(&philo->data->mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->mutex);
	}
	return (0);
}
