/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:20:29 by tchantro          #+#    #+#             */
/*   Updated: 2023/03/01 15:14:44 by tchantro         ###   ########.fr       */
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
			pthread_mutex_unlock(&philo->data->mutex);
			return (is_dead(philo), 1);
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
	if (philo->data->must_eat != 0)
	{
		philo->nbr_eat++;
		if (philo->nbr_eat == philo->data->must_eat)
			need_place(philo);
	}
	while (get_time() - time < philo->data->t_eat)
	{
		pthread_mutex_lock(&philo->data->mutex);
		if (get_time() - philo->last_eat > philo->data->t_die)
		{
			pthread_mutex_unlock(&philo->data->mutex);
			return (is_dead(philo), 1);
		}
		pthread_mutex_unlock(&philo->data->mutex);
		usleep(100);
	}
	return (0);
}

void	is_dead(t_philo *philo)
{
	printing(get_time() - philo->data->start, philo, DIE);
	pthread_mutex_lock(&philo->data->m_death);
}

void	put_chop(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_f->m_chop);
	philo->left_f->i_chop = 1;
	pthread_mutex_unlock(&philo->left_f->m_chop);
	pthread_mutex_lock(&philo->right_f->m_chop);
	philo->right_f->i_chop = 1;
	pthread_mutex_unlock(&philo->right_f->m_chop);
}
