/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:46:53 by tchantro          #+#    #+#             */
/*   Updated: 2023/03/01 11:53:28 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	destroy(t_philo *philo, t_data *data, t_chop *chop)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&chop[i].m_chop);
		i++;
	}
	clear(philo, data, chop, 0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	k;
	int	a;

	i = 0;
	j = 0;
	k = 1;
	a = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '+' || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			k = k * -1;
		i++;
		j++;
	}
	if (j >= 2)
		return (0);
	while (nptr[i] >= 48 && nptr[i] <= 57)
		a = a * 10 + nptr[i++] - 48;
	return (a * k);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}
