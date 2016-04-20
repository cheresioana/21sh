/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 19:38:25 by icheres           #+#    #+#             */
/*   Updated: 2015/10/25 17:04:16 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*aux;

	aux = 0;
	if (size == 0)
		return (aux);
	aux = (void *)malloc(size);
	if (aux != 0)
		ft_bzero(aux, size);
	return (aux);
}
