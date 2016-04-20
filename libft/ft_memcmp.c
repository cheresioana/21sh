/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 18:58:58 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 18:59:20 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (*((char*)s1 + i) != (*((char*)s2 + i)))
			return (*((char*)s1 + i) - (*((char*)s2 + i)));
		i++;
	}
	return (0);
}
