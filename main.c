/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:36:24 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/11/08 20:29:05 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->thread_id[0], NULL, &routine, &data->philo[0]))
		return (error("ERROR", data));
	pthread_join(data->thread_id[0], NULL);
	while(data->dead == 0)
		mysleep(5);
	ft_destroy(data);
	return (0);
} 

void	ft_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philo[i].f_own_lock);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock);
	free(data->thread_id);
}
int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_destroy(data);
	return (1);
}
void	message(char *str, t_philo *philo)
{
	long long	time;

	
	time = get_time() - philo->data->start_time;
	if (ft_strcmp(DEAD, str) == 0 && philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%llu philo[%d] %s\n", time, philo->id, str);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_lock(&philo->data->is_dead);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->is_dead);
		mysleep(5);
	}
	if (!philo->data->dead)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%llu philo[%d] %s\n", time, philo->id, str);
		pthread_mutex_unlock(&philo->data->print);
	}
}
int main(int ac, char **av)
{
	t_data	data;
	
	if (ac == 5 || ac == 6)
	{
		if (!pars(&data, av))
			return (error("wrong arguments", NULL));
		get_time();
		if (init_1(&data, av))
			return (1);
		if (ft_atoi(av[1]) == 1)
		{
			one_philo(&data);
			return (0);
		}
		if (action(&data))
			return (1);
		ft_destroy(&data);
	}
	return (0);
}
