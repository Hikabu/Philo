/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:19:46 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/10 20:32:17 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	h;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] != '\0')
	{
		h = 0;
		while (haystack[i + h] == needle[h] && (i + h) < len)
		{
			if (haystack[i + h] == '\0' && needle[h] == '\0')
				return ((char *)&haystack[i]);
			h++;
		}
		if (needle[h] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
