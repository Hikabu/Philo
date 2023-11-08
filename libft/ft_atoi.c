/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:13:05 by vfedorov          #+#    #+#             */
/*   Updated: 2023/01/27 05:31:01 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	i;
	int	otr;

	count = 0;
	i = 0;
	otr = 1;
	while (str[count] == '\n' || str[count] == '\t' || str[count] == '\f'
		|| str[count] == '\r' || str[count] == '\v' || str[count] == ' ')
		count++;
	if (str[count] == '-')
		otr = -1;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] >= 48 && str[count] <= 57)
	{
		i = i * 10 + str[count] - 48;
		count++;
	}
	return (otr * i);
}
