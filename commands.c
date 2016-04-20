/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_handeling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:39:46 by icheres           #+#    #+#             */
/*   Updated: 2016/04/19 14:04:25 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cplm(t_nlist *l)
{
	if (l == NULL)
		printf("???\n");
	printf("%s\n", l->command);
	if (l->next == NULL)
		printf("%s\n", l->command);
}

void	commands(t_slist *list, char **envp, char **paths)
{
//	printf("intra?\n");
//	afis_paths(paths);
	while (list != NULL)
	{
	//	cplm(list->data_list);
		if (list->data_list)
			//pulis(list->data_list, envp, paths);
			//rec(list->data_list, 0, envp, paths);
			iter_comm(list->data_list, envp, paths);
		list = list->next;
	}
}
