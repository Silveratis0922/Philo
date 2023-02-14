/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:07:32 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/14 17:40:09 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

extern int test;

void	*start_routine(void *arg)
{
	int	i = 0;

	pthread_mutex_lock(arg);
	while (i < 1000000)
	{
		test++;
		i++;
	}
	pthread_mutex_unlock(arg);
	return (NULL);
}
