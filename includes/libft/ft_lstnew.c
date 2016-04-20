/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 20:27:23 by icheres           #+#    #+#             */
/*   Updated: 2016/04/03 14:58:57 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*aux;

	aux = 0;
	aux = (t_list *)ft_memalloc(sizeof(t_list) * content_size);
	if (content == 0)
	{
		aux->content = 0;
		aux->content_size = 0;
		return (aux);
	}
	if (aux == 0)
		return (0);
	aux->content = malloc(sizeof(aux->content) * content_size);
	ft_strcpy(aux->content, content);
	aux->content_size = content_size;
	aux->next = 0;
	return (aux);
}
