/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:54:19 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/27 18:24:46 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printing(time_t time, t_philo *philo, int write)
{
	pthread_mutex_lock(&philo->data->m_death);
	if (philo->data->death == 0)
	{
		if (write == 1)
			printf("%ld %d has taken a fork\n", time, philo->name);
		else if (write == 2)
			printf("%ld %d is eating\n", time, philo->name);
		else if (write == 3)
			printf("%ld %d is sleeping\n", time, philo->name);
		else if (write == 4)
			printf("%ld %d is thinking\n", time, philo->name);
		else if (write == 5)
		{
			printf("%ld %d died\n", time, philo->name);
			philo->data->death++;
		}
	}
	pthread_mutex_unlock(&philo->data->m_death);
}
