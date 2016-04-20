/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 18:42:15 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 18:43:28 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_aux;
	unsigned const char *src_aux;

	dst_aux = dst;
	src_aux = src;
	while (n--)
	{
		*dst_aux++ = *src_aux++;
	}
	return (dst);
}
