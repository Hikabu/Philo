/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:11:53 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/11/11 22:35:21 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!is_dead(philo))
	{
		pthread_mutex_lock(philo->l_fork);
		message(LFORK, philo, get_time());
		pthread_mutex_lock(philo->r_fork);
		message(RFORK, philo, get_time());
		message(EAT, philo, get_time());
		pthread_mutex_lock(&philo->last_eat);
		philo->long_last_eat = get_time();
		pthread_mutex_unlock(&philo->last_eat);
		mysleep(philo->eat_tm);
		pthread_mutex_lock(&philo->eated);
		philo->cnt_meal++;
		pthread_mutex_unlock(&philo->eated);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		message(SLEEP, philo, get_time());
		mysleep(philo->sleep_tm);
		message(THINK, philo, get_time());
	}
	return (NULL);
}

int pars(t_data *data, char **av)
{
	int	i;
	(void)data;
	printf("lslsl\n");
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
