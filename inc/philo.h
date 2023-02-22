/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:12:42 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/22 17:30:04 by tchantro         ###   ########.fr       */
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

typedef struct s_chop
{
	pthread_mutex_t	m_chop;
	int				i_chop;
	int				index;
}	t_chop;

typedef struct s_data
{
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	time_t			start;
	pthread_mutex_t	mutex;
}	t_data;

typedef struct s_philo
{
	int			name;
	int			nbr_eat;
	t_chop		*left_f;
	t_chop		*right_f;
	pthread_t	thread;
	t_data		*data;
}	t_philo;

int			main(int argc, char **argv);
int			parsing_handler(int argc, char **argv);
int			verif_arg(int arg, int index_arg, t_data *data);
void		init_data(int arg, int index_arg, t_data *data);
t_philo		*init_philo(t_data *data, t_chop *chop);
t_chop		*init_chop(t_data *data);
void		init_threads(t_philo *philo, t_data *data);
void		*routine(void *arg);
void		take_left_chop(t_philo *philo);
void		take_right_chop(t_philo *philo);
void		put_chop(t_philo *philo);
void		printing(time_t time, int philo, int write);
time_t		get_time(void);

#endif
