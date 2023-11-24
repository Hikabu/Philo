/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:06:46 by vfedorov          #+#    #+#             */
/*   Updated: 2023/11/12 00:52:55 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	erro(void)
{
	write(2, "error with argument\n", 20);
}

long	ft_atol(const char *str)
{
	int		count;
	long	i;
	long	otr;

	count = 0;
	i = 0;
	otr = 1;
	if (!str)
		return (0);
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
	if (str[count] != '\0')
		erro();
	return (otr * i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1 && str2 && str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!str[i] || !(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}
