/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:46 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/13 17:52:32 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int arg, int index_arg, t_data *data)
{
	if (index_arg == 1)
		data->nbr_philo = arg;
	else if (index_arg == 2)
		data->t_die = arg;
	else if (index_arg == 3)
		data->t_eat = arg;
	else if (index_arg == 4)
		data->t_sleep = arg;
	else if (index_arg == 5)
		data->must_eat = arg;
}
