/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:20:29 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/24 17:35:16 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_sleeping(t_philo *philo)
{
	time_t	time;

	time = get_time();
	printing(get_time() - philo->data->start, philo, SLEEP);
	while (get_time() - time < philo->data->t_sleep)
	{
		pthread_mutex_lock(&philo->data->mutex);
		if (get_time() - philo->last_eat > philo->data->t_die)
		{
			printing(get_time() - philo->data->start, philo, DIE);
			philo->data->death++;
			pthread_mutex_unlock(&philo->data->mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->mutex);
		usleep(100);
	}
	return (0);
}

int	is_eating(t_philo *philo)
{
	time_t	time;

	time = get_time();
	philo->last_eat = get_time();
	printing(get_time() - philo->data->start, philo, EAT);
	philo->nbr_eat++;
	while (get_time() - time < philo->data->t_eat)
	{
		pthread_mutex_lock(&philo->data->mutex);
		if (get_time() - philo->last_eat > philo->data->t_die)
		{
			printing(get_time() - philo->data->start, philo, DIE);
			philo->data->death++;
			pthread_mutex_unlock(&philo->data->mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->mutex);
		usleep(100);
	}
	return (0);
}

int	is_thinking(t_philo *philo)
{
	time_t	time;

	time = get_time();
	printing(get_time() - philo->data->start, philo, THINK);
	while (get_time() - time < philo->data->t_eat)
	{
		if (get_time() - philo->last_eat > philo->data->t_die)
		{
			printing(get_time() - philo->data->start, philo, DIE);
			philo->data->death++;
			return (1);
		}
		usleep(100);
	}
	return (0);
}
