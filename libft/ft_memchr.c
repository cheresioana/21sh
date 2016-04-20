/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 18:52:20 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 18:52:47 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *aux;

	aux = (char *)s;
	while (n--)
	{
		if (c == *aux)
			return (aux);
		aux++;
	}
	return (0);
}
