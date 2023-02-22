/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:07:32 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/22 17:52:34 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->name % 2 == 1)
	{
		while (1)
		{
			take_left_chop(philo);
			take_right_chop(philo);
			break ;
		}
	}
	pthread_mutex_unlock(&philo->data->mutex);
	return (NULL);
}

void	take_left_chop(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->left_f->m_chop);
		if (philo->left_f->i_chop == 1)
		{
			philo->left_f->i_chop = 0;
			pthread_mutex_unlock(&philo->left_f->m_chop);
			printing(get_time() - philo->data->start, philo->name, 1);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&philo->left_f->m_chop);
			usleep(100);
		}
	}
}

void	take_right_chop(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->right_f->m_chop);
		if (philo->right_f->i_chop == 1)
		{
			philo->right_f->i_chop = 0;
			pthread_mutex_unlock(&philo->right_f->m_chop);
			printing(get_time() - philo->data->start, philo->name, 1);
			printing(get_time() - philo->data->start, philo->name, 2);
			//usleep;
			put_chop(philo);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&philo->right_f->m_chop);
			usleep(100);
		}
	}
}

void	put_chop(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_f->m_chop);
	philo->left_f->i_chop = 1;
	pthread_mutex_unlock(&philo->left_f->m_chop);
	pthread_mutex_lock(&philo->right_f->m_chop);
	philo->right_f->i_chop = 1;
	pthread_mutex_unlock(&philo->left_f->m_chop);
}

