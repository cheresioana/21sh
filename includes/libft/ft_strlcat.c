/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 19:19:36 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 19:19:38 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t length;

	i = 0;
	while (dst[i] != '\0')
		i++;
	length = i;
	j = 0;
	while (i < size - 1 && src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	if (size < i)
		return (size + j);
	return (length + j);
}
