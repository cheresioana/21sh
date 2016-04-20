/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 19:06:12 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 19:06:28 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*aux1;
	char	*aux2;

	i = 1;
	aux1 = (char *)s1;
	while (*aux1++)
		i++;
	aux2 = (char *)malloc(sizeof(char) * i);
	aux1 = aux2;
	while (*s1)
		*aux2++ = *s1++;
	return (aux1);
}
