/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:37:58 by vfedorov          #+#    #+#             */
/*   Updated: 2023/10/08 21:37:59 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
