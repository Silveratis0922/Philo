/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:12:42 by tchantro          #+#    #+#             */
/*   Updated: 2023/02/27 17:43:26 by tchantro         ###   ########.fr       */
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
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_chop
{
	pthread_mutex_t	m_chop;
	int				i_chop;
}	t_chop;

typedef struct s_data
{
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				full;
	int				death;
	time_t			start;
	pthread_mutex_t	mutex;
	//pthread_mutex_t	print;
	pthread_mutex_t	m_death;
	pthread_mutex_t	m_full;
}	t_data;

typedef struct s_philo
{
	int			name;
	int			nbr_eat;
	time_t		last_eat;
	t_chop		*left_f;
	t_chop		*right_f;
	pthread_t	thread;
	t_data		*data;
}	t_philo;

int			main(int argc, char **argv);
int			parsing_handler(int argc, char **argv);
int			verif_arg(int arg, int index_arg, t_data *data, int argc);
void		init_data(int arg, int index_arg, t_data *data, int argc);
t_philo		*init_philo(t_data *data, t_chop *chop);
t_chop		*init_chop(t_data *data);
void		init_threads(t_philo *philo, t_data *data);
void		*routine(void *arg);
int			take_left_chop(t_philo *philo);
int			take_right_chop(t_philo *philo);
void		put_chop(t_philo *philo);
int			is_sleeping(t_philo *philo);
int			is_eating(t_philo *philo);
void		is_dead(t_philo *philo);
void		printing(time_t time, t_philo *philo, int write);
void		destroy(t_data *data, t_chop *chop);
time_t		get_time(void);

#endif
