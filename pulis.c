/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:54:31 by icheres           #+#    #+#             */
/*   Updated: 2016/04/16 12:05:21 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pulis(t_nlist *list, char **env, char **paths)
{
	int fd[2];
	int fp[2];
	int fk[2];
	t_sp s;
	pid_t pid1, pid2, pid3;
	int saved_stdout = dup(1);

	pipe(fd);
	pipe(fp);
	pipe(fk);
	if ((pid1 = fork()) == 0)
	{

		dup2(fd[1], STDOUT_FILENO);
		child(env, paths, list->command);
	}
	else {
		close(fd[1]);
		/*if ((pid2 = fork()) == 0)
		{
			close(fp[0]);
			dup2(fd[0], STDIN_FILENO);
			dup2(fp[1], STDOUT_FILENO);
			child(env, paths, list->next->next->command);
		}
		else{
			close(fp[1]);*/
			waitpid(pid1, &s.status, WNOHANG);
			if ((pid3 = fork()) == 0)
			{
				dup2(fd[0], STDIN_FILENO);
				child(env, paths, list->next->next->command);
			}
			else {
				waitpid(pid3, &s.status, WNOHANG);

				//waitpid(pid2, &s.status, WNOHANG);}
		}
	}
}
