/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:36:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/11/12 00:53:10 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	message(char *str, t_philo *philo, long long time)
{
	pthread_mutex_lock(philo->mutex_print);
	if (!(is_dead(philo)))
		printf("%llu philo[%d] %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->mutex_print);
}

int	mb_philo_dead(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		pthread_mutex_lock(&(data->philo[i].last_eat));
		if (get_time() - data->philo[i].long_last_eat > data->die_tm)
		{
			pthread_mutex_lock(&data->mutex_dead);
			data->dead = 1;
			pthread_mutex_unlock(&data->mutex_dead);
			pthread_mutex_lock(&data->mutex_print);
			printf("%llu philo[%d] died\n", get_time()
				- data->philo[i].long_last_eat, data->philo[i].id);
			pthread_mutex_unlock(&data->mutex_print);
			pthread_mutex_unlock(&(data->philo[i].last_eat));
			return (1);
		}
		pthread_mutex_unlock(&(data->philo[i].last_eat));
	}
	return (0);
}

int	god_safe_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo && data->nbr_meal != -1)
	{
		pthread_mutex_lock(&(data->philo[i].eated));
		if (data->philo[i].cnt_meal >= data->nbr_meal)
		{
			pthread_mutex_unlock(&(data->philo[i].eated));
			i++;
		}
		else
		{
			pthread_mutex_unlock(&(data->philo[i].eated));
			break ;
		}
	}
	if (i == data->nbr_philo)
	{
		pthread_mutex_lock(&(data->mutex_dead));
		data->dead = 1;
		pthread_mutex_unlock(&(data->mutex_dead));
		return (1);
	}
	return (0);
}

void	ft_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philo[i].last_eat);
		pthread_mutex_destroy(&data->philo[i].eated);
	}
	pthread_mutex_destroy(&data->mutex_dead);
	pthread_mutex_destroy(&data->mutex_print);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = -1;
	get_time();
	if (ac == 5 || ac == 6)
	{
		if (!pars(&data, av))
			return (printf("wrong arguments\n"));
		pars(&data, av);
		init_1(&data, av);
		init_philo(&data, av);
		init_mutex(&data);
		while (++i < data.nbr_philo)
		{
			pthread_create(&(data.philo[i].philosof), NULL,
				(t_thread_handler)(&routine), &(data.philo[i]));
		}
		while (1)
		{
			if ((mb_philo_dead(&data) == 1) || god_safe_philo(&data))
				break ;
		}
		i = -1;
		if (data.nbr_philo != 1)
		{
			while (++i < data.nbr_philo)
				pthread_join(data.philo[i].philosof, NULL);	
		}
		ft_destroy(&data);
	}
	else
		return (printf("wrong arguments\n"));
	return (0);
}
