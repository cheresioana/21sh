/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 14:53:08 by icheres           #+#    #+#             */
/*   Updated: 2016/04/17 16:53:15 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*init_data(char *data, t_slist *slist, t_sp *ij)
{
	char *command;

	ij->i = 0;
	ij->j = 0;
	command = (char *)malloc(sizeof(char) * (ft_strlen(data) + 1));
	//command = NULL;
	slist = (t_slist *)malloc(sizeof(t_slist));
	slist = NULL;
	return (command);
}

t_slist		*get_list(char *data)
{
	t_slist		*slist;
	t_slist 	*begin_slist;
	char		*command;
	t_sp		ij;

//	printf("intra in get slist\n");
	command = init_data(data, slist, &ij);
	slist = NULL;
//	printf("iese din init slist\n");
	while (data[ij.i])
	{
		if (data[ij.i] == ';')
		{
			command[ij.j] = '\0';
			ij.j = 0;
			if (slist == NULL)
			{
				slist = create_selem(command);
				begin_slist = slist;
			}
			else
			{
				slist->next = create_selem(command);
				slist = slist->next;
			}
			free(command);
			command = (char *)malloc(sizeof(char) * (ft_strlen(data + ij.i) + 1));
		}
		else
		{
			command[ij.j] = data[ij.i];
			ij.j++;
		}
		ij.i++;
	}
	if (slist == NULL)
	{
		slist = create_selem(command);
		begin_slist = slist;
	}
	else
	{
		slist->next = create_selem(command);
		slist = slist->next;
	}

//	printf("iese din get list\n");
	return (begin_slist);
}
