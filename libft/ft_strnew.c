/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 19:40:05 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 19:40:19 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*aux;

	aux = 0;
	aux = (char *)malloc(sizeof(char) * size);
	if (aux != NULL)
		ft_bzero(aux, size);
	return (aux);
}
