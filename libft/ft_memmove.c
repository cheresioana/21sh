/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 18:45:55 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 18:51:03 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*aux1;
	const char	*aux2;

	aux1 = (char *)dst;
	aux2 = (char *)src;
	if (aux1 < aux2)
	{
		while (len--)
			*aux1++ = *aux2++;
	}
	else
	{
		aux1 += len;
		aux2 += len;
		while (len--)
			*--aux1 = *--aux2;
	}
	return (dst);
}
