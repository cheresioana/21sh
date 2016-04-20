/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 19:25:24 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 19:25:35 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(s1 + i) != '\0' && i < n)
	{
		if (*(s1 + i) == *(s2 + j))
			while (*(s1 + i) == *(s2 + j) && i < n)
			{
				i++;
				j++;
			}
		if ((*(s2 + j) == '\0'))
			return (char *)(s1 + i - j);
		else
			j = 0;
		i++;
	}
	return (0);
}
