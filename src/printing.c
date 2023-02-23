/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:54:19 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/23 15:00:23 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printing(time_t time, t_philo *philo, int write)
{
	pthread_mutex_init(&philo->data->print, NULL);
	pthread_mutex_lock(&philo->data->print);
	if (write == 1)
		printf("%ld %d has taken a fork\n", time, philo->name);
	else if (write == 2)
		printf("%ld %d is eating\n", time, philo->name);
	else if (write == 3)
		printf("%ld %d is sleeping\n", time, philo->name);
	else if (write == 4)
		printf("%ld %d is thinking\n", time, philo->name);
	else if (write == 5)
		printf("%ld %d died\n", time, philo->name);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_destroy(&philo->data->print);
}
