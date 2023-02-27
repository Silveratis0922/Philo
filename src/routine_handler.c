/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:07:32 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/27 17:55:18 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	main_routine_with_four(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_death);
	while (philo->data->death == 0)
	{
		pthread_mutex_unlock(&philo->data->m_death);
		if (take_left_chop(philo))
			break ;
		if (take_right_chop(philo))
			break ;
		if (is_eating(philo))
			break ;
		put_chop(philo);
		if (is_sleeping(philo))
			break ;
		printing(get_time() - philo->data->start, philo, THINK);
		pthread_mutex_lock(&philo->data->m_death);
	}
	pthread_mutex_unlock(&philo->data->m_death);
}

void	main_routine_with_five(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&philo->data->m_full);
	pthread_mutex_lock(&philo->data->m_death);
	while (philo->data->death == 0 && data->full != data->nbr_philo)
	{
		pthread_mutex_unlock(&philo->data->m_full);
		pthread_mutex_unlock(&philo->data->m_death);
		if (take_left_chop(philo))
			break ;
		if (take_right_chop(philo))
			break ;
		if (is_eating(philo))
			break ;
		put_chop(philo);
		if (is_sleeping(philo))
			break ;
		printing(get_time() - philo->data->start, philo, THINK);
		pthread_mutex_lock(&philo->data->m_full);
		pthread_mutex_lock(&philo->data->m_death);
	}
	pthread_mutex_unlock(&philo->data->m_full);
	pthread_mutex_unlock(&philo->data->m_death);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	time_t		time;

	philo = (t_philo *)arg;
	if (philo->name % 2 == 0 || philo->name == philo->data->nbr_philo)
	{
		time = get_time();
		printing(get_time() - philo->data->start, philo, THINK);
		while (get_time() - time < philo->data->t_eat)
		{
			if (get_time() - philo->last_eat > philo->data->t_die)
				return (is_dead(philo), NULL);
			usleep(100);
		}
	}
	if (philo->data->must_eat == 0)
		main_routine_with_four(philo);
	else
		main_routine_with_five(philo, philo->data);
	return (NULL);
}

int	take_left_chop(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->left_f->m_chop);
		if (philo->left_f->i_chop == 1)
		{
			philo->left_f->i_chop = 0;
			pthread_mutex_unlock(&philo->left_f->m_chop);
			printing(get_time() - philo->data->start, philo, FORK);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&philo->left_f->m_chop);
			usleep(100);
			if (get_time() - philo->last_eat > philo->data->t_die)
				return (is_dead(philo), 1);
		}
	}
	return (0);
}

int	take_right_chop(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->right_f->m_chop);
		if (philo->right_f->i_chop == 1)
		{
			philo->right_f->i_chop = 0;
			pthread_mutex_unlock(&philo->right_f->m_chop);
			printing(get_time() - philo->data->start, philo, FORK);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&philo->right_f->m_chop);
			usleep(100);
			if (get_time() - philo->last_eat > philo->data->t_die)
				return (is_dead(philo), 1);
		}
	}
	return (0);
}
