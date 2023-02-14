/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:54:19 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/14 13:59:39 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printing(int philo, int write)
{
	if (write == 1)
		printf("%d has taken a fork\n", philo);
	else if (write == 2)
		printf("%d is eating\n", philo);
	else if (write == 3)
		printf("%d is sleeping\n", philo);
	else if (write == 4)
		printf("%d is thinking\n", philo);
	else if (write == 5)
		printf("%d died\n", philo);
}
