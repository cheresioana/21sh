/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 19:42:37 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 19:43:45 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*start;

	new = (char *)malloc(sizeof(char) * ft_strlen(s));
	start = new;
	while (*s)
	{
		*new = f(*s);
		new++, s++;
	}
	*new = 0;
	return (start);
}
