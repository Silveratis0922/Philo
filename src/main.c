/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:06:05 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/27 16:54:15 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear(t_philo *philo, t_data *data, t_chop *chop, int write)
{
	if (chop)
		free(chop);
	if (philo)
		free(philo);
	if (write == 2)
	{
		destroy(data, chop);
		printf("Malloc Error\n");
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_data		data;
	t_philo		*philo;
	t_chop		*chop;

	i = 1;
	if (!parsing_handler(argc, argv))
	{
		while (argv[i])
		{
			if (verif_arg(ft_atoi(argv[i]), i, &data, argc))
				return (1);
			i++;
		}
		chop = init_chop(&data);
		if (!chop)
			return (printf("Malloc Error\n"), 2);
		philo = init_philo(&data, chop);
		if (!philo)
			return (clear(philo, &data, chop, 2), 2);
		data.start = get_time();
		init_threads(philo, &data);
		destroy(&data, chop);
		clear(philo, &data, chop, 0);
	}
	return (0);
}
