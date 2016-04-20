/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 20:39:45 by icheres           #+#    #+#             */
/*   Updated: 2015/08/07 20:39:46 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *aux;

	while ((*alst) != 0)
	{
		del((*alst)->content, (*alst)->content_size);
		aux = *alst;
		(*alst) = (*alst)->next;
		free(aux);
	}
}
