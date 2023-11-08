/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:59:18 by vfedorov          #+#    #+#             */
/*   Updated: 2023/01/21 17:57:32 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*s)
		s++;
	while (s >= p)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
