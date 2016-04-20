/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 18:44:49 by icheres           #+#    #+#             */
/*   Updated: 2016/04/10 17:04:46 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *)dst;
	aux2 = (unsigned char *)src;
	while (n--)
	{
		*aux1 = *aux2;
		if (*aux2 == (unsigned char)c)
			return (aux1 + 1);
		aux1++;
		aux2++;
	}
	return (0);
}
