/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/11/11 22:35:05 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>
#include <pthread.h>

# define E_ARG "Wrong arguments"
# define ERORR "ERORR"
# define MALLOC "Error with malloc"
# define E_PAR "Not good parcing"
# define TH_CREATE "Error with thread creating"
# define TH_JOIN "Error with thread joining"
# define LFORK "has taken left fork"
# define RFORK "has taken right fork"
# define DEAD "died"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define TAKE_FORK "has taken a fork"

// struct timeval
//{
//		time_t		tv_sec;         /* seconds */
//     suseconds_t tv_usec;        /* microseconds */
//}

typedef void*	(*t_thread_handler)(void*);


typedef struct s_philo
{
	long long		long_last_eat;
	int				*die;
	int				id;
	long			eat_tm;
	long			sleep_tm;
	long			cnt_meal;
	pthread_t		philosof; //dont need to use(only for pthread)
	pthread_mutex_t last_eat;
	pthread_mutex_t eated;
	pthread_mutex_t *mutex_dead;
	pthread_mutex_t *mutex_print;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_philo;

typedef struct s_data
{
	t_philo			*philo;
	long long		die_tm;
	int				nbr_philo;
	int				nbr_meal;
	int				dead;
	pthread_mutex_t *fork;
	pthread_mutex_t mutex_print;
	pthread_mutex_t mutex_dead;
} t_data;

int			is_dead(t_philo *philo);
void		init_mutex(t_data *data);
int			pars(t_data *data, char **av);
long long	get_time(void);
int			init_philo(t_data *data, char **av);
int			init_1(t_data *data, char **av);
void		mysleep(useconds_t time);
void		ft_destroy(t_data *data);
void		message(char *str, t_philo *philo, long long time);
void		*routine(t_philo *info);
void		ft_destroy(t_data *data);
long 		ft_atol(const char *str);
int			ft_strcmp(char *str1, char *str2);
int			ft_strisnum(char *str);
#endif
