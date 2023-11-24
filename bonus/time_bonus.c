/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:28:07 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/11/12 00:52:50 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time (void)
{
	struct	timeval			start;
	static 	long long		fix_first_sec;
	static	int				count;

	if (gettimeofday(&start, NULL))
		return (printf("FAIL\n"));
	if (count == 0)
	{
		fix_first_sec = (start.tv_sec * 1000 + start.tv_usec / 1000);
		count = 1;
	}
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000) - fix_first_sec);
}

void	mysleep(useconds_t time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(time / 10);
}


