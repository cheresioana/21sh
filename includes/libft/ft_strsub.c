/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 20:07:19 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 20:07:45 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*aux;
	char			*first;
	size_t			i;

	if (start < (unsigned int)len)
		return (NULL);
	i = 0;
	aux = (char *)malloc(1000);
	if (aux == NULL)
		return (NULL);
	first = aux;
	while (*s && i++ < len)
		*aux++ = *(s + start++);
	return (first);
}
