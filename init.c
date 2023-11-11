/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:25:11 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/11/11 21:16:38 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		data->philo[i].mutex_print = &(data->mutex_print);
		data->philo[i].mutex_dead = &(data->mutex_dead);
		pthread_mutex_init(&(data->fork[i]), NULL);
		pthread_mutex_init(&(data->philo[i].last_eat), NULL);
		pthread_mutex_init(&(data->philo[i].eated), NULL);
	}
	i = -1;
	while (++i < data->nbr_philo)
	{
		if (i == data->nbr_philo - 1)
		{
			data->philo[i].l_fork = &(data->fork[i]);
			data->philo[i].r_fork = &(data->fork[0]);
		}
		else
		{
			data->philo[i].l_fork = &(data->fork[i]);
			data->philo[i].r_fork = &(data->fork[i + 1]);
		}
	}
}

int	init_philo(t_data *data, char **av)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].die = &(data->dead);
		data->philo[i].cnt_meal = 0;
		data->philo[i].eat_tm = ft_atol(av[3]);
		data->philo[i].sleep_tm = ft_atol(av[4]);
		data->philo[i].long_last_eat = 0;
		i++;
	}
	return (0); 
}

int	init_1(t_data *data, char **av)
{
	data->dead = 0;
	data->nbr_philo = ft_atol(av[1]);
	if (data->nbr_philo == 0)
		return (1);
	pthread_mutex_init(&(data->mutex_print), NULL);
	pthread_mutex_init(&(data->mutex_dead), NULL);
	data->die_tm = ft_atol(av[2]);
	data->fork = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philo);
	if (av[5])
		data->nbr_meal = ft_atol(av[5]);
	else
		data->nbr_meal = -1;
	return (0);
}

int	is_dead(t_philo *philo)
{
	int	i;
	pthread_mutex_lock(philo->mutex_dead);
	i = *(philo->die);
	pthread_mutex_unlock(philo->mutex_dead);
	return (i);
}


