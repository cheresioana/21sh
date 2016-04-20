/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 20:07:59 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 20:08:05 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	char	*first;

	aux = 0;
	aux = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (aux == 0)
		return (0);
	first = aux;
	while (*s1)
		*aux++ = *s1++;
	while (*s2)
		*aux++ = *s2++;
	return (first);
}
