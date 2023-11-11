/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:28:07 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/11/11 21:50:13 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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


