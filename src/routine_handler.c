/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:07:32 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/24 17:44:22 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	//time_t		time;

	philo = (t_philo *)arg;
	if (philo->name % 2 == 0 || philo->name == philo->data->nbr_philo)
	{
		if (is_thinking(philo))
			return (NULL);
		/*time = get_time();
		printing(get_time() - philo->data->start, philo, THINK);
		while (get_time() - time < philo->data->t_eat)
		{
			if (get_time() - philo->last_eat > philo->data->t_die)
			{
				printing(get_time() - philo->data->start, philo, DIE);
				philo->data->death++;
				return (NULL);
			}
			usleep(100);
		}*/
	}
	while (1)
	{
		if (take_left_chop(philo))
			break ;
		if (take_right_chop(philo))
			break ;
		if (is_eating(philo))
			break ;
		put_chop(philo);
		if (is_sleeping(philo))
			break ;
		//if (is_thinking(philo))
		//	break ;
	}
	return (NULL);
}

int	take_left_chop(t_philo *philo)
{
	int	rotation;

	rotation = 0;
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
			if (rotation == 0 && philo->nbr_eat != 0)
			{
				printf("%d ici\n", philo->name);
				printing(get_time() - philo->data->start, philo, THINK);
				rotation++;
			}
			usleep(100);
			if (get_time() - philo->last_eat > philo->data->t_die)
			{
				printing(get_time() - philo->data->start, philo, DIE);
				philo->data->death++;
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
			break ;
		}
		else
		{
			pthread_mutex_unlock(&philo->right_f->m_chop);
			usleep(100);
			if (get_time() - philo->last_eat > philo->data->t_die)
			{
				printing(get_time() - philo->data->start, philo, DIE);
				philo->data->death++;
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
