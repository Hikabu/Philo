/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:33:01 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/14 20:07:22 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		dl1;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	dl1 = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (dl1 + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[dl1++] = s2[i];
		i++;
	}
	str[dl1] = '\0';
	return (str);
}
