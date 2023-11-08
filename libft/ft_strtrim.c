/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:41:06 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/14 19:41:08 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_kakoyset(char f, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == f)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*c;
	size_t	i;
	size_t	beg;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	beg = 0;
	while (s1[beg] && ft_kakoyset(s1[beg], set))
		beg++;
	end = ft_strlen(s1);
	while (end > beg && ft_kakoyset(s1[end - 1], set))
		end--;
	c = ((char *)malloc(sizeof(*s1) * (end - beg + 1)));
	if (!c)
		return (0);
	i = 0;
	while (beg < end)
		c[i++] = s1[beg++];
	c[i] = 0;
	return (c);
}
