/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:24:05 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/27 16:54:30 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_arg(int arg, int index_arg, t_data *data, int argc)
{
	if (index_arg == 1)
	{
		if (arg < 1)
			return (printf("Need at least one philosopher\n"), 1);
	}
	else if (index_arg == 2 || index_arg == 3 || index_arg == 4)
	{
		if (arg < 0)
		{
			if (index_arg == 2)
				return (printf("Time to die can't be negative\n"), 2);
			else if (index_arg == 3)
				return (printf("Time to eat can't be negative\n"), 2);
			else if (index_arg == 4)
				return (printf("Time to sleep can't be negative\n"), 2);
		}
	}
	else if (index_arg == 5)
	{
		if (arg < 1)
			return (printf("Philosopher must eat at least 1 time\n"), 5);
	}
	init_data(arg, index_arg, data, argc);
	return (0);
}

int	parsing_arg(char **argv, int i, int j)
{
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
			return (printf("Argument is empty\n"), 1);
		else if (argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return (printf("Only '-' didn't work\n"), 2);
		while (ft_isdigit(argv[i][j]) == 1)
			j++;
		if (!argv[i][j])
		{
			j = 0;
			i++;
		}
		else
			return (printf("Numeric argument is required\n"), 3);
	}
	return (0);
}

int	parsing_handler(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (parsing_arg(argv, 1, 0) == 0)
			return (0);
		else
			return (1);
	}
	else if (argc < 5)
	{
		printf("Argument is missing\n");
		return (2);
	}
	else
	{
		printf("Too many arguments\n");
		return (3);
	}
}
