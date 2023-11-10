/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/11/10 17:10:35 by vfedorov         ###   ########.fr       */
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
#include "./libft/libft.h"

# define E_ARG "Wrong arguments"
# define ERORR "ERORR"
# define MALLOC "Error with malloc"
# define E_PAR "Not good parcing"
# define TH_CREATE "Error with thread creating"
# define TH_JOIN "Error with thread joining"
# define FORK "has taken a fork"
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

typedef struct s_philo
{
	struct s_data	*data;
	long			eat_tm;
	long			sleep_tm;
	long			die_tm;
	long			eat_cnt;
	int				eating;
	int				id;
	pthread_t		philosof; //dont need to use(only for pthread)
	pthread_mutex_t	f_own_lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t m_cnt;
	pthread_mutex_t eat_m;
} t_philo;

typedef struct s_data
{
	t_philo			philo[200];
	int				nbr_philo;
	int				full;
	int				dead;
	int				nbr_meal;
	long			eat_tm;
	long			sleep_tm;
	long			die_tm;
	long long		start_time;
	pthread_t		*thread_id;
	pthread_mutex_t fork[200];
	pthread_mutex_t print;
	pthread_mutex_t is_dead;
	pthread_mutex_t mutex_dead;
	pthread_mutex_t lock;
} t_data;

// void		for_time(); // for delete
// void		whatuint(); // delete
// void		problem(); // delete
int			pars(t_data *data, char **av);
long long	get_time(void);
int			init_philo(t_data *data);
int			init_1(t_data *data, char **av);
void		mysleep(useconds_t time);
// int			parc (t_data *data, char **av);
void		erro();
int			error(char *str, t_data *data);
void		create_forks(t_data *data);
void		drop_forks(t_philo *philo);
void		message(char *str, t_philo *philo);
int			action(t_data *data);
void		*one_more(void *info);
void		*routine(void *sofer);
void		*stalker(void *infa);
void		eat(t_philo *philo);
void		ft_destroy(t_data *data);
#endif
