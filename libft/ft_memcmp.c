/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:55:02 by vfedorov          #+#    #+#             */
/*   Updated: 2023/01/26 15:28:51 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			in;
	unsigned char	*pe;
	unsigned char	*vt;

	pe = (unsigned char *)s1;
	vt = (unsigned char *)s2;
	in = 0;
	while (in < n)
	{
		if (pe[in] != vt[in])
			return (pe[in] - vt[in]);
		in++;
	}
	return (0);
}
