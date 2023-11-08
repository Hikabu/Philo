/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:56:39 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/08 19:20:10 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*der;
	int		i;
	int		g;

	i = 0;
	while (s1[i])
		i++;
	der = malloc(sizeof(char) * (i + 1));
	if (!(der))
		return (0);
	g = 0;
	while (s1[g])
	{
		der[g] = s1[g];
			g++;
	}
	der[g] = '\0';
	return (der);
}
/*
#include<string.h>
#include<stdio.h>
int main()
{
	const char s[] = "werrtyu";
	printf("%s\n", ft_strdup(s));
	printf("%s", strdup(s));
}
*/
