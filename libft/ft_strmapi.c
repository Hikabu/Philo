/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:54:21 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/14 19:43:15 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;
	size_t			len;

	len = ft_strlen(s);
	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!result)
		return (0);
	while (i < len)
	{		
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
