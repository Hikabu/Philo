/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:16:38 by vfedorov          #+#    #+#             */
/*   Updated: 2023/02/10 20:02:12 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	j = 0;
	if (dest == NULL && size == 0)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	if (size == 0)
		return (src_len);
	if (size < dest_len)
		return (src_len + size);
	else
	{
		while (src[j] && j + dest_len < size)
			dest[i++] = src[j++];
		if (dest_len + j == size && dest_len < size)
			dest[--i] = '\0';
		else
			dest[i] = '\0';
	}
	return (dest_len + src_len);
}
