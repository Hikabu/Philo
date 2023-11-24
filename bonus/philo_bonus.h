/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/11/20 15:52:38 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>
# include <pthread.h>
# include <semaphore.h>

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

typedef void*	(*t_thread_handler)(void*);

typedef struct s_philo
{
	long			nbr_philo;
	long 			die_tm;
	long			eat_tm;
	long			sleep_tm;
	long 			long_last_eat;
	long			cnt_meal;
	int				id;
	int				dead;
	int				stop;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*place;
	sem_t			*time;
}	t_philo;

int			is_dead(t_philo *philo);
void		init_mutex(t_philo *data);
int			pars(t_philo *data, char **av);
long long	get_time(void);
int			init_philo(t_philo *data, char **av);
int			init_1(t_philo *data, char **av);
void		mysleep(useconds_t time);
void		ft_destroy(t_philo *data);
void		message(char *str, t_philo *philo, long long time);
void		*routine(t_philo *info);
void		ft_destroy(t_philo *data);
long		ft_atol(const char *str);
int			ft_strcmp(char *str1, char *str2);
int			ft_strisnum(char *str);
#endif
