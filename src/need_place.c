/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:09:53 by tchantro          #+#    #+#             */
/*   Updated: 2023/03/01 15:13:37 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	need_place(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_full);
	philo->data->full++;
	pthread_mutex_unlock(&philo->data->m_full);
}

void	need_place_bis(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->m_death);
	pthread_mutex_lock(&philo->data->m_full);
}

void	need_place_ter(t_philo *philo)
{
	printing(get_time() - philo->data->start, philo, THINK);
	pthread_mutex_lock(&philo->data->m_death);
}
