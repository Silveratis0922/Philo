/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:12:42 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/08 15:52:43 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include "libft.h"

typedef struct s_init
{
	int	nbr_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat;
}	t_init;

int		main(int argc, char **argv);
int		parsing_handler(int argc, char **argv);
int		verif_arg(int arg, int index_arg, t_init *init);
void	init_struct(int arg, int index_arg, t_init *init);

#endif
