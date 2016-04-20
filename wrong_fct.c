/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:25:05 by icheres           #+#    #+#             */
/*   Updated: 2016/04/19 16:25:57 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	aff_nlist(t_nlist *a)
{
	while (a != NULL)
	{
		printf("%s\n", a->command);
		a = a->next;
	}
}

void	aff(t_slist *a)
{
	printf("ajunge in afisare\n");
	while (a != NULL)
	{
		while (a->data_list != NULL)
		{
			printf("%s\n", a->data_list->command);
			a->data_list = a->data_list->next;
		}
		printf("\n");
		a = a->next;
	}

}

void afis_paths(char **s)
{
	int i = 0;
	printf("halloooo");
	while (s[i])
	{
		printf("**%s**\n", s[i]);
		i++;
	}
}

void aff_meganlist(t_nlist *list)
{
	while (list)
	{
		printf("%s\n", list->command);
		printf("fd_in\n");
		while (list->fd_in)
		{
			printf("%s**%s**\n",list->fd_in->fd, list->fd_in->mode);
		   list->fd_in = list->fd_in->next;	
		}
		printf("fd_out\n");
		while (list->fd_out)
		{
			printf("%s**%s**\n",list->fd_out->fd, list->fd_out->mode);
		   list->fd_out = list->fd_out->next;	
		}
		list = list->next;
	}
}
