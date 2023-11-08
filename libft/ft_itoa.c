/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:25:49 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/10 20:00:57 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}

char	*ft_nul(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		num;
	int		count;
	char	*str;

	num = n;
	count = 0;
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	count = count + (n <= 0);
	(str = (char *)malloc(sizeof(char) * count + 1));
	if (!str)
		return (str);
	ft_nul(n, str);
	str[count] = '\0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[--count] = (n % 10) * (2 * (n > 0) - 1) + '0';
		n = n / 10;
	}
	return (str);
}
