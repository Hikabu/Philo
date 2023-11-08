/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:36:43 by vfedorov          #+#    #+#             */
/*   Updated: 2023/01/29 13:47:47 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*sra;

	if (count && size)
	{
		if (((count * size) < count) || ((count * size) < size))
			return (NULL);
	}
	sra = malloc (count * size);
	if (sra == NULL)
		return (NULL);
	ft_memset(sra, 0, (size * count));
	return (sra);
}
