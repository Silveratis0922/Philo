/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:46 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/08 15:57:02 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(int arg, int index_arg, t_init *init)
{
	if (index_arg == 1)
		init->nbr_philo = arg;
	else if (index_arg == 2)
		init->t_die = arg;
	else if (index_arg == 3)
		init->t_eat = arg;
	else if (index_arg == 4)
		init->t_sleep = arg;
	else if (index_arg == 5)
		init->must_eat = arg;
}
