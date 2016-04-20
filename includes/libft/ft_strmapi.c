/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 19:44:12 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 19:44:25 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*first;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s));
	first = new;
	while (*s)
	{
		*new = f(i, *s);
		new++, s++, i++;
	}
	*new = 0;
	return (first);
}
