/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 15:13:35 by icheres           #+#    #+#             */
/*   Updated: 2016/04/19 14:11:41 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		in_fd(char *s)
{
	if (ft_strcmp(s, "<") == 0 || ft_strcmp(s, "<<") == 0 ||
			ft_strcmp(s, "1<") == 0 || ft_strcmp(s, "1<<") == 0 ||
			ft_strcmp(s, "2<") == 0 || ft_strcmp(s, "2<<") == 0)
		return (1);
	return (0);
}

int		out_fd(char *s)
{
	if (ft_strcmp(s, ">") == 0 || ft_strcmp(s, ">>") == 0 ||
			ft_strcmp(s, "1>") == 0 || ft_strcmp(s, "1>>") == 0 ||
			ft_strcmp(s, "2>") == 0 || ft_strcmp(s, "2>>") == 0)
		return (1);
	return (0);

}

t_nnlist	*createlem_nnlist(char *mod, char *command, t_nnlist *t)
{
	t_nnlist	*l;

	l = (t_nnlist *)malloc(sizeof(t_nnlist));
	l->next = NULL;
	l->prev = t;
	l->fd = ft_strdup(command);
	l->mode = ft_strdup(mod);

	return (l);
}

void	add(int i, t_nlist *list)
{
	t_nnlist	*begin;
	char		*mod;
	char		*fd;

	mod = list->next->command;
	fd = list->next->next->command;
	if (i == 0)
	{
		if (list->fd_in == NULL)
			list->fd_in = createlem_nnlist(mod, fd, NULL);
		else
		{
			begin = list->fd_in;
			while (list->fd_in->next != NULL)
				list->fd_in = list->fd_in->next;
			list->fd_in->next = createlem_nnlist(mod, fd, list->fd_in);
			list->fd_in = begin;	
		}
	}
	else
	{
		if (list->fd_out == NULL)
			list->fd_out = createlem_nnlist(mod, fd, NULL);
		else
		{
			begin = list->fd_out;
			while (list->fd_out->next != NULL)
				list->fd_out = list->fd_out->next;
			list->fd_out->next = createlem_nnlist(mod, fd, list->fd_out);
			list->fd_out = begin;	
		}
	}
}

void	connect (t_nlist *t1, t_nlist *t2)
{
	if (t2)
	{
		t1->next = t2;
		t2->prev = t1;
	}
	else t1->next = NULL;
}

void	processing_list(t_nlist *list)
{
	t_nlist		*cp;

	cp = list;
	list = list->next;
	while (list)
	{
		if (in_fd(list->command) == 1)
		{
			list = list->prev;
			add(0, list);
			connect(list, list->next->next->next);
		}
		else if (out_fd(list->command) == 1)
		{
			list = list->prev;
			add(1, list);
			connect(list, list->next->next->next);
		}
			list = list->next;
			//aff_meganlist(cp);
	}
	list = cp;
}
