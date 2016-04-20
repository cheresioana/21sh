/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:21:05 by icheres           #+#    #+#             */
/*   Updated: 2016/04/17 16:53:07 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	maybe_is_exec(t_run_data run)
{
	if (run.command[0] == '.' && run.command[1] == '/')
	{
		run.path = comp(get_info(run.envp, "PWD") + 4, run.command);
		run.argv[0] = run.path;
		execve(run.path, run.argv, run.envp);
	}
}

int		get_nr(char **argv)
{
	int		i = 0;
	while (argv[i])
		i++;
	//printf("%d\n", i);
	return (i);
}

void	child(char **env, char **paths, char *data)
{
	t_run_data		run;
	t_sp			s;

	s.i = 0;
	run.envp = env;
	run.argv = ft_split_whitespaces(data, ' ');
	//afis_paths(run.argv);
	run.argv[get_nr(run.argv)] = 0;
	run.command = run.argv[0];
	while (paths[s.i])
	{
		run.path = comp(paths[s.i], run.command);
		run.argv[0] = run.path;
		//dprintf(0, "%s\n", paths[s.i]);
		execve(run.path, run.argv, run.envp);
		//dprintf(0,"%s\n", paths[s.i]);
		s.i++;
	}
	maybe_is_exec(run);
	ft_putstr_s("zsh: command not found:", run.command);	
	exit(0);
}

int		compute(char *data, char **paths, char **env)
{
	t_slist		*list;

	list = get_list(data);	
	//aff(list);
	commands(list, env, paths);	
	return (1);
}
