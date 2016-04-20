/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 12:05:33 by icheres           #+#    #+#             */
/*   Updated: 2016/04/20 12:07:00 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		list_count(t_nlist *list)
{
	int		i;
	t_nlist	*begin;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	list = begin;
	return (i);
}
