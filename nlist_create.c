/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlist_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 11:52:27 by icheres           #+#    #+#             */
/*   Updated: 2016/04/18 17:34:20 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*init_data_n(char *data, t_nlist *nlist, t_sp *ij)
{
	char	*command;

	ij->i = 0;
	ij->j = 0;
	command = (char *)malloc(sizeof(char) * (ft_strlen(data) + 1));
	nlist = (t_nlist *)malloc(sizeof(t_nlist));
	nlist = NULL;
	return (command);
}

char		*get_shit(char *data, t_sp *ij)
{
	char		*shit;
	int			i;

	i = 0;
	shit = (char *)malloc(sizeof(char) * (ft_strlen(data + ij->i) + 1));
	while (data[ij->i] == '|' || data[ij->i] == '<' || data[ij->i] == '>' ||
			data[ij->i] == '<' || (data[ij->i] >= '0' && data[ij->i] <='3')
			|| data[ij->i] == '&')
	{
		shit[i] = data[ij->i];
		ij->i++;
		i++;
	}
	shit[i] = '\0';
	if (ft_strcmp(shit, "3>&1") != 0 && ft_strcmp(shit, "2>&1") != 0 &&
			ft_strcmp(shit, "1>&2") != 0 && ft_strcmp(shit, "3>&2") != 0 &&
			ft_strcmp(shit, ">") != 0 && ft_strcmp(shit, ">>") != 0 &&
			ft_strcmp(shit, "<") != 0 && ft_strcmp(shit, "<<") != 0 &&
			ft_strcmp(shit, "1>>") != 0 && ft_strcmp(shit, "2>") != 0 &&
			ft_strcmp(shit, "2>>") != 0 && ft_strcmp(shit, "1>") != 0 &&
			ft_strcmp(shit, "&>") != 0 && ft_strcmp(shit, "&>>") != 0 &&
			ft_strcmp(shit, "|") != 0)
	{
		printf("***%s**\n", shit);
		err("-bash: 12: Bad file descriptor");
	}
	return (shit);	
}

t_nlist		*create_nelem(char *data, t_nlist *l)
{
	t_nlist		*list;
	//printf("intra in create nelem %s\n", data);
	list = (t_nlist *)malloc(sizeof(t_nlist));
	list->prev = l;
	list->next = NULL;
	list->fd_in = NULL;
	list->fd_out = NULL;
	list->command = ft_strdup(clean_spaces(data));
//	printf("%s\n", clean_spaces(data));
	return (list);

}

t_nlist		*get_nlist(char *data)
{
	t_nlist		*list;
	t_nlist		*begin_list;
	t_sp		ij;
	char		*command;

	//printf("intra in get_nelem\n");
	command = init_data_n(data, list, &ij);
	list = NULL;
	begin_list = list;
	while (data[ij.i])
	{
		if (data[ij.i] == '|' || data[ij.i] == '<' || data[ij.i] == '>' ||
				data[ij.i] == '<' || (data[ij.i] >= '0' && data[ij.i] <='3'))
		{
			command[ij.j] = '\0';
			ij.j = 0;
			if (list == NULL)
			{
				list = create_nelem(command, NULL);
				list->next = NULL;
				begin_list = list;
			}
			else
			{
				list->next = create_nelem(command, list);
				list = list->next;
			}
			list->next = create_nelem(get_shit(data, &ij), list);
			list = list->next;
			//aff_nlist(begin_list);
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
	command[ij.j] = '\0';
	if (list == NULL)
	{
		list = create_nelem(command, NULL);
		begin_list = list;
	}
	else
	{
		//printf("intri in pula?\n");
		list->next = create_nelem(command, list);
		list = list->next;
	}

	//printf("vrea sa iasa\n");
	//aff_nlist(begin_list);
	return (begin_list);
}

t_slist		*create_selem(char *data)
{
	t_slist	*list;

	//printf("intra in create selem %s\n", data);
	list = (t_slist *)malloc(sizeof(t_slist));
	list->data_list = get_nlist(data);
	list->next = NULL;
	return (list);
}
