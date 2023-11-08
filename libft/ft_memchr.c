/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:31:12 by vfedorov          #+#    #+#             */
/*   Updated: 2023/01/26 12:43:45 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*k;
	unsigned char	l;

	k = (unsigned char *)s;
	l = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		if (k[i] == l)
			return ((char *)(k + i));
		i++;
	}
	return (NULL);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char	*str = "bcwvcbi";
	int 	ds = 'v';
   	int		j = 5;
	printf("%s", ft_memchr(str, ds, j));   
}*/
