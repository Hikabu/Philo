/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:01:51 by vfedorov          #+#    #+#             */
/*   Updated: 2023/01/26 15:21:48 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*wer;
	char	rt;

	rt = (char)c;
	wer = (char *)s;
	while (*wer != '\0' && rt != *wer)
		wer++;
	if (rt == *wer)
		return ((char *)wer);
	return (0);
}
/*
#include<stdio.h>
#include<string.h>

int main()
{
	char	dt[] = "ehwof";
	int		c = 256;
	printf("%s\n", ft_strchr(dt,c));
	printf("%s", strchr(dt,c));
}
*/
