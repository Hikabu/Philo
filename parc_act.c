/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/11/08 20:54:55 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	
	pthread_mutex_lock(philo->l_fork);
	message(TAKE_FORK, philo);
	if (philo->data->nbr_philo == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	message(TAKE_FORK, philo) ;
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	message(SLEEP, philo);
	mysleep(philo->data->sleep_tm);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	if (philo->data->nbr_philo == 1)
		return ;
	pthread_mutex_lock(&(philo->eat_m));
	philo->eating = 1;
	pthread_mutex_unlock(&(philo->eat_m));
	pthread_mutex_lock(&(philo->data->is_dead));
	philo->data->die_tm = get_time() + philo->data->die_tm;
	pthread_mutex_unlock(&(philo->data->is_dead));
	message(EAT, philo);
	pthread_mutex_lock(&(philo->m_cnt));
	philo->eat_cnt++;
	pthread_mutex_unlock(&(philo->m_cnt));
	mysleep(philo->data->eat_tm);
	pthread_mutex_lock(&(philo->eat_m));
	philo->eating = 0;
	pthread_mutex_unlock(&(philo->eat_m));
	drop_forks(philo);
}

int pars(t_data *data, char **av)
{
	int	i;
	(void)data;
	i = 1;
	while (av[i])
	{
		if (ft_atol(av[1]) > 200)
			return (0);
		if (!ft_strisnum(av[i]))
			return (0);
		i++;
	}
	return (1);
}
