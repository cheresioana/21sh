/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 18:48:56 by icheres           #+#    #+#             */
/*   Updated: 2016/04/20 19:19:57 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_special_pipe(char *shit)
{
	if (ft_strcmp(shit, "3>&1") != 0 && ft_strcmp(shit, "2>&1") != 0 &&
			ft_strcmp(shit, "1>&2") != 0 && ft_strcmp(shit, "3>&2") != 0 &&
			ft_strcmp(shit, ">") != 0 && ft_strcmp(shit, ">>") != 0 &&
			ft_strcmp(shit, "<") != 0 && ft_strcmp(shit, "<<") != 0 &&
			ft_strcmp(shit, "1>>") != 0 && ft_strcmp(shit, "2>") != 0 &&
			ft_strcmp(shit, "2>>") != 0 && ft_strcmp(shit, "1>") != 0 &&
			ft_strcmp(shit, "&>") != 0 && ft_strcmp(shit, "&>>") != 0 &&
			ft_strcmp(shit, "|") != 0)
		return (0);
	return (1);
}

void	redir_input(int fk, t_nlist *list, t_run_data data)
{
	t_nnlist *begin;
	int			fd;
	t_sp 		s;
	pid_t		pid;
	int			cp_input;
	int			cp_output;

	//cp_input = dup(0);
	//cp_output = dup(1);
	begin = list->fd_in;
	printf("command:%s\n", list->command);
	/*if (fk != -2)
			{
				printf("bareaza out-ul");
				dup2(fk, STDOUT_FILENO);
			}
	*/
	while (list->fd_in)
	{
		if ((pid = fork()) == 0)
		{
			fd = open(list->fd_in->fd, O_RDONLY);
			dup2(fd, STDIN_FILENO);
			close(fd);
			child(data.envp, data.paths, list->command);
			exit(0);
		}
		else
		{
			waitpid(pid, &s.status, 0);
			close(fd);
			list->fd_in = list->fd_in->next;
		}
	}
	//dup2(cp_input, 0);
	//dup2(cp_output, 1);
	printf("IESE DIN INPUT\n");
	list->fd_in = begin;
	//exit(0);
}

void	redir_output(int input, t_nlist *list, t_run_data data)
{
	t_nnlist	*begin;
	int			fd;
	t_sp		s;
	pid_t		pid;
	int			cp_input;
	int			cp_output;

//	cp_input = dup(0);
//	cp_output = dup(1);

	begin = list->fd_out;
	while (list->fd_out)
		if ((pid = fork()) == 0)
		{
			fd = open(list->fd_out->fd, O_CREAT | O_WRONLY, S_IRWXU);
			dup2(fd, STDOUT_FILENO);
			//close(fd);
			child(data.envp, data.paths, list->command);
		}
		else
		{
			waitpid(pid, &s.status, 0);
			close(fd);
			list->fd_out = list->fd_out->next;
		}
	list->fd_out = begin;
//	dup2(cp_input, 0);
//	dup2(cp_output, 1);

	printf("IESE DIN OUTPUT\n");
	//exit(0);
}

void		iter_comm(t_nlist *list, char **envp, char **paths)
{
	int		fd[2];
	int			cd[2];
	t_run_data	run;
	pid_t		pid, pid2;
	t_sp		s;
	int			in_fd;
	pid_t		*pp;
	int			i;
	int			j;

	i = -1;
	run.paths = paths;
	run.envp = envp;
	processing_list(list);
	//aff_meganlist(list);
	pp = (pid_t *)malloc(sizeof(pid_t) * list_count(list));
	while(list)
	{
		printf("yaaaa\n");
		if (is_special_pipe(list->command) == 0)
		{
			pipe(fd);
			i++;
			pid = fork();
			pp[i] = pid;
			if (pid == 0)
			{
				if (list->next != NULL)
				{
					printf("inchide iesirea pt:%s\n", list->command);
					dup2(fd[1], STDOUT_FILENO);
				}
				if (list->prev != NULL)
				{
					printf("inchide intratrea pentru %s\n", list->command);
					close(fd[0]);
					dup2(in_fd, STDIN_FILENO);
				}
				if (list->prev == NULL)
				{
					printf("cacatu de redirect\n");
					if (list->fd_out != NULL)
					{
						printf("redirect_output");
						dup2(fd[1], 1);
					}
					redir_input((list->next != NULL || list->fd_out != NULL ) ? (fd[1]) : (-2), list, run);
				}
				if (list->fd_out)
				{
					printf("output\n");
					redir_output(fd[0], list, run);
					if (list->next == NULL)
						exit(0);
				}
				if(list->fd_out == NULL && list->next == NULL && list->fd_in == NULL)
				{
					printf("HALOOOOO**%s**\n", list->command);
					child(envp, paths, list->command);
				}
				else if (list->prev != NULL && list->fd_in != NULL)
				{
					if (list->fd_in != NULL)
					{
						pid2 = fork();
						if (pid2 == 0)
						{
							printf("111\n");
							child(envp, paths, list->command);
						}
						else {
							waitpid(pid2, &s.status, 0);
							printf("22\n");
							redir_input(-1, list, run);
							exit(0);
						}
						//kill(pid2, 0);
					}
					else child(envp, paths, list->command);
				}
				else
				{
					printf("AJUNGE LANGA EXIT\n");
					exit(0);
				}
			}
			else
			{
				close(fd[1]);
				in_fd = fd[0];
				printf("PARENT");
				if (i > 1)
					for (j = 0; j < i - 1; j++)
						waitpid(pp[j], &s.status, 0);
				waitpid(pid, &s.status, WNOWAIT);
				list = list->next;
			}
		}
		else
			list = list->next;
	}
	for (j = 0; j<= i; j++)
		waitpid(pp[j], &s.status, 0);
	printf("IESE DIN COMMENZI");
}
