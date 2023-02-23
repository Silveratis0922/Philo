/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:07:32 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/23 17:12:16 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	float		f;

	f = 0;
	philo = (t_philo *)arg;
	if (philo->name % 2 == 0 || philo->name == philo->data->nbr_philo)
	{
		printing(get_time() - philo->data->start, philo, THINK);
		while (f < philo->data->t_eat)
		{
			if (get_time() - philo->last_eat > philo->data->t_die)
			{
				printing(get_time() - philo->data->start, philo, DIE);
				return (NULL);
			}
			usleep(100);
			f = f + 0.2;
		}
	}
	while (1)
	{
		if (take_left_chop(philo))
			break ;
		if (take_right_chop(philo))
			break ;
	}
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
			{
				printing(get_time() - philo->data->start, philo, DIE);
				return (1);
			}
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
			if (is_eating(philo))
				return (1);
			put_chop(philo);
			if (is_sleeping(philo))
				return (1);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&philo->right_f->m_chop);
			usleep(100);
			if (get_time() - philo->last_eat > philo->data->t_die)
			{
				printing(get_time() - philo->data->start, philo, DIE);
				return (1);
			}
		}
	}
	return (0);
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
