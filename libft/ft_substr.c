/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:27 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/10 19:15:38 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*drug_s;
	size_t			r;

	if (!s)
		return (0);
	if (len > ft_strlen(s + start))
		r = ft_strlen(s + start);
	else
		r = len;
	drug_s = malloc (r + 1);
	if (!drug_s)
		return (0);
	i = 0;
	while (start < ft_strlen(s) && s[start + i] && i < r)
	{
		drug_s[i] = s[start + i];
		i++;
	}
	drug_s[i] = '\0';
	return (drug_s);
}
