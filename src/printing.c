/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:54:19 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/22 14:34:27 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printing(time_t time, int philo, int write)
{
	if (write == 1)
		printf("%ld ms %d has taken a fork\n", time, philo);
	else if (write == 2)
		printf("%ld ms %d is eating\n", time, philo);
	else if (write == 3)
		printf("%ld ms %d is sleeping\n", time, philo);
	else if (write == 4)
		printf("%ld ms %d is thinking\n", time, philo);
	else if (write == 5)
		printf("%ld ms %d died\n", time, philo);
}
