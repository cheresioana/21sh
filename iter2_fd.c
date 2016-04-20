/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:58:02 by icheres           #+#    #+#             */
/*   Updated: 2016/04/20 10:28:12 by icheres          ###   ########.fr       */
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

void	redir_input(int red, t_nlist *list, t_run_data data)
{
	t_nnlist *begin;
	int			fd;
	t_sp 		s;
	pid_t		pid;

	begin = list->fd_in;
	while (list->fd_in)
	{
		if ((pid = fork()) == 0)
		{
			fd = open(list->fd_in->fd, O_RDONLY);
			dup2(fd, STDIN_FILENO);
			close(fd);
			dup2(red, 1);
			child(data.envp, data.paths, list->command);
		}
		else 
		{
			waitpid(pid, &s.status, WNOHANG);
			//close(red);
			list->fd_in = list->fd_in->next;
		}
	}
	list->fd_in = begin;
}	

void	redir_output(int red, t_nlist *list, t_run_data data)
{
	t_nnlist	*begin;
	int			fd;
	t_sp		s;
	pid_t		pid;

	begin = list->fd_out;
	printf("ana are mere\n");
	while (list->fd_out)
		if ((pid = fork()) == 0)
		{
			fd = open(list->fd_out->fd, O_CREAT | O_WRONLY, S_IRWXU);
			printf("ceplm %s\n%s\n", list->command, list->fd_out->fd);
			dup2(red, STDIN_FILENO);
			dup2(fd, STDOUT_FILENO);
			
			close(fd);
			printf("suuuugiii\n");
			child(data.envp, data.paths, list->command);
		}
		else
		{
			waitpid(pid, &s.status, WNOHANG);
			//close(red);
			//close(fd);
			list->fd_out = list->fd_out->next;
		}
	list->fd_out = begin;
}

void	iter_comm(t_nlist *list, char **envp, char **paths)
{
	int			fd[2];
	int			fp[2];
	int			in_fd;
	t_run_data	gdata;
	t_sp s;
	pid_t pid1;

	gdata.paths = paths;
	gdata.envp = envp;
	processing_list(list);
	//aff_meganlist(list);
	pipe(fd);
	while (list)
	{
		if (!is_special_pipe(list->command))
		{
			pipe(fp);
			pid1 = fork();
			if (pid1 == 0)
			{
					if (list->prev == NULL && list->next != NULL)
					{
						printf("primu***%s**\n", list->command);
						dup2(fd[1], STDOUT_FILENO);
					}
					else if (list->next == NULL && list->prev != NULL &&
							list->fd_out != NULL)
					{
					 	dup2(in_fd, STDIN_FILENO);
						printf("ultimu ***%s***\n", list->command);
					}	
					else if (list->next == NULL && list->prev == NULL)
					{
						if (list->fd_in != NULL)
							dup2(fp[0], STDIN_FILENO);
						if (list->fd_out != NULL)
							dup2(fp[1], STDOUT_FILENO);

					}
					else if (ft_strcmp(list->prev->command, "|") == 0)  
					{
						dup2(in_fd, STDIN_FILENO);
						dup2(fp[1], STDOUT_FILENO);
					}
					if (list->fd_in)
					{
						if (list->next == NULL && list->prev == NULL)
							redir_input(fp[1], list, gdata);	
						else redir_input((list->prev == NULL) ? (fd[1]) : (fp[1]),
								list, gdata);
					}
					if (list->fd_out)
					{
						if (list->next == NULL && list->prev == NULL)
							redir_output(fp[0], list, gdata);	
						if (list->prev == NULL)
							redir_output(fd[0], list, gdata);
						else {printf("intra cu in_fd\n");redir_output(fd[0], list, gdata);}
					}
					else child( envp, paths, list->command);
					exit(0);
			}
			else
			{
				close((list->prev == NULL) ? (fd[1]) : (fp[1]));
				in_fd = (list->prev == NULL) ? (fd[0]) : (fp[0]);	
				waitpid(pid1, &s.status, WNOHANG);
				
				//waitpid(pid1, &s.status, WSTOPSIG);
				list = list->next;
			}
		}
		else list = list->next;
	}
}
